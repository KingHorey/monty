#Algorithms & Data Structures - Stack(s) and Queue(s)

##Table of Contents
* [General information](#general-info)
* [Documentation Styles](#documentation)
* [More information](#moreinfo)

###General information
Repository contains tasks to the implementation of stacks and queues in C

###Documentation styles
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
* All your files end with a new line
* All files are checked using betty-style.pl and betty-doc.pl
* There is a maximum of one global variable
* No more than 5 functions per file
* The prototypes of all functions are included in the header file called monty.h

###More information
The following data structures are used and included in the header file

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


* All errors are printed on stderr
* All outputs are printed to stdout
* C codes are compiled with the command: gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
