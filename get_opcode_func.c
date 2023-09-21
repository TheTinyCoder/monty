#include "monty.h"

/**
 * get_opcode_func - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */

void (*get_opcode_func(char *opc))(stack **stack, unsigned int line_number)
{
	opcode_t opcodes[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"queue", _queue},
		{"stack", _stack},
		{"add", add_opcode},
		{"nop", nop_opcode},
		{"sub", sub_opcode},
		{"mul", mul_opcode},
		{"div", div_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (_strcmp(opcodes[i].opcode, opc) == 0)
			break;
	}

	return (opcodes[i].f);
}
