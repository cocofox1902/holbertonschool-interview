#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome.
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n) {
    unsigned long rev = 0, last, n_index = n;

    while (n != 0) {
        last = n % 10;
        rev = rev * 10 + last;
        n /= 10;
    }

    if (n_index == rev) {
        return (1);
    } else {
        return (0);
    }
}