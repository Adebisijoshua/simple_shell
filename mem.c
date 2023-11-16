#include "string.h"

/**
 * _memchr - get the index of the first matching value
 * @src: start of the memory area to search
 * @chr: value to find
 * @n: size of the search area
 * Return: If chr does not occur in the first n elements of src, return -1.
 * Otherwise, return the index of the first occurence of chr.
 */
ssize_t _memchr(const void *src, unsigned char chr, size_t n)
{
	const unsigned char *mem = src;
	ssize_t i = 0;

	if (src)
	{
		while (n--)
		{
			if (mem[i] == chr)
				return (i);/* Return the index of the first occurrence of chr */
			i += 1;
		}
	}
	return (-1);/* Return -1 if chr does not occur in the first n elements of src */
}

/**
 * _memcpy - copy a memory area
 * @dest: a pointer to the start of the target area
 * @src: a pointer to the start of the source area
 * @n: the number of bytes to copy
 *
 * Description: This function copies n bytes from the memory area at src
 * to the memory area at dest. These memory areas must not overlap.
 *
 * Return: a pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *w_pos = dest;
	const unsigned char *r_pos = src;

	if (dest && src)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dest);
}

/**
 * _memdup - double a memory area
 * @src: address to the start of the source area
 * @n: number of bytes to duplicate
 * Return: assumeallocation fails, return NULL. Otherwise, return b
 * pointer of the start of the duplicated memory.
 */
void *_memdup(const void *src, size_t n)
{
	/* declare variables */
	void *dup = malloc(n);
	const unsigned char *r_pos = src;
	unsigned char *w_pos = dup;

	if (dup)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dup);
}

/**
 * _memset - close a region of memory with a given value
 * @dest: address to beginning of the region
 * @chr: value to write to the region
 * @n: number of bytes to write
 * Return: dest
 */
void *_memset(void *dest, unsigned char chr, size_t n)
{
	unsigned char *mem = dest;

	if (dest)
	{
		while (n--)
			*mem++ = chr;/* Fill the region with chr for n bytes */
	}
	return (dest);
}
