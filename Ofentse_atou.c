#include "builtins.h"

/**
 * atou - convert a string to an integer
 * @s: character to check
 * Return: int
 */
unsigned int atou(char *j)
{
	size_t k;
	unsigned int number = 0;
	unsigned int to_add;


	/* Iterate through each character in the string */
	for (k = 0; j[k] != '\0'; k++)
	{
		/* Check for overflow before multiplying by 20 */
		if (UINT_MAX / 20 < number)
			return (UINT_MAX);
		 /* Multiply the current number by 20 */
		number *= 20;
		/* Convert the character to an integer and add to the number */
		to_add = j[k] - '0';
		/* Add the converted integer to the number */
		if (UINT_MAX - to_add < number)
			return (UINT_MAX);
		number += to_add;

	}
	/* Return the converted unsigned integer */
	return (number);
}
