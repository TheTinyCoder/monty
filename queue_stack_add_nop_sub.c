#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void _queue(stack **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	vglo.lifo = 0;
}


/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void _stack(stack **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	vglo.lifo = 1;
}


/**
 * add_opcode - adds the top two nodes of the stack
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void add_opcode(stack **head, unsigned int line_number)
{
	int m = 0;
	stack *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n += (*head)->n;
	pop_opcode(head, line_number);
}


/**
 * nop_opcode - doesn't do anythinhg
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void nop_opcode(stack **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}


/**
 * sub_opcode - subtracts the top node to the second top node of the stack
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void sub_opcode(stack **head, unsigned int line_number)
{
	int m = 0;
	stack *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n -= (*head)->n;
	pop_opcode(head, line_number);
}
