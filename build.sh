#!/bin/bash
set -e
mkdir -p build
cd build
cmake ..
make -j
echo "Build complete. Run './run.sh' to execute."