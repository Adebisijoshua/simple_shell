#include "ctype.h"

/**
  * _isalnum -looks if the character is alphanumeric
  * @c: check character
 * Return: If it is a  alphanumeric, return 1. Otherwise, return 0.
  */
bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
