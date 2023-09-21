#include "monty.h"

/**
 * rotl_opcode - rotates first node to the bottom & the second to the top
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void rotl_opcode(stack **head, unsigned int line_number)
{
	stack *aux1 = NULL;
	stack *aux2 = NULL;
	(void)line_number;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	aux1 = (*head)->next;
	aux2 = *head;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->previous = NULL;
	aux2->next = *head;
	(*head)->next = NULL;
	(*head)->previous = aux2;
	*head = aux1;
}


/**
 * rotr_opcode - reverse the stack
 *
 * @head: head of the linked list
 * @line_number: line number
 * Return: no return
 */

void rotr_opcode(stack **head, unsigned int line_number)
{
	stack *aux = NULL;
	(void)line_number;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	aux = *head;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->previous->next = NULL;
	aux->next = *head;
	aux->previous = NULL;
	(*head)->previous = aux;
	*head = aux;
}
