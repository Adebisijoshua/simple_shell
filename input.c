#include "getline.h"
#include "hsh.h"

/**
 * read_input - To get the input
 * @info: shell information
 *
 * Return: Return size of the line
 */
bool read_input(info_t *info)
{
	/* declare the variables */
	char *line = NULL, *temp = NULL;

	if (info->interactive)
		write(STDERR_FILENO, "$ ", 2);

	info->lineno += 1;
	while (_read_input(&info->line, info->fileno) &
		(QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
	{
		temp = line;
		line = strjoin(NULL, "", temp, info->line);
		free(temp);
		free(info->line);
		if (info->interactive)
			write(STDERR_FILENO, "> ", 2);
		info->lineno += 1;
	}
	if (line)
	{
		temp = info->line;
		info->line = strjoin(NULL, "", line, temp);
		free(temp);
		free(line);
	}
	return (info->line); /* return info */
}


/**
 * _read_input - To read a single line
 * @lineptr: buffer line
 * @fd: file descriptor to read from
 *
 * Return: ending quote state
 */
quote_state_t _read_input(char **lineptr, int fd)
{
	/* declare sub prototype */
	char *line = *lineptr = _getline(fd);
	static quote_state_t state = QUOTE_NONE;
	size_t index = 0;

	if (line)
	{
		switch (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
		{
		case QUOTE_DOUBLE:
		case QUOTE_SINGLE:
			do {
				index += quote_state_len(line + index, state);
				if (line[index] == '\0')
					continue;
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
					index += 1;
				/* fall through */
		case 0:
				state = quote_state(line[index]);
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
					index += 1;
			} while (line[index]);
		}
	}
	return (state); /* return state */
}
