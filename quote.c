#include "quote.h"

/**
 * quote_state - get the state associated with a given character
 * @c: character
 *
 * Return: the state associated with c
 */
quote_state_t quote_state(char c)
{
	if (_isspace(c))
		return (QUOTE_NONE);/* Return QUOTE_NONE for whitespace characters */
	if (c == '"')
		return (QUOTE_DOUBLE);/* Return QUOTE_DOUBLE for double quotes */
	if (c == '\'')
		return (QUOTE_SINGLE);/* Return QUOTE_SINGLE for single quotes */
	if (c == '\\')
		return (QUOTE_ESCAPE);/* Return QUOTE_ESCAPE for backslashes */
	return (QUOTE_WORD);/* Return QUOTE_WORD for other characters (word characters)*/
}


/**
 * quote_state_f - given state of a function
 * @s: state of a function
 *
 * Return: give back the state associated with it
 */
quote_state_fp quote_state_f(quote_state_t s)
{
	/* switch, case and return case */
	switch (s)
	{
	case QUOTE_NONE:
		return (_quote_state_none);
	case QUOTE_WORD:
		return (_quote_state_word);
	case QUOTE_DOUBLE:
		return (_quote_state_double);
	case QUOTE_SINGLE:
		return (_quote_state_single);
	case QUOTE_ESCAPE:
		return (_quote_state_escape);
	}
	return (NULL);
}


/**
 * quote_state_len - length of a given state
 * @str: string
 * @state: state
 *
 * Return: state associated with it
 */
size_t quote_state_len(const char *str, quote_state_t state)
{
	return (quote_state_f(state)(str, NULL));/* Return Null */
}
