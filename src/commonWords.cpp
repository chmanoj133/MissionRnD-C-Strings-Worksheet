/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int string_len(char *x);

char ** commonWords(char *str1, char *str2) 
{
	int i, j, k = 0, action = 1, len1, len2, *index1 = (int*)malloc(sizeof(int) * 2), *index2 = (int*)malloc(sizeof(int) * 2);
	char **str = (char**)calloc(1, sizeof(char*));
	int diff1, diff2, sub_action = 1, flag = 1, count = 0;

	if (str1 == NULL || str2 == NULL)
		return NULL;
	else
	{
		len1 = string_len(str1);
		len2 = string_len(str2);
		

		for (i = 0; str1[i] == ' '; i++);
		index1[0] = i;
		for (j = 0; str2[j] == ' '; j++);
		index2[0] = j;
		while (action == 1)
		{
			for (i = index1[0]; str1[i] != ' ' && i < len1; i++);
			index1[1] = i - 1;
			if (index1[1] < 0)
				index1[1] = 0;
			diff1 = index1[1] - index1[0] + 1;

			index2[0] = 0;
			sub_action = 1;
			while (sub_action == 1)
			{
				for (j = index2[0]; str2[j] != ' ' && j < len2; j++);
				index2[1] = j - 1;
				if (index2[1] < 0)
					index2[1] = 0;
				diff2 = index2[1] - index2[0] + 1;

				if (diff1 == diff2)
				{
					for (i = index1[0], j = index2[0]; i < index1[0] + diff1; i++, j++)
					{
						if (str1[i] != str2[j])
						{
							flag = 0;
							break;
						}
						else
							flag = 1;
					}
					if (flag == 1)
					{
						str = (char**)realloc(str, (count + 1)*sizeof(char*));
						str[count] = (char *)calloc(SIZE, sizeof(char));
						for (i = 0, j = index2[0]; j < index2[0] + diff2; i++, j++)
							str[count][i] = str2[j];
						count++;
					}
				}

				if (index2[1] == len2 - 1)
					sub_action = 0;
				else
				{
					for (j = index2[1] + 1; str2[j] == ' '; j++);
					index2[0] = j;
				}
			}

			if (index1[1] == len1 - 1)
				action = 0;
			else
			{
				for (i = index1[1] + 1; str1[i] == ' '; i++);
				index1[0] = i;
			}

		}
		if (count != 0)
			return str;
		else
			return NULL;
	}
}

int string_len(char *x)
{
	int len;
	for (len = 0; x[len] != '\0'; len++);
	return len;
}