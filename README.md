# transform

transform is a C project that converts decimals and hexadecimals to their ascii values
and prints them to the standard output

## Getting Started


### Prerequisites
- make
- gcc

## Installing

1. Download this source code
2. Inside of the transform folder, run make
```
make
```
3. Run the program:
```
./transform
```
### Usage
1. When executed with no arguments, this program will wait for the user to type into the standard input
2. This program can be run with the following syntax to read in input from files:
```
./transform < filename.txt
```
### Documented Bugs
1. When a string only contains letters that could be hex, this source code classifies these letters as hex, but does not print them
if they do not produce a valid ASCII character (e.g., the string abc)

## Authors

* Kelsey Cole 

