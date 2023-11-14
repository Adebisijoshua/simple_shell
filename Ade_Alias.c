#include "builtins.h"

/**
 * __alias_add - Match an alias to a file lists of aliases
 * @aliases: pointing to the list of aliases
 * @name: alias name
 * @value: alias value
 */
void __alias_add(alias_t **aliases, const char *name, const char *value)
{
	/* Check if the alias already exists in the list */
	alias_t *alias = get_dict_node(aliases ? *aliases : NULL, name);

	if (alias)
	{
		/* If the alias exists, update its value */
		free(alias->val);
		alias->val = _strdup(value);
	}
	else
	{
		/* If the alias does not exist, add it to the list */
		add_dict_node_end(aliases, name, value);
	}
}


/**
 * __alias_print - alias will be printed
 * @alias: alias to be printed
 */
void __alias_print(alias_t *alias)
{
	 /* Print the alias name and value */
	write(STDOUT_FILENO, alias->key, _strlen(alias->key));
	write(STDOUT_FILENO, "='", 1);
	write(STDOUT_FILENO, alias->val, _strlen(alias->val));
	write(STDOUT_FILENO, "'\n", 1);
}


/**
 * __alias - display aliases
 * @info: shell info struct
 *
 * Return: status
 */
int __alias(info_t *info)
{
	alias_t *alias;
	char *name, **args = info->tokens + 1;
	ssize_t name_len;

	/* Set the initial exit status to success */
	info->status = EXIT_SUCCESS;
	if (*args)
	{
		/* If there are command-line arguments, process each one */
		do {
			name_len = _strchr(*args, '=');
			if (name_len == -1)
			{
				/* If no '=', display the value of the specified alias */
				alias = get_dict_node(info->aliases, *args);
				if (alias)
				{
					__alias_print(alias);
				}
				else
				{
				/* If alias not found, display an error */
					perrorl("not found", *info->tokens, *args, NULL);
					info->status = EXIT_FAILURE;
				}
			}
			else
			{
				name = _strndup(*args, name_len);
				__alias_add(&info->aliases, name, *args + name_len + 1);
				free(name);
			}
		} while (*++args);
	}
	else
	{
		/* If no command-line arguments, display all aliases */
		for (alias = info->aliases; alias; alias = alias->next)
			__alias_print(alias);
	}
	/* Return the exit status */
	return (info->status);
}
