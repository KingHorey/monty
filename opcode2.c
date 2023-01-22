#include "monty.h"

/**
 * counter - counts the stack
 * @stack: address
 * Return: count
 */

int counter(stack_t **stack)
{
	stack_t *ptr = *stack;
	int count = 0;

	if (ptr == NULL)
		return (0);
	while (ptr != NULL)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

/**
 * _swap - changes the topmost
 * @stack: addrress
 * @line_number: mode
 *
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int count = 0;
	int temp;

	count = counter(stack);
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		temp = ptr->n;
		ptr->n = (ptr->prev)->n;
		(ptr->prev)->n = temp;
	}
	if (_mode == 2)
	{
		temp = ptr->n;
		ptr->n = (ptr->next)->n;
		(ptr->next)->n = temp;
	}
}

/**
 * _add - adds the topmost and top more
 * @stack: address
 * @line_number: no longer mode but line number
 *
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int added;
	int tmode = _mode;

	if (counter(stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	_mode = 1;
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr = ptr->prev;
		added = ptr->n + (ptr->next)->n;
		ptr->n = added;
		free(ptr->next);
		ptr->next = NULL;
	}
	if (_mode == 2)
	{
		ptr = ptr->next;
		added = ptr->n + (ptr->prev)->n;
		ptr->n = added;
		free(ptr->prev);
		ptr->prev = NULL;
		*stack = ptr;
	}
	_mode = tmode;
}

/**
 * _nop - function void
 * @stack: Stack list
 * @line_number: Number of the line
 */
void _nop(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t __attribute__ ((unused)) *ptr = *stack;
}

/**
 * _sub - subtarcts
 * @stack: address of list
 * @line_number: error purpose
 *
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int subbed;
	int tmode = _mode;

	if (counter(stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	_mode = 1;
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr = ptr->prev;
		subbed = ptr->n - ptr->next->n;
		ptr->n = subbed;
		_pop(stack, line_number);
	}
	if (_mode == 2)
	{
		ptr = ptr->next;
		subbed = ptr->n - ptr->prev->n;
		ptr->n = subbed;
		_pop(stack, line_number);
	}
	_mode = tmode;
}

