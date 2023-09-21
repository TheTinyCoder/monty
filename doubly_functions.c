#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */

stack *add_dnodeint_end(stack **head, const int n)
{
	stack *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->previous = NULL;
		*head = temp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->previous = aux;
	aux->next = temp;
	return (aux->next);
}


/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack *add_dnodeint(stack **head, const int n)
{
	stack *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->previous = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->previous = temp;
	temp->next = (*head);
	temp->previous = NULL;
	*head = temp;
	return (*head);
}


/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */

void free_dlistint(stack *head)
{
	stack *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
