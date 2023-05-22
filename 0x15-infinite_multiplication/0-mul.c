#include <stdio.h>
#include <stdlib.h>


/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: The number to be checked
 * Return: 1 if c is a digit, 0 otherwise
*/
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * print_error - prints Error and exit 98
 * Return: void
*/
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * check_digits - checks if a string contains only digits
 * @s: The string to be checked
 * Return: void
*/
void check_digits(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (!_isdigit(s[i]))
			print_error();
	}
}

/**
 * multiply - multiplies two positive numbers
 * @num1: The first number to be multiplied
 * @num2: The second number to be multiplied
 * Return: void
*/
void multiply(char *num1, char *num2)
{
	int i, j, len1, len2, carry, n1, n2, sum;
	int *result;

	len1 = 0;
	while (num1[len1] != '\0')
		len1++;
	len2 = 0;
	while (num2[len2] != '\0')
		len2++;
	result = malloc((len1 + len2) * sizeof(int));
	if (result == NULL)
		print_error();

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}

		if (carry > 0)
			result[i + j + 1] += carry;
	}
	i = 0;
	while (result[i] == 0 && i < len1 + len2 - 1)
		i++;

	for (; i < len1 + len2; i++)
		printf("%d", result[i]);
	printf("\n");
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0 if success, 1 otherwise
*/
int main(int argc, char **argv)
{
	if (argc != 3)
		print_error();

	for (int i = 1; i < argc; i++)
	{
		int j = 0;

		while (argv[i][j] != '\0')
		{
			if (!_isdigit(argv[i][j]))
				print_error();
			j++;
		}
	}

	multiply(argv[1], argv[2]);

	return (0);
}
