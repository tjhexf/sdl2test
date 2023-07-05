#!/usr/bin/sh

git submodule init &&
git submodule update &&

mkdir build &&
cd build &&

cmake -DCMAKE_BUILD_TYPE=RELEASE .. &&

make -j$(nproc) &&

echo "Succesfully built into folder: build/"
