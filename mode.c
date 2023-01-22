#include "monty.h"

/**
 * _smode - set to stack
 * @stack: not useful
 * @line_number: not useful
 */

void _smode(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t __attribute__ ((unused)) *ptr = *stack;

	_mode = 1;
}

/**
 * _qmode - set to queue
 * @stack: not useful
 * @line_number: not useful
 */

void _qmode(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t __attribute__ ((unused)) *ptr = *stack;

	_mode = 2;
}

/**
 * free_dlistint - Free a list.
 * @stack: Head node.
 * Return: Nothing.
 */
void free_dlistint(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_dlistint(current->next);
		free(current);
	}
}

/**
 * _rotl - takes the top to bottom
 * @stack: list address
 * @line_number: cmd line
 *
 * Return: void
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp = 0;
	int tmode = _mode;

	if (ptr != NULL && ptr->next != NULL)
	{
		if (_mode == 1)
		{
			while (ptr->next != NULL)
				ptr = ptr->next;
			temp = ptr->n;
			number = temp;
			_pop(stack, line_number);
			_mode = 2;
			_push(stack, line_number);
			_mode = 1;
		}
		if (_mode == 2)
		{
			temp = ptr->n;
			number = temp;
			_pop(stack, line_number);
			_mode = 1;
			_push(stack, line_number);
			_mode = 2;
		}
	}
	_mode = tmode;
}

/**
 * _rotr - Aaaaa Peeee Ceee, from top to bottom in buhari's voice
 * @stack: list address
 * @line_number: cmd line
 *
 * Return: void
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp = 0;
	int tmode = _mode;

	if (ptr != NULL && ptr->next != NULL)
	{
		temp = ptr->n;
		number = temp;
		_mode = 1;
		_push(stack, line_number);
		*stack = ptr->next;
		(*stack)->prev = NULL;
		free(ptr);
		_mode = tmode;
	}
}
