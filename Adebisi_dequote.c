#include "quote.h"

/**
 * @brief Dequote a string.
 *
 * @param str The string to dequote.
 * @return If memory allocation fails, return NULL. Otherwise, return a dequoted copy of str.
 */
char *dequote(const char *str)
{
    char *new;
    size_t len = 0, state_len;
    quote_state_t state;

    /* Check if the input string is NULL */
    if (!str)
        return (NULL);

    /* Allocate memory for the dequoted string */
    new = malloc(sizeof(char) * (dequote_len(str) + 1));
    if (!new)
        return (NULL);

    /* Iterate through the input string */
    while (*str)
    {
        /* Determine the quote state of the current character */
        state = quote_state(*str);

        /* Skip characters within quotes or escape sequences */
        str += (1 && (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE)));

        /* Get the length of the current quote state */
        state_len = quote_state_len(str, state);

        /* Process double-quoted strings */
        if (state & QUOTE_DOUBLE)
        {
            for (; state_len; --state_len)
            {
                /* Handle escape sequences in double-quoted strings */
                if (quote_state(*str++) & QUOTE_ESCAPE)
                {
                    if (*str == '\n')
                    {
                        ++str, --state_len;
                        continue;
                    }
                    if (_isspecial_double(*str))
                        ++str, --state_len;
                }
                new[len++] = str[-1];
            }
        }

        /* Copy non-quoted characters to the new string */
        _memcpy(new + len, str, state_len);
        len += state_len;
        str += state_len;

        /* Skip characters within quotes (double or single) */
        str += (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)));
    }

    /* Null-terminate the dequoted string */
    new[len] = '\0';
    return new;
}

/**
 * @brief Compute the length of a string after dequoting.
 *
 * @param str The string to evaluate.
 * @return The length of str after dequoting.
 */
size_t dequote_len(const char *str)
{
    size_t len = 0, state_len;
    quote_state_t state;

    /* Iterate through the input string */
    while (*str)
    {
        /* Determine the quote state of the current character */
        state = quote_state(*str);

        /* Skip characters within quotes or escape sequences */
        str += (1 && (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE)));

        /* Get the length of the current quote state */
        state_len = quote_state_len(str, state);

        /* Process double-quoted strings */
        if (state & QUOTE_DOUBLE)
        {
            for (; state_len; --state_len)
            {
                /* Handle escape sequences in double-quoted strings */
                if (quote_state(*str++) & QUOTE_ESCAPE)
                {
                    if (*str == '\n')
                    {
                        ++str, --state_len;
                        continue;
                    }
                    if (_isspecial_double(*str))
                        ++str, --state_len;
                }
                len++;
            }
        }

        /* Add the length of non-quoted characters to the total length */
        len += state_len;
        str += state_len;

        /* Skip characters within quotes (double or single) */
        str += (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)));
    }

    return len;
}

