#!/bin/bash

error() {
    msg="$1"
    echo -e "\e[31m$msg\e[0m"
}

EXPORT="build/alicia_roguelike.app"
SRC="src"
INCLUDE="include"
LIB="lib"
FLAGS="-lsfml-graphics -lsfml-window -lsfml-system -ltbb"

run() {
    if [ ! -f "$EXPORT" ]; then
        error "Error: $EXPORT not found."
        return
    fi
    $EXPORT
}

clean() {
    rm -f ./*.o
    rm -f "$EXPORT"
}

build() {
    mkdir -p build
    cpp_files=$(find "$SRC" -type f -name "*.cpp")

    if [ -z "$cpp_files" ]; then
        error "Error: No .cpp files found in $SRC"
        return
    fi

    g++ -c $cpp_files -I"$INCLUDE"
    g++ ./*.o -o "$EXPORT" -L"$LIB" $FLAGS
    rm -f ./*.o
}

main() {
    for callback in "$@"; do
        if declare -f "$callback" > /dev/null; then
            "$callback"
        else
            error "Error: Function '$callback' not found."
        fi
    done
}

main "$@"
