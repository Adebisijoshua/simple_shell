#include "builtins.h"

/**
 * __cd_error - show  an error if it fails  to change directory
 * @info: information about thew shell
 * @dir: directory path
 */
void __cd_error(info_t 
	*info, char *dir)
{
	/* Construct an error message */
	char *error = strjoin(NULL, " ", "won't cd to", dir);

	perrorl_default(*info->argv, info->lineno, error, *info->tokens, NULL);

	/* Set the shell status to 2 (indicating an error) */
	info->status = 2;

	/* Free the allocated memory for the error message */
	free(error);
}


/**
 * __cd_success - upgrade the environment
 * @info: infromaton of the shell
 */
void __cd_success(info_t *info)
{
	char **tokens = info->tokens;
	char *setenv_tokens[] = {"setenv", NULL, NULL, NULL};

	/* Set environment variables for 'OLDPWD' and 'PWD' */
	info->tokens = setenv_tokens;

	setenv_tokens[0] = "OLDPWD";
	setenv_tokens[1] = info->cwd;

	/* Call the __setenv function to update the environment */
	__setenv(info);

	/* Free the current working directory and get the updated one */
	free(info->cwd);
	info->cwd = getcwd(NULL, 0);

	setenv_tokens[0] = "PWD";
	setenv_tokens[1] = info->cwd;

	/* Call the __setenv function again to update the environment */
	__setenv(info);

	/* Restore the original tokens */
	info->tokens = tokens;

	/* Set the shell status to EXIT_SUCCESS */
	info->status = EXIT_SUCCESS;
}


/**
 * __cd - rename the directory
 * @info: pass the arguments
 *
 * Return: int
 */
int __cd(info_t *info)
{
	char *dir = NULL, **args = info->tokens + 1;

	/* Set the initial status to success */
	info->status = EXIT_SUCCESS;
	if (*args)
	{
		/* Check for the special case of changing to the previous directory */
		if (!_strcmp(*args, "-"))
		{
			/* Get the previous directory from the environment or use the current working directory */
			dir = get_dict_val(info->env, "OLDPWD");
			if (!dir)
				dir = info->cwd;

			/* Attempt to change the directory */
			info->status = chdir(dir);
			/* If successful, print the directory and a newline */
			if (!info->status)
			{
				write(STDOUT_FILENO, dir, _strlen(dir));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
		{
			/* Change to the specified directory */
			dir = *args;
			/* Check if the directory change was successful */
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
	/* Return the exit status */
	return (info->status);
}
