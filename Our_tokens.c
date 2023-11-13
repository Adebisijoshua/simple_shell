#include "tokens.h"

/**
 * tokenize - arrange the  string into words and dequote
 * @str: the string will be tokenize
 * Return: If malloc is not successful or if str  contains no tokens, return EMPTY.
 * If not,give  an array having the tokens in str, terminated by EMPTY.
 */
char **tokenize(const char *str)
{
	char **tokens; /* array to store the token */
	const char *tok; /* pointer to the current token in the string */
	size_t count; /* counter for the number of tokens*/
	quote_state_t state; /* representing the quoting state*/

	/* check if the input string is NULL*/
	if (!str)
		return (NULL);

	/* allocate memory for the array of tokens*/
	tokens = malloc(sizeof(char *) * (count_tokens(str) + 1));
	if (!tokens)
		return (NULL);

	/* loop through the input string*/
	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		tok = str;

		/* Loop to identify and handle quoted sections in the token */
		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}

		 /* Allocate memory for the current token and copy it */
		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';/* Null-terminate the token */
	}
	tokens[count] = NULL;/* Null-terminate the array of tokens */

	return (tokens);
}


/**
 * count_tokens - give the length of a string after dequoting
 * @str: the string to work on
 * Return: Bring back the length of str after dequoting
 */
size_t count_tokens(const char *str)
{
	size_t count;/* Counter for the number of tokens */
	quote_state_t state;/* Enum representing the quoting state */

	/* Loop through the input string to count tokens after dequoting */
	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}
	}
	return (count);
}


/**
 * tokenize_noquote - split a string into words (tokens)
 * @str: the string to tokenize
 * Return: If malloc fails or if str is 0 or contains no tokens, return NULL.
 * Otherwise, return an array containing the tokens in str, terminated by NULL.
 */
char **tokenize_noquote(const char *str)/* Array to store the tokens */
{
	char **tokens;/* Pointer to the current token in the input string */
	const char *tok;
	size_t count;/* Counter for the number of tokens */

	/* Check if the input string is NULL */
	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens_noquote(str) + 1));
	if (!tokens)
		return (NULL);

	/* Loop through the input string to tokenize without dequoting */
	for (count = 0; *str; ++count)
	{
		/* Skip leading white spaces */
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok = str;
		/* Find the end of the current token */
		do {
			++str;
		} while (*str && !_isspace(*str));

		/* Allocate memory for the current token and copy it */
		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';/* Null-terminate the token */
	}
	tokens[count] = NULL;/* Null-terminate the array of tokens */

	return (tokens);
}


/**
 * count_tokens_noquote - know the words in a string
 * @str: the string to work on
 * Return: If str is NULL, return NULL.
 * If str is not NULL, return the number of words in str.
 */
size_t count_tokens_noquote(const char *str)/* Counter for the number of tokens */
{
	size_t tok_count;

	/* Loop through the input string to count tokens without dequoting */
	for (tok_count = 0; *str; ++tok_count)
	{
		/* Skip leading white spaces */
		while (_isspace(*str))
			++str;
		if (!*str)
			break;
		 /* Find the end of the current token */
		do {
			++str;
		} while (*str && !_isspace(*str));
	}
	return (tok_count);
}


/**
 * free_tokens - allow  an array of strings
 * @tokens: The pointer to an array of tokens
 */
void free_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
		return;

	tok = *tokens;/* Check if the array of tokens is NULL */
	if (!tok)
		return;

	/* Free each individual token and move the pointer to the next one */
	while (*tok)
		free(*tok++);
	/* Free the array of tokens and nullify the input pointer */
	free(*tokens);

	*tokens = NULL;
}
