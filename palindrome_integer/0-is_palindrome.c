#include "palindrome.h"

int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, original = n, remainder;

	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	return (original == reversed);
}
