#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>


/**
 * struct stack - doubly linked list of a stack (or queue)
 * @n: integer
 * @prev: points to the previous node of the stack
 * @next: points to the next node of the stack
 *
 * Description: doubly linked list node structure
 */
typedef struct stack
{
	int n;
	struct stack *previous;
	struct stack *next;
} stack;

/**
 * struct global_struct - structure to use in the functions
 * @lifo: stack or queue
 * @count: current line
 * @s: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 */
typedef struct global_struct
{
	int lifo;
	unsigned int count;
	char  *s;
	stack *head;
	FILE *fd;
	char *buffer;
} global;

/**
 * struct opcode_struct - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct opcode_struct
{
	char *opcode;
	void (*f)(stack **, unsigned int);
} opcode_t;

extern global vglo;

/* opcodes */
void push_opcode(stack **, unsigned int);
void pall_opcode(stack **, unsigned int);
void pint_opcode(stack **, unsigned int);
void pop_opcode(stack **, unsigned int);
void swap_opcode(stack **, unsigned int);
void _queue(stack **, unsigned int);
void _stack(stack **, unsigned int);
void add_opcode(stack **, unsigned int);
void nop_opcode(stack **, unsigned int);
void sub_opcode(stack **, unsigned int);
void div_opcode(stack **, unsigned int);
void mul_opcode(stack **, unsigned int);
void mod_opcode(stack **, unsigned int);
void pchar_opcode(stack **, unsigned int);
void pstr_opcode(stack **, unsigned int);
void rotl_opcode(stack **, unsigned int);
void rotr_opcode(stack **, unsigned int);

/* get function */
void (*get_opcode_func(char *))(stack **, unsigned int);

/* string functions */
int _search(char *, char);
char *_strtoky(char *, char *);
int _strcmp(char *, char *);

/* malloc functions */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);


/* doubly linked list functions */
stack *add_dnodeint_end(stack **, const int);
stack *add_dnodeint(stack **, const int);
void free_dlistint(stack *);

/* main */
void free_vglo(void);

#endif
