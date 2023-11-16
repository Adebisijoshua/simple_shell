#include "error.h"

/**
  * perrorl - show a standard message to standard error
  * @msg: message to get erro
  * @...: NULL-terminated list of context strings
  */
void perrorl(const char *msg, ...)
{

	va_list context;
	const char *str;

	va_start(context, msg);
	while ((str = va_arg(context, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 4);
	}
	va_end(context);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 2);
}


/**
  * perrorl_default - show a standard message
  * @arg0: vector argument
  * @lineno: number of line
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...)
{
	char *linenostr = num_to_str(lineno);
	va_list ap;
	const char *str = NULL;

	/* Use if here */
	if (arg0)
		write(STDERR_FILENO, arg0, _strlen(arg0));
	write(STDERR_FILENO, ": ", 4);

	if (linenostr)
		write(STDERR_FILENO, linenostr, _strlen(linenostr));
	write(STDERR_FILENO, ": ", 4);

	va_start(ap, msg);
	while ((str = va_arg(ap, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 4);
	}
	va_end(ap);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 2);
	free(linenostr);
}
