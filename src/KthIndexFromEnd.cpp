/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include <stdio.h>

int string_length_of(char *x);

char KthIndexFromEnd(char *str, int K)
{
	int index;

	if (str == '\0' || str == NULL)
		return '\0';
	else
	{
		index = string_length_of(str) - 1;
		if (K < 0 || K > index)
			return '\0';
		else
			return str[index - K];
	}
}

int string_length_of(char *x)
{
	int len;
	for (len = 0; x[len] != '\0'; len++);
	return len;
}