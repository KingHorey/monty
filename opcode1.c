#include "monty.h"

/**
 * create_node - creates node with value
 * @num: number to be in the node
 * Return: address of node
 */

stack_t *create_node(int num)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->prev = NULL;
	new->n = num;

	return (new);
}

/**
 * _push - creates a stack in stack and queue mode
 * @stack: address
 * @line_number: mode
 *
 * Return: void
 */

void _push(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *newnode = NULL;
	stack_t *ptr = *stack;

	newnode = create_node(number);

	if (ptr == NULL)
		*stack = newnode;
	else if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->prev = ptr;
	}
	else if (_mode == 2)
	{
		ptr->prev = newnode;
		newnode->next = ptr;
		*stack = newnode;
	}
}

/**
 * _pop - deletes top by definition
 * @stack: address
 * @line_number: q or stk
 *
 * Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	stack_t *temp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	if (ptr->next == NULL)
	{
		free(ptr);
		*stack = NULL;
	}
	else if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		(ptr->prev)->next = NULL;
		free(ptr);
	}
	else if (_mode == 2)
	{
		temp = ptr;
		ptr = ptr->next;
		ptr->prev = NULL;
		free(temp);
		*stack = ptr;
	}
}

/**
 * _pall - print all contained in stack
 * @stack: address
 * @line_number: queue or stack
 *
 * Return: void
 */

void _pall(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *ptr = *stack;

	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->prev;
		}
	}
/*
 *	else if (ptr != NULL && _mode == 2)
 *	{
 *		while (ptr != NULL)
 *		{
 *			printf("%d\n", ptr->n);
 *			ptr = ptr->next;
 *		}
 *	}
 */
}

/**
 * _pint - prints top most
 * @stack: address
 * @line_number: indicator
 *
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
	}
	printf("%d\n", ptr->n);
}
