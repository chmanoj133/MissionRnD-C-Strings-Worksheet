/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <stdio.h>

int string_length(char *x);

char removeSpaces(char *str) 
{
	int i = 0, j, temp_length;

	
	if (str == NULL || str == '\0')
		return '\0';
	else
	{
		temp_length = string_length(str);
		while (i < temp_length)
		{
			if (str[i] == ' ')
			{
				for (j = i; j < temp_length - 1; j++)
					str[j] = str[j + 1];
				str[j] = '\0';
				temp_length--;
			}
			if (str[i] != ' ')
				i++;
		}
		return '\0';
	}
}

int string_length(char *x)
{
	int len;
	for (len = 0; x[len] != '\0'; len++);
	return len;
}