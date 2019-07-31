# Hashing-Hard Version

## Brief introduction

This program gets the current hash table and rebuilds the insertion sequence. The whole file contains C code file and report.

## Development Environment

IDE: Dev C++ 5.11
Complier Configuration:TDM-GCC 4.9.2 64-bit Release

## Running Instruction

Project only contain one source file. Use gcc or g++ complier to compile the source file, or directly use feasible IDE such as Dev C++, Visual Studio to compile it before you evaluate the result. Then open the generated executable file to run it.

## Input Instruction

This program gets the input on the following format (in order):

1. A positive integer N(<=1000), which is the size of hash table.
2. N integers, separated by a space. A negative integer represents an empty cell. All the non-negative integers must be distinct.

Please follow the rules strictly and make sure that solution is existed, otherwise the program will print the error message and exit directly.

## Output

The rebuilt insertion sequence in one line. All the elements are separated by a space, and there is no extra space at the end of the line.
You can see the result in input window directly.
**********************************************************************************************************************************************
There is an another program  "random_generator.c" which is used to generate random values for testing the max-size hash table.