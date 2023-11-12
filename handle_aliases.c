#include "builtins.h"

/**
 * __alias_add - add an alias to a list of aliases
 * @aliases: a pointer to a list of aliases
 * @name: the name of the alias
 * @value: the value of the alias
 */

/* here comes the prototype */
void __alias_add(alias_t **aliases, const char *name, const char *value)
{
	/*checks if the alias already exist*/
	alias_t *alias = get_dict_node(aliases ? *aliases : NULL, name);

	if (alias)
	{
		free(alias->val);
		alias->val = _strdup(value);
	}
	else
	{
		/* add a new one if alias does not eixst */
		add_dict_node_end(aliases, name, value);
	}
}


/**
 * __alias_print - The alias will be printed
 * @alias: the alias to print
 */
void __alias_print(alias_t *alias)
{
	write(STDOUT_FILENO, alias->key, _strlen(alias->key));
	write(STDOUT_FILENO, "='", 2);
	write(STDOUT_FILENO, alias->val, _strlen(alias->val));
	write(STDOUT_FILENO, "'\n", 2);
}


/**
 * __alias - create and display aliases
 * @info: shell info struct
 *
 * Return: Nothing to return
 */
int __alias(info_t *info)
{
	alias_t *alias;
	char *name, **args = info->tokens + 1;
	ssize_t name_len;

	info->status = EXIT_SUCCESS;
	/* checks if argument are intact */
	if (*args0)
	{
		do
		{
			/* check if it is an alias */
			name_len = _strchr(*args, '=');
			if (name_len == -1)
			{
				alias = get_dict_node(info->aliases, *args);
				if (alias)
				{
					__alias_print(alias);
				}
				else
				{
					/* display error if no alias found */
					perrorl("not found", *info->tokens, *args, NULL);
					info->status = EXIT_FAILURE;
				}
			}
			else
			{
				/* give update to the alias */
				name = _strndup(*args, name_len);
				__alias_add(&info->aliases, name, *args + name_len + 1);
				free(name);
			}
		} while (*++args);
	}
	else
	{
		/* print all alias */
		for (alias = info->aliases; alias; alias = alias->next)
			__alias_print(alias);
	}

	return (info->status);
}
