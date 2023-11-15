#include "dict.h"

/**
  * get_dict_val - take a value from a dictionary
  * @head: dict
  * @key: entry key
  *
  * Return: enttry value to the key
  */
char *get_dict_val(dict_t *head, const char *key)
{
	/* Check if key is NULL */
	if (!key)
		return (NULL);

	/* Traverse the dictionary to find the entry with the specified key */
	while (head)
	{
		/* Compare the current node's key with the target key */
		if (!_strcmp(head->key, key))
			return (head->val);/* Return the value if the key matches */
		head = head->next;/* Move to the next node */
	}

	return (NULL);/* Return NULL if the key is not found */
}


/**
  * get_dict_node - get a node by key
  * @head: dict
  * @key: entry key
  *
  * Return: node or NULL
  */
dict_t *get_dict_node(dict_t *head, const char *key)
{
	/* Check if the dictionary is empty */
	if (!head)
		return (NULL);
	/* Compare the key of the current node with the target key */
	if (!_strcmp(head->key, key))
		return (head);/* Return the node if the key matches */

	/* Recursive call to search for the key in the next nodes */
	return (get_dict_node(head->next, key));
}


/**
  * add_dict_node_end - give node at the end of list
  * @headptr: pointer
  * @key: key of the entry
  * @val: val of the entry
  * Return: pointer to list
  */
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val)
{
	dict_t *new;

	/* Check if the head pointer is NULL */
	if (!headptr)
		return (NULL);

	/* If the list is not empty, recursively call to add the node to the end */
	if (*headptr)
		return (add_dict_node_end(&((*headptr)->next), key, val));

	/* Allocate memory for the new node */
	new = malloc(sizeof(dict_t));
	if (!new)
		return (NULL);

	/* Copy the key and value to the new node */
	new->key = _strdup(key);
	new->val = _strdup(val);
	new->next = NULL;

	/* Set the head pointer to the new node */
	*headptr = new;
	/* Return the pointer to the new node */
	return (new);
}


/**
  * del_dict_node - delete
  * @headptr: pointer
  * @key: entry key
  *
  * Return: pointer to resulting list
  */
dict_t *del_dict_node(dict_t **headptr, const char *key)
{
	dict_t *tmp;

	/* Check if the head pointer or dictionary is empty */
	if  (!(headptr && *headptr))
		return (NULL);
	/* Check if the key matches the key of the current node */
	if (!_strcmp((*headptr)->key, key))
	{
		/* Remove the current node and update the head pointer */
		tmp = *headptr;
		(*headptr) = tmp->next;
		free(tmp->key);
		free(tmp->val);
		free(tmp);
	}
	else
		/* Recursive call to search for the key in the next nodes */

		del_dict_node(&((*headptr)->next), key);
	/* Return the updated head pointer */
	return (*headptr);
}


/**
 * free_dict - free a linked list and and set head to NULL
 * @headptr: the first list node
 */
void free_dict(dict_t **headptr)
{
	/* Check if the dictionary is empty */
	if (!*headptr)
		return;

	/* Recursive call to free the next nodes in the list */
	free_dict(&((*headptr)->next));
	/* Free the key, value, and the current node */
	free((*headptr)->key);
	free((*headptr)->val);
	free(*headptr);
	*headptr = NULL;
}
