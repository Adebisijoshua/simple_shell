#include "tokens.h"

/**
 * arrjoin - two arrays will be joined
 * @arr1: array 1
 * @arr2: array 2
 *
 * Return: moving alloc array  from arrayy 1 and arr 2
 */
char **arrjoin(char **arr1, char **arr2)
{
	/* Pointer to the new dynamically-allocated array */
	char **new;
	/* Variables to store the length of arr1, arr2, and the new array */
	size_t arr1_len = 0, arr2_len = 0, new_len;

	/* Calculate the length of arr1 if it is not NULL */
	if (arr1)
	{
		while (arr1[arr1_len])
			++arr1_len;
	}
	/* Calculate the length of arr2 if it is not NULL */
    if (arr2)
	if (arr2)
	{
		while (arr2[arr2_len])
			++arr2_len;
	}
    /* Allocate memory for the new array */
	new = malloc(sizeof(char *) * (arr1_len + arr2_len + 1));
	/* Check if memory allocation was successful */
	if (!new)
		return (NULL);
	/* Initialize new_len to 0 */
	new_len = 0;
	/* Copy elements from arr1 to the new array */
	if (arr1)
	{
		while (*arr1)
			new[new_len++] = _strdup(*arr1++);
	}
	/* Copy elements from arr2 to the new array */
	if (arr2)
	{
		while (*arr2)
			new[new_len++] = _strdup(*arr2++);
	}
	/* Set the last element of the new array to NULL */
	new[new_len] = NULL;
	/* Return the new array */
	return (new);
}
