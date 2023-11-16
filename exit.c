#include "builtins.h"

/**
  * __exit - exits from shell
  * @info: arguments passed
  * Return: int
  */
int __exit(info_t *info)
{
	char **args = info->tokens + 1;

	/* Check if additional arguments are provided */
	if (*args)
	{
		/* Check if the argument is a valid number and within the range of INT_MAX */
		if (_isnumber(*args) && atou(*args) <= INT_MAX)
		{
			info->status = atou(*args);/* Set the exit status */
		}
		else
		{
			/* Print an error message for an illegal number */
			perrorl_default(*info->argv, info->lineno, *args,
					*info->tokens, "Illegal number", NULL);
			info->status = 2;/* Set the exit status to 2 */

			return (info->status);
		}
	}
	/* Close the file if it is open */
	if (info->file)
		close(info->fileno);

	exit(free_info(info));/* Exit the shell, freeing allocated resources */
}
