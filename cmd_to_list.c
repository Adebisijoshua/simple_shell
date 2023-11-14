#include "command.h"

/**
 * cmd_to_list - build a linked list of token for commands
 * @cmd: the command to parse
 *
 * Return: On fails, give  NULL. Otherwise, return 1
 * pointer to the head of the new list.
 */
cmdlist_t *cmd_to_list(const char *cmd)
{
	cmdlist_t *head = NULL;
	size_t count;
	char *split = _strdup(cmd);

	/* Check for memory allocation failure */
	if (!split)
		return (NULL);

	count = split_cmd(split);

	/* Check for memory allocation failure during list construction */
	if (!_cmd_to_list(&head, split, count))
	{
		free_cmdlist(&head);
		return (NULL);
	}
	free(split);

	return (head);/* return */
}


/**
 * _cmd_to_list - build a linked list of tokenized commands
 * @tailptr: pointer to the tail at the command list
 * @split: a line split with null bytes on separators
 * @count: Total number of commands we have in the list
 *
 * Return: On fails,give  return NULL. Otherwise, return 1
 * pointer to the tail at the new list.
 */
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count)
{
	cmdlist_t *tail;

	/* If count is zero, return the current tail pointer */
	if (!count)
		return (*tailptr);

	/* Add a new command to the end of the list and update the tail pointer */
	tail = add_cmd_end(tailptr, split);
	/* Check for memory allocation failure */
	if (!tail)
		return (NULL);

	/* Move the split pointer to the next command */
	while (*split++)
		;

	/* Recursively call _cmd_to_list for the remaining commands */
	return (_cmd_to_list(&tail, split, count - 1));
}
