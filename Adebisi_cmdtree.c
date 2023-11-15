#include "command.h"

/**
 * cmd_to_tree - build a binary tree of commands
 * @tokens: parse
 *
 * Return: on memory allocation fails.
 */
cmdtree_t *cmd_to_tree(const char * const *tokens __attribute__((unused)))
{
	/* Placeholder function, currently returning NULL */
	return (NULL);
}

/**
 * free_cmdtree - ALLOW a binary tree and and set root to EMPTY
 * @rootptr: pointer the binary which hold the adress
 * Return: EMPTY
 */
void free_cmdtree(cmdtree_t **rootptr)
{
	/* Check if the root pointer is not NULL and the tree is not empty */
	if (rootptr && *rootptr)
	{
		/* Recursively free the memory of the success and failure subtrees */
        free_cmdtree(&((*rootptr)->success));
		free_cmdtree(&((*rootptr)->success));
		free_cmdtree(&((*rootptr)->failure));
		 /* Set tokens to NULL and the root to NULL */
		(*rootptr)->tokens = NULL;
		(*rootptr) = NULL;
	}
}
