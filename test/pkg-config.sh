#!/bin/sh
set -eu

cd "$(dirname "$0")/.."
work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT HUP INT TERM
mkdir "$work/source"
cp -R src bindings CMakeLists.txt Makefile "$work/source/"
version=$(node -p 'require("./package.json").version')

for build in make cmake; do
	prefix="$work/$build-install"
	libdir="$prefix/custom-lib"
	includedir="$prefix/custom-include"
	if [ "$build" = make ]; then
		make -C "$work/source" install PREFIX="$prefix" LIBDIR="$libdir" INCLUDEDIR="$includedir"
	else
		cmake -S "$work/source" -B "$work/cmake-build" \
			-DCMAKE_INSTALL_PREFIX="$prefix" -DCMAKE_INSTALL_LIBDIR="$libdir" \
			-DCMAKE_INSTALL_INCLUDEDIR="$includedir"
		cmake --build "$work/cmake-build"
		cmake --install "$work/cmake-build"
	fi

	export PKG_CONFIG_PATH="$libdir/pkgconfig"
	pkg-config --validate tree-sitter-haml
	test "$(pkg-config --modversion tree-sitter-haml)" = "$version"
	test "$(pkg-config --variable=prefix tree-sitter-haml)" = "$prefix"
	test "$(pkg-config --variable=libdir tree-sitter-haml)" = "$libdir"
	test "$(pkg-config --variable=includedir tree-sitter-haml)" = "$includedir"
	# Intentional word splitting: pkg-config returns compiler arguments.
	cc $(pkg-config --cflags tree-sitter-haml) -x c - -o "$work/consumer" \
		$(pkg-config --libs tree-sitter-haml) <<'C'
#include <tree_sitter/tree-sitter-haml.h>
int main(void) { return tree_sitter_haml() == 0; }
C
	LD_LIBRARY_PATH="$libdir" DYLD_LIBRARY_PATH="$libdir" "$work/consumer"
done
