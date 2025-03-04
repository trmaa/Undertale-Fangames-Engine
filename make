#!/bin/bash

error() {
	msg="$1"
	echo -e "\e[31m$msg\e[0m"
}

EXPORT="./build/alicia_roguelike.app"
SRC="./src/"
INCLUDE="./include/"
LIB="./lib/"
FLAGS="-lsfml-graphics -lsfml-window -lsfml-system -ltbb"

run() {
	if [ ! -f "$EXPORT" ]; then
		error "Error: $EXPORT not found."
		return
	fi
	$EXPORT
}

clean() {
	rm ./**.o
	if [ ! -f "$EXPORT" ]; then
		return
	fi
	rm $EXPORT
}

build() {
	g++ -c $SRC/**.cpp -I$INCLUDE
	g++ ./**.o -o $EXPORT -L$LIB $FLAGS
	rm ./**.o
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
