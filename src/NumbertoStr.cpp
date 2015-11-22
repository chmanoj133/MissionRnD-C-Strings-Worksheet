/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <malloc.h>

void number_to_str(float number, char *str,int afterdecimal)
{
	int i, index = 0, part_int, remainder, int_count = 0, j = 0;
	float part_flt;
	char *part1 = (char*)malloc(10 * sizeof(char));

	

	if (number < 0)
	{
		str[index] = '-';
		index++;
		part_int = -number;
		part_flt = -number - part_int;
	}
	else
	{
		part_int = number;
		part_flt = number - part_int;
	}


	for (i = 0; part_int != 0; i++)
	{
		remainder = part_int % 10;
		part_int = part_int / 10;
		part1[i] = remainder + '0';
		int_count++;
	}
	part1[i] = '\0';

	for (i = int_count - 1 + index; i >= index; i--)
	{
		str[i] = part1[j];
		j++;
	}
	index = j + index;

	if (part_flt == 0.0000)
		str[index] = '\0';
	else
	{
		str[index] = '.';
		index++;
		for (i = 0; i < afterdecimal; i++)
		{
			part_int = part_flt * 10;
			str[index] = part_int + '0';
			part_flt = (part_flt * 10) - part_int;
			index++;
		}
		str[index] = '\0';
	}
}
