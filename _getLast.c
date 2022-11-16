#include "shell.h"

/**
 * _getLast - get last node
 * @HdNode: first node
 * Return: last element
 */
environment_t *_getLast(environment_t *HdNode)
{
	environment_t *head, *next;

	head = HdNode;

	if (head == NULL)
		return (NULL);

	next = head->next;

	if (next == NULL)
		return (head);
	else
		return (_getLast(next));
}
