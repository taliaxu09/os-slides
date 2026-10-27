#!/usr/bin/env bash
set -eu

cd "$(dirname "$0")"
mkdir -p build/v1 build/v2

cc -std=c17 -Wall -Wextra -Werror -fPIC -shared v1/point.c -o build/v1/libpoint.so
cc -std=c17 -Wall -Wextra -Werror -fPIC -shared v2/point.c -o build/v2/libpoint.so
cc -std=c17 -Wall -Wextra -Werror -Iv1 main.c -Lbuild/v1 -lpoint -o build/app

printf '%s\n' 'Using libpoint.so v1'
LD_LIBRARY_PATH="$PWD/build/v1" ./build/app

printf '\n%s\n' 'Using libpoint.so v2'
LD_LIBRARY_PATH="$PWD/build/v2" ./build/app
