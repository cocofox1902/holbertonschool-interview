#include "slide_line.h"

/**
 * slide_left - slides and merges an array of integers to the left
 * @line: points to an array of integers
 * @size: number of elements in array
 * Return: 1 upon success, or 0 upon failure
 */
int slide_left(int *line, size_t size)
{
	int i, j;

	for (i = 0; i < (int)size; i++)
	{
		for (j = i + 1; j < (int)size; j++)
		{
			if (line[j] != 0)
			{
				if (line[i] == 0)
				{
					line[i] = line[j];
					line[j] = 0;
					i--;
				}
				else if (line[i] == line[j])
				{
					line[i] += line[j];
					line[j] = 0;
				}
				break;
			}
		}
	}
}

/**
 * slide_right - slides and merges an array of integers to the right
 * @line: points to an array of integers
 * @size: number of elements in array
 * Return: 1 upon success, or 0 upon failure
 */
int slide_right(int *line, size_t size)
{
	int i, j;

	for (i = (int)size - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (line[j] != 0)
			{
				if (line[i] == 0)
				{
					line[i] = line[j];
					line[j] = 0;
					i++;
				}
				else if (line[i] == line[j])
				{
					line[i] += line[j];
					line[j] = 0;
				}
				break;
			}
		}
	}
	return (1);
}

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: number of elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
	{
		return (0);
	}
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
	}
	else if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	}
	return (1);
}
