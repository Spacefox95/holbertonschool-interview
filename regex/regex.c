#include "regex.h"
#include <stdio.h>

/**
 * regex_match - Checks if a string matches the pattern
 * @str: the string to check
 * @pattern: the regex pattern to match
 * Return: 1 if match, 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{
	if (!pattern || !str)
		return (0);

	if (*pattern == '\0')
		return (*str == '\0');

	int first_match = (*str != '\0' &&
										 (*str == *pattern || *pattern == '.'));

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
						(first_match && regex_match(str + 1, pattern)));
	}
	else
	{
		return (first_match && regex_match(str + 1, pattern + 1));
	}
}
