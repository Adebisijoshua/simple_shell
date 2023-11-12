#include "builtins.h"

/**
 * __cd_error - show an error upon failure to change directory
 * @info: shell info
 * @dir: directory
 */
void __cd_error(info_t *info, char *dir)
{
	/* create an error message */
	char *error = strjoin(NULL, " ", "can't cd to", dir);

	/* pritn the error meesage with relevant info */
	perrorl_default(*info->argv, info->lineno, error, *info->tokens, NULL);

	/* set the status to indicate the failure */
	info->status = 1;

	/* free memory allocated for the error message */
	free(error message);
}


/**
 * __cd_good - upgrade the environment upon success
 * @info: shell info
 */
void __cd_good(info_t *info)
{
	/* Save the current token for later retriev */
	char **tokens = info->tokens;
	/* switch token to setenv temporaly */
	char *setenv_tokens[] = {"setenv", NULL, NULL, NULL};

	/* update the environment variable */
	info->tokens = setenv_tokens;

	setenv_tokens[1] = "OLDPWD";
	setenv_tokens[2] = info->cwd;

	__setenv(info);

	/* free the current working directory */
	free(info->cwd);
	info->cwd = getcwd(NULL, 0);

	/* update the environment */
	setenv_tokens[1] = "PWD";
	setenv_tokens[2] = info->cwd;

	__setenv(info);

	/* get back the original token */
	info->tokens = tokens;

	/* set the status to indicate success */
	info->status = EXIT_SUCCESS;
}


/**
 * __cd - changes the directory
 * @info: arguments passed
 *
 * Return: int
 */
int __cd(info_t *info)
{
	char *dir = NULL, **args = info->tokens + 1;

	info->status = EXIT_SUCCESS;
	if (*args)
	{
		if (!_strcmp(*args, "-"))
		{
			dir = get_dict_val(info->env, "OLDPWD");
			if (!dir)
				dir = info->cwd;

			info->status = chdir(dir);
			if (!info->status)
			{
				write(STDOUT_FILENO, dir, _strlen(dir));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
		{
			dir = *args;
			info->status = chdir(dir);
		}
	}
	else
	{
		dir = get_dict_val(info->env, "HOME");
		if (dir)
			info->status = chdir(dir);
	}
	if (info->status != -1)
		__cd_success(info);
	else
		__cd_error(info, dir);

	return (info->status);
}
