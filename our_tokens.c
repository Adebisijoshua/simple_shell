#include "tokens.h"

/**
 * sizeoftoken - split a string into words (tokens) and dequote
 * @str: the string to tokenize
 * Return: If malloc fails or if str is 0 or contains no tokens, return NULL.
 * Otherwise, return an array containing the tokens in str, terminated by NULL.
 */
char **sizeoftoken(const char *str)
{
	/* array to store token */
	char **tokens;
	/* Pointer to the current token in the string */
	const char *tok;
	/* size of tokens */
	size_t count;
	/* state to hnadle string */
	quote_state_t state;

	/* check if input string is NULL */
	if (!str)
		return (NULL);

	/* Allocate memory for the array of tokens */
	tokens = malloc(sizeof(char *) * (count_tokens(str) + 1));
	if (!tokens)
		return (NULL);

	/* Loop through the string to extract tokens */
	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		/* Set the current token */
		tok = str;

		/* Loop through the string until a token is found */
		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			/* Copy the token to the array */
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}

		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			/* Free the memory in case of failure and return NULL */
			free_tokens(&tokens);
			return (NULL);
		}
		/* Set the last element of the array to NULL to terminate it */
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	/* Return the array of tokens */
	return (tokens);
}


/**
 * number_tokens - compute the length of a string after dequoting
 * @str: the string to evaluate
 * Return: Return the length of str after dequoting
 */
size_t number_tokens(const char *str)
{
	/* Count of tokens */
	size_t count;
	/* State to handle quotes in the string */
	quote_state_t state;

	/* Loop through the string to count tokens */
	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		/* Loop through the string until a token is found */
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
	/* Return the count of tokens */
	return (count tokens);
}


/**
 * tokenize_andquote - split a string into words (tokens)
 * @str: the string to tokenize
 * Return: If malloc fails or if str is 0 or contains no tokens, return NULL.
 * Otherwise, return an array containing the tokens in str, terminated by NULL.
 */
/* Array to store tokens */
char **tokenize_andquote(const char *str)
{
	char **tokens;
	const char *tok;
	size_t count;

	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens_noquote(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *str; ++count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok = str;
		do {
			++str;
		} while (*str && !_isspace(*str));

		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	return (tokens);
}


/**
 * count_tokens_andquote - count the words in a string
 * @str: the string to evaluate
 * Return: If str is NULL, return -1.
 * Otherwise, return the number of words in str.
 */
size_t count_tokens_andquote(const char *str)
{
	size_t tok_count;

	for (tok_count = 0; *str; ++tok_count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !_isspace(*str));
	}
	return (tok_count);
}


/**
 * allow_tokens - free & nullify an array of strings
 * @tokens: pointer to an array of tokens
 */
void allow_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
		return;

	tok = *tokens;
	if (!tok)
		return;

	while (*tok)
		free(*tok++);
	free(*tokens);

	*tokens = NULL;
}
