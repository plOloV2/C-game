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
FLAGS=(src/input/input.c)

export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH
SDL_FLAGS=$(pkg-config sdl3 sdl3-image sdl3-mixer --cflags --libs)
if [ $? -ne 0 ]; then
    echo "Error: Failed to retrieve SDL3 flags using pkg-config. Is SDL3 installed?"
    exit 1
fi
FLAGS+=($SDL_FLAGS)

# Set the source file and output binary names
SOURCE_FILE="game.c"
OUTPUT_BINARY_NAME="game"

# Check if source file is present
if [ ! -f "$SOURCE_FILES_LOCATION/$SOURCE_FILE" ]; then
    echo "Error: Source file '$SOURCE_FILE' not found!"
    exit 1
fi

echo "Souce file present"

DEBUG=false
CLEAN=false
OPTI=false
HELP=false
while [[ $# -gt 0 ]]; do
    case "$1" in
        -d|--debug)
            DEBUG=true
            shift ;;
        -c|--clean)
            CLEAN=true
            shift ;;
        -O|--optimalize)
            OPTI=true
            shift ;;
        -h|--help)
            HELP=true
            shift ;;
        *)
            echo "Unknown option: $1. Use -h / --help to see all avaible options."
            exit 1 ;;
    esac
done

if $HELP; then
    echo "Script to compile this project with gcc. All available flags:
    -d / --debug    ->  adds -g to gcc flags
    -c / --clean    ->  cleans /bin directory
    -O / --optimize ->  adds optimalization flags such as -O3, -march, ... 
    "
    exit 0
fi

if $DEBUG; then
    FLAGS+=(-g)
    echo "Debug enabled."
fi

if $OPTI; then
    FLAGS+=(-O3 -march=native -mtune=native -flto -fomit-frame-pointer)
    echo "Added optimalization."
fi

mkdir -p "$BIN_FILES_LOCATION"

if $CLEAN; then
    echo "Cleaning directory build directory"
    rm -rf "$BIN_FILES_LOCATION"/*
fi

echo "Compiling program with flags: ${FLAGS[@]}"
comp_time gcc "$SOURCE_FILES_LOCATION/$SOURCE_FILE" -o "$BIN_FILES_LOCATION/$OUTPUT_BINARY_NAME" "${FLAGS[@]}"


# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."
else
    echo "Compilation failed."
    exit 1
fi
