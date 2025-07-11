#!/bin/bash

# Define EXACT required versions
REQUIRED_SDL_VERSION="3.1.7"
REQUIRED_IMAGE_VERSION="3.1.0"
REQUIRED_MIXER_VERSION="3.0.0"

comp_time() {
    local start=$(date +%s%3N)
    "$@"
    local exit_code=$?
    local finish=$(date +%s%3N)
    echo
    echo >&2 "Took ~$(( finish - start )) ms."
    return ${exit_code}
}

echo

DEBUG=false
CLEAN=false
HELP=false
OPTIMIZE=false
IGNORE=true

while [[ $# -gt 0 ]]; do
    case "$1" in
        -d|--debug)
            DEBUG=true
            shift ;;
        -c|--clean)
            CLEAN=true
            shift ;;
        -O|--optimize)
            OPTIMIZE=true
            shift;;
        -i|--ignore-errors)
            IGNORE=false
            shift ;;
        -h|--help)
            HELP=true
            shift;;
        *)
            echo "Unknown option: $1"
            exit 1 ;;
    esac
done

if $HELP; then
    echo "Script to compile this project with gcc. All available flags:
    -d / --debug            ->  adds -g to gcc flags
    -c / --clean            ->  cleans /bin directory
    -O / --optimize         ->  adds optimization flags such as -O3, -march, ...
    -i / --ignore-errors    ->  ignores errors during compile
    "
    exit 0
fi

# Set file locations
BIN_FILES_LOCATION="bin"

# Recursively collect all .c files from src/
SRC_FILES=()
while IFS= read -r -d $'\0'; do
    SRC_FILES+=("$REPLY")
done < <(find src -type f -name "*.c" -print0)

if [ ${#SRC_FILES[@]} -eq 0 ]; then
    echo "Error: No source files found in src/ directory!"
    exit 1
fi

# Set compiling flags for gcc
FLAGS=(-fopenmp -lm)
FLAGS+=(-Wall -Wextra)

export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:$PKG_CONFIG_PATH

# Verify SDL versions
check_sdl_version() {
    local lib=$1
    local required_version=$2
    
    if ! pkg-config --exists $lib; then
        echo >&2 "Error: $lib is not installed"
        exit 1
    fi
    
    local installed_version=$(pkg-config --modversion $lib)
    if [ "$installed_version" != "$required_version" ]; then
        echo >&2 "Error: Wrong $lib version. Required: $required_version, Found: $installed_version"
        exit 1
    fi
}

# Check specific library versions
check_sdl_version sdl3 $REQUIRED_SDL_VERSION
check_sdl_version sdl3-image $REQUIRED_IMAGE_VERSION
check_sdl_version sdl3-mixer $REQUIRED_MIXER_VERSION

# Get SDL flags
SDL_FLAGS=($(pkg-config sdl3 sdl3-image sdl3-mixer --cflags --libs))
FLAGS+=("${SDL_FLAGS[@]}")

if $IGNORE; then
    FLAGS+=(-Werror)
fi

OUTPUT_BINARY="game"

if $DEBUG; then
    FLAGS+=(-g)
    echo "Debug enabled."
    echo
    echo "Source files to compile:"
    printf '  %s\n' "${SRC_FILES[@]}"
    echo
fi

mkdir -p "$BIN_FILES_LOCATION"

if $CLEAN; then
    echo "Cleaning build directory"
    echo
    rm -rf "$BIN_FILES_LOCATION"/*
fi

if $OPTIMIZE; then
    FLAGS+=(-O3 -march=native -mtune=native -flto -fomit-frame-pointer)
    echo "Added special flags for better optimization"
    echo
fi

echo "Compiling program with flags: ${FLAGS[@]} "
echo 

comp_time gcc "${SRC_FILES[@]}" -o "$BIN_FILES_LOCATION/$OUTPUT_BINARY" "${FLAGS[@]}"

echo

if [ $? -eq 0 ]; then
    echo "Compilation successful."
else
    echo "Compilation failed."
    exit 1
fi
