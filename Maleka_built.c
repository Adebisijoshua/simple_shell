#include "builtins.h"

/**
 * get_builtins - get builtins
 * Return: NULL-terminated statically-allocated array of builtins
 */
const builtin_t *get_builtins(void)
{
	static builtin_t builtins[] = {
		{"alias", __alias, ALIAS_HELP, ALIAS_DESC},
		{"cd", __cd, CD_HELP, CD_DESC},
		{"exec", __exec, EXEC_HELP, EXEC_DESC},
		{"setenv", __setenv, SETENV_HELP, SETENV_DESC},
		{"exit", __exit, EXIT_HELP, EXIT_DESC},
		{"help", __help, HELP_HELP, HELP_DESC},
		{"env", __env, ENV_HELP, ENV_DESC},
		{"unsetenv", __unsetenv, UNSETENV_HELP, UNSETENV_DESC},
		{0} /* Null-terminate the array */
	};

	return (builtins);
}

/**
 * get_builtin - get a builtin by name
 * @name: the name of the builtin that will be retrieved
 * Return: if no match is found NULL, otherwise a pointer to the builtin
 */
const builtin_t *get_builtin(const char *name)
{
	const builtin_t *builtin = NULL;

	/* Iterate through the array of built-in commands */
	for (builtin = get_builtins(); builtin->name; builtin += 1)
	{
		if (_strcmp(name, builtin->name) == 0)
			return (builtin);/* Return the matching builtin if found */
	}
	return (NULL);/* Return NULL if no match is found */
}
