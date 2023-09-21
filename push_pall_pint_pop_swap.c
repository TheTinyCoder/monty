#include "monty.h"

/**
 * push_opcode - pushes a node to the stack
 *
 * @head: head of the linked list
 * @line_number: line number
 * Return: no return
 */

void push_opcode(stack **head, unsigned int line_number)
{
	int i, j;

	if (!vglo.s)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.s[j]; j++)
	{
		if (!isdigit(vglo.s[j]) && vglo.s[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(vglo.s);

	if (vglo.lifo == 1)
		add_dnodeint(head, i);
	else
		add_dnodeint_end(head, i);
}


/**
 * pall_opcode - prints all values on the stack
 *
 * @head: head of the linked list
 * @line_number: line numbers
 * Return: no return
 */

void pall_opcode(stack **head, unsigned int line_number)
{
	stack *aux;
	(void)line_number;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}


/**
 * pint_opcode - prints the value at the top of the stack
 *
 * @head: head of the linked list
 * @line_number: line number
 * Return: no return
 */

void pint_opcode(stack **head, unsigned int line_number)
{
	(void)line_number;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}


/**
 * pop_opcode - removes the top node of the stack
 *
 * @head: head of the linked list
 * @line_number: line number
 * Return: no return
 */

void pop_opcode(stack **head, unsigned int line_number)
{
	stack *aux;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *head;
	*head = (*head)->next;
	free(aux);
}


/**
 * swap_opcode - swaps the top two nodes of the stack
 *
 * @head: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void swap_opcode(stack **head, unsigned int line_number)
{
	int m = 0;
	stack *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *head;
	*head = (*head)->next;
	aux->next = (*head)->next;
	aux->previous = *head;
	(*head)->next = aux;
	(*head)->previous = NULL;
}
