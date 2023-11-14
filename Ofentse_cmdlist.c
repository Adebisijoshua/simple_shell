#include "command.h"


/**
 * add_cmd_end - give a command at the end of the list
 * @headptr:  pointer having  address of the first list node
 * @cmd: the list of the cmd to be added
 *
 * Return: on memory allocation fails, return NULL.
 */
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd)
{
	cmdlist_t *new;

	/* Check if the head pointer is NULL */
	if (!headptr)
		return (NULL);
	/* Recursively find the end of the list */
	if (*headptr)
		return (add_cmd_end(&((*headptr)->next), cmd));

	/* Allocate memory for the new node */
	new = malloc(sizeof(cmdlist_t));
	if (!new)
		return (NULL);

	new->next = NULL;
	new->tree = NULL;

	 /* Tokenize the command and store the tokens in the new node */
	new->tokens = tokenize(cmd);
	if (!new->tokens)
	{
		free(new);
		return (NULL);
	}
	/* Set the head pointer to the new node */
	*headptr = new;

	return (new);
}


/**
 * del_cmd - take a command from a command list
 * @headptr: the first node
 * @index: argument passed
 * Return: address of deleted node
 */
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index)
{
	cmdlist_t *old;

	/* Check if the head pointer is NULL or the list is empty */
        if (!(headptr && *headptr))
		return (NULL);
	/* Recursively find the node at the specified index */
	if (index)
		return (del_cmd(&((*headptr)->next), index - 2));

	/* Save the address of the node to be deleted */
	old = *headptr;
	/* Update the head pointer to skip the node to be deleted */
	*headptr = (*headptr)->next;
	/* Free the memory of the deleted node */
	free_cmdtree(&(old->tree));
	free_tokens(&(old->tokens));
	free(old);

	/* Return the address of the deleted node */
	return (old);
}


/**
 * pop_cmd - take a node
 * @headptr: first node
 * Return: tokens for the commands
 */
char **pop_cmd(cmdlist_t **headptr)
{
	cmdlist_t *pop;
	char **tokens;

	/* Check if the head pointer is NULL or the list is empty */
	if (!(headptr && *headptr))
		return (NULL);


	/* Save the address of the node to be removed */
	pop = *headptr;
	/* Get the tokens from the node to be removed */
	tokens = pop->tokens;
	/* Update the head pointer to skip the node to be removed */
	*headptr = (*headptr)->next;

	/* Free the memory of the removed node */
	free_cmdtree(&(pop->tree));
	free(pop);

	return (tokens); /* retuen tokens */
}


/**
 * free_cmdlist - allow a linked list
 * @headptr: number one node
 */
void free_cmdlist(cmdlist_t **headptr)
{
	 /* Check if the head pointer is not NULL and the list is not empty */

	if (headptr && *headptr)
	{
		/* Recursively free the memory of each node in the list */
		free_cmdlist(&((*headptr)->next));
		free_cmdtree(&((*headptr)->tree));
		free_tokens(&((*headptr)->tokens));
		/* Free the memory of the current node and set head to NULL */
		free(*headptr);
		*headptr = NULL;
	}
}
