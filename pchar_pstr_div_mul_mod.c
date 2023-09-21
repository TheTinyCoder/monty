#include "monty.h"

/**
 * div_opcode - divides the second node by the top node of the stack
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void div_opcode(stack **head, unsigned int line_number)
{
	int m = 0;
	stack *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n /= (*head)->n;
	pop_opcode(head, line_number);
}


/**
 * mul_opcode - multiplies the top node to the second node of the stack
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void mul_opcode(stack **head, unsigned int line_number)
{
	int m = 0;
	stack *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n *= (*head)->n;
	pop_opcode(head, line_number);
}


/**
 * mod_opcode - computes the rest of the division of the second node
 * by the top node of the stack
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void mod_opcode(stack **head, unsigned int line_number)
{
	int m = 0;
	stack *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n %= (*head)->n;
	pop_opcode(head, line_number);
}


/**
 * pchar_opcode - print the char value of the first node
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void pchar_opcode(stack **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}


/**
 * pstr_opcode - prints the string of the stack
 *
 * @head: head of the linked list
 * @line_number: line number;
 * Return: no return
 */

void pstr_opcode(stack **head, unsigned int line_number)
{
	stack *aux;
	(void)line_number;

	aux = *head;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
