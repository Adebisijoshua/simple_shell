#include "tokens.h"

/**
 * arrdup - duplicate a (NULL-terminated) array
 * @arr: the array to duplicate
 *
 * Return: a duplicate of arr
 */
char **arrdup(char **arr)
{
	char **dup = NULL;/* Pointer to the duplicate array */
	size_t len = 0;/* Counter for the length of the input array */

	/* Check if the input array is NULL */
	if (!arr)
		return (NULL);
	/* Calculate the length of the input array */
	while (arr[len++])
		;
	/* Allocate memory for the duplicate array */
	dup = malloc(sizeof(*dup) * len);
	if (!dup)
		return (NULL);
	/* Copy each element from the input array to the duplicate array */
	while (len--)
		dup[len] = _strdup(arr[len]);
	return (dup); /* Return the duplicate array */
}


