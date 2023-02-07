# 0x08-palindrome_integer

This repository contains the solution to the 0x08-palindrome_integer project of the Holberton School interview pre-examination process.

## Function is_palindrome
The function `is_palindrome` takes an unsigned integer `n` as argument and returns 1 if the number is a palindrome and 0 otherwise. The function must not allocate memory dynamically (malloc, calloc, etc.).

## Usage
A test file `0-main.c` is provided to test the function. To use it, compile it with `0-is_palindrome.c` and run the binary with an unsigned integer argument. The output will be whether the argument is a palindrome or not.

```$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
$ ./palindrome 121
121 is a palindrome.
$ ./palindrome 112
112 is not a palindrome.```