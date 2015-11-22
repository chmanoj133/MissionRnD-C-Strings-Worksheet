/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len)
{
	int i, j, temp, k, action = 0;
	i = 0;
	j = len - 1;

	while (i < j) 
	{
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}

	i = 0;
	for (k = 0; k < len; k++)
	{
		if (input[k] == ' ' || k == len - 1)
		{
			if (k == len - 1)
				j = k;
			else
				j = k - 1;
			action = 1;
		}
		if (action == 1)
		{
			while (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
				i++;
				j--;
			}
			action = 0;
			for (i = k; input[i] == ' '; i++);
			k = i;
		}
	}

}

