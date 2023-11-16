#include "builtins.h"

/**
  * __unsetenv - unpack environment variable
  * @info: pass arguments
  * Return: status of the arguments
  */
int __unsetenv(info_t *info)
{
	char **args = info->tokens + 1;

	if (*args)
	{
		while (*args)
			del_dict_node(&info->env, *args++);
		info->status = EXIT_SUCCESS;
	}
	else
	{
		perrorl("Too much  arguments.", *info->tokens, NULL);
		info->status = EXIT_FAILURE;
	}
	return (info->status);
}
