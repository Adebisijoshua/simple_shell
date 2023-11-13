#include "builtins.h"

/**
  * __exit - exits from shell
  * @info: arguments passed
  * Return: int
  */
int __exit(info_t *info)
{
	char **args = info->tokens + 1;/* Extract arguments from the token array */

	/* Check if an exit status is provided as an argument */
	if (*args)
	{
		/* Check if the argument is a valid number and within the range of int */
		if (_isnumber(*args) && atou(*args) <= INT_MAX)
		{
			info->status = atou(*args);
		}
		else
		{
			/* Print an error message for an illegal number and set status to 2 */
			perrorl_default(*info->argv, info->lineno, *args,
					*info->tokens, "Illegal number", NULL);
			info->status = 2;

			return (info->status);
		}
	}
	/* Close the file if it is open */
	if (info->file)/* Set the exit status */
		close(info->fileno);

	exit(free_info(info));/* Exit the shell after freeing allocated memory */
}
