#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - Compare two string
 * @s1: first string to compare
 * @s2: second string, can contain * character
 * Return: 1 if true, otherwise 0
 *
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || (*s1 && wildcmp(s1 + 1, s2)));
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
