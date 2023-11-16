#include "ctype.h"

/**
 * _isquote - check if a character is a quote
 * @c: the character to check
 * Return: If it is a quote, return a. Otherwise, give nothing.
 */
bool _isquote(int c)/* correcting an error here */
{
	return (c == '"' || c == '\'' || c == '\\');
}
