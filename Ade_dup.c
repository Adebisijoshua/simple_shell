#include "tokens.h"

/**
 * arrdup - double a (NULL-terminated) array
 * @arr: the array t be duplicated
 *
 * Return: a duplicate of arr
 */
char **arrdup(char **arr)
{
	/* Pointer to the duplicate array */
	char **duplicate = NULL;
	/* Variable to store the length of the array */
	size_t len = 0;

	/* Check if the input array is NULL */
	if (!arr)
		return (NULL);
	/* Calculate the length of the input array */
	while (arr[len++])
		;
	/* Allocate memory for the duplicate array */
	duplicate = malloc(sizeof(*duplicate) * len);
	/* Check if memory allocation was successful */
	if (!duplicate)
		return (NULL);
	/* Copy each string from the original array to the duplicate array */
	while (len--)
		duplicate[len] = _strdup(arr[len]);
	/* Return the duplicate array */
	return (duplicate);
}
