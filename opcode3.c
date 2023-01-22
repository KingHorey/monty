#include "monty.h"

/**
 * _div - division oooo
 * @stack: list address
 * @line_number: line
 *
 * Return: void
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int dived;
	int tmode = _mode;

	if (counter(stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	_mode = 1;
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		if (ptr->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			cleanStack(stack);
			exit(EXIT_FAILURE);
		}
		ptr = ptr->prev;
		dived = ptr->n / (ptr->next)->n;
		ptr->n = dived;
		_pop(stack, line_number);
	}
	if (_mode == 2)
	{
		if (ptr->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			cleanStack(stack);
			exit(EXIT_FAILURE);
		}
		ptr = ptr->next;
		dived = ptr->n / (ptr->prev)->n;
		ptr->n = dived;
		_pop(stack, line_number);
	}
	_mode = tmode;
}

/**
 * _mul - multiplies
 * @stack: list address
 * @line_number: line
 *
 * Return: void
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int muled;
	int tmode = _mode;

	if (counter(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	_mode = 1;
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr = ptr->prev;
		muled = (ptr->n) * ((ptr->next)->n);
		ptr->n = muled;
		_pop(stack, line_number);
	}
	if (_mode == 2)
	{
		ptr = ptr->next;
		muled = (ptr->n) * ((ptr->prev)->n);
		ptr->n = muled;
		_pop(stack, line_number);
	}
	_mode = tmode;
}

/**
 * _mod - modulus
 * @stack: list address
 * @line_number: line
 *
 * Return: void
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int moded;
	int tmode = _mode;

	if (counter(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	_mode = 1;
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		if (ptr->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			cleanStack(stack);
			exit(EXIT_FAILURE);
		}
		ptr = ptr->prev;
		moded = ptr->n % (ptr->next)->n;
		ptr->n = moded;
		_pop(stack, line_number);
	}
	if (_mode == 2)
	{
		if (ptr->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			cleanStack(stack);
			exit(EXIT_FAILURE);
		}
		ptr = ptr->next;
		moded = ptr->n % (ptr->prev)->n;
		ptr->n = moded;
		_pop(stack, line_number);
	}
	_mode = tmode;
}

/**
 * _pchar - character
 * @stack: list address
 * @line_number: command line
 *
 * Return: void
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int tmode = _mode;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	if (ptr->n > 127 || ptr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	_mode = 1;
	if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		putchar(ptr->n);
	}
	if (_mode == 2)
		putchar(ptr->n);
	putchar('\n');
	_mode = tmode;
}

/**
 * _pstr - string
 * @stack: list addrress
 * @line_number: cmd line
 *
 * Return: void
 */

void _pstr(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *ptr = *stack;
	int tmode = _mode;

	_mode = 1;
	if (ptr == NULL)
	{
		putchar('\n');
	}
	else if (ptr->next == NULL)
	{
		if (ptr->n > 0 && ptr->n < 128)
			putchar(ptr->n);
		putchar('\n');
	}
	else if (_mode == 1)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		while (ptr->n > 0 && ptr->n < 128)
		{
			putchar(ptr->n);
			ptr = ptr->prev;
			if (!ptr)
				break;
		}
		putchar('\n');
	}
	else if (_mode == 2)
	{
		while (ptr->n > 31 && ptr->n < 128)
		{
			putchar(ptr->n);
			ptr = ptr->next;
		}
		putchar('\n');
	}
	_mode = tmode;
}
