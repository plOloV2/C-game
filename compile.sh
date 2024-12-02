#!/bin/bash

comp_time() {
    local start=${EPOCHREALTIME/./}
    "$@"
    local exit_code=$?
    echo >&2 "Took ~$(( (${EPOCHREALTIME/./} - start)/1000 )) ms."
    return ${exit_code}
}

# Set file locations
SOURCE_FILES_LOCATION="src"
INCLUDE_LOCATION="include"
BIN_FILES_LOCATION="bin"

# Set compiling flags for gcc
FLAGS=()

export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH
SDL_FLAGS=$(pkg-config sdl3 sdl3-image sdl3-mixer --cflags --libs)
if [ $? -ne 0 ]; then
    echo "Error: Failed to retrieve SDL3 flags using pkg-config. Is SDL3 installed?"
    exit 1
fi
FLAGS+=($SDL_FLAGS)

# Set the source file and output binary names
SOURCE_FILE="game.c"
OUTPUT_BINARY_LINUX="game"
OUTPUT_BINARY_WINDOWS="game.exe"

# Check if source file is present
if [ ! -f "$SOURCE_FILES_LOCATION/$SOURCE_FILE" ]; then
    echo "Error: Source file '$SOURCE_FILE' not found!"
    exit 1
fi

echo "Souce file present"


DEBUG=false
CLEAN=false
WINDOWS=false
while [[ $# -gt 0 ]]; do
    case "$1" in
        -d|--debug)
            DEBUG=true
            shift ;;
        -c|--clean)
            CLEAN=true
            shift ;;
        -w|--windows)
            WINDOWS=true
            shift ;;
        *)
            echo "Unknown option: $1"
            exit 1 ;;
    esac
done

if $DEBUG; then
    FLAGS+=(-g)
    echo "Debug enabled."
fi

mkdir -p "$BIN_FILES_LOCATION"

if $CLEAN; then
    echo "Cleaning directory build directory"
    rm -rf "$BIN_FILES_LOCATION"/*
fi

if $WINDOWS; then
    echo "Compiling program for windows with flags: ${FLAGS[@]}"
    # comp_time gcc "$SOURCE_FILES_LOCATION/$SOURCE_FILE" -o "$BIN_FILES_LOCATION/$OUTPUT_BINARY_WINDOWS" "${FLAGS[@]}"

else
    echo "Compiling program for linux with flags: ${FLAGS[@]}"
    comp_time gcc "$SOURCE_FILES_LOCATION/$SOURCE_FILE" -o "$BIN_FILES_LOCATION/$OUTPUT_BINARY_LINUX" "${FLAGS[@]}"
fi

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Output binary is $OUTPUT_BINARY"
else
    echo "Compilation failed."
    exit 1
fi
