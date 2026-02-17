# mkpr
mkpr - a simple tool to initialize projects for different languages

## Supported languages:
  C, C++, Python

## How to build:
Since theres no precompiled binaries, you have to compile it yourself.
To compile it do make in the root folder of mkpr 
OR
g++ -std=c++17 src/main.cpp -o mkpr in the root folder of mkpr

## Usage:
mkpr "project_name" -lang "language"

## TODO:
Add --build support(mkpr foobar -lang C --build CMake 
