#ifndef _CTYPE_H_
#define _CTYPE_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Check if the given character is letter
 *
 * @param c The character to check.
 * @return true if the character is alphanumeric, false other
bool _isalpha(int c);
*/

bool _isalpha(int c);

/**
 * @brief Check if the given character is number
 *
 * @param c The character to check.
 * @return true if the character is alphabetic, false otherwise.
 */
bool _isalnum(int c);


/**
 * @brief Check if the given character is a digit.
 *
 * @param c The character to check.
 * @return true if the character is a digit, false otherwise.
 */
bool _isdigit(int c);

/**
 * @brief Check if the given character is a valid identifier character
 * (alphanumeric or underscore).
 *
 * @param c The character to check.
 * @return true if the character is a valid identifier character, false otherwise.
 */
bool _isident(int c);

/**
 * @brief Check if the given character is a whitespace character.
 *
 * @param c The character to check.
 * @return true if the character is a whitespace character, false otherwise.
 */
bool _isspace(int c);

/**
 * @brief Check if the given character is a quote character.
 *
 * @param c The character to check.
 * @return true if the character is a quote character, false otherwise.
 */
bool _isquote(int c);

/**
 * @brief Check if the given string represents a number.
 *
 * @param s The string to check.
 * @return true if the string represents a number, false otherwise.
 */
bool _isnumber(const char *s);

#endif /* _CTYPE_H_ */

