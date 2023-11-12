#include "builtins.h"

/**
  * __env - displays environment
  * @format: arguments passed
  * Return: int
  */
int __env(format_t *format)
{
	/* Pointer to traverse the linked list of environment variables */
	env_t *var;

	format->status = EXIT_SUCCESS;

	/* Iterate through the linked list of environment variables */
	for (var = format->env; var; var = var->next)
	{
		if (var->key)
			write(STDOUT_FILENO, var->key, _strlen(var->key));
		write(STDOUT_FILENO, "=", 1);
		if (var->val)
			write(STDOUT_FILENO, var->val, _strlen(var->val));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (format->status);
}
