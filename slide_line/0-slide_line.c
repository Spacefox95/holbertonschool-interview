#include "slide_line.h"

/**
 * slide_line - the main function to slide and merge integers
 * @line: an array of integers
 * @size: the size of the array line
 * @direction: the direction the array should be merge
 * Return: 1 if success, 0 if failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (size == 0)
		return (0);

	if (direction == SLIDE_RIGHT)
		reverse_array(line, size);

	slide(line, size);
	merge(line, size);
	slide(line, size);

	if (direction == SLIDE_RIGHT)
		reverse_array(line, size);
	return (1);
}

/**
 * slide - slide on the array and put all the 0 at the end of the array
 * @line: the array to slide
 * @size: the size of the array
 */

void slide(int *line, size_t size)
{
	size_t i;
	size_t index = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[index++] = line[i];
		}
	}

	while (index < size)
	{
		line[index++] = 0;
	}
}

/**
 * merge - merge the equals elements of the array
 * @line: the array to merge
 * @size: the size of the array
 */

void merge(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] += line[i + 1];
			line[i + 1] = 0;
			i++;
		}
	}
}

/**
 * reverse_array - if the direction of the array is right, reverse the array
 * @line: the array to reverse
 * @size: the size of the array
 */

void reverse_array(int *line, size_t size)
{
	size_t i;
	int temp;

	for (i = 0; i < size / 2; i++)
	{
		temp = line[i];
		line[i] = line[size - 1 - i];
		line[size - 1 - i] = temp;
	}
}
