#ifndef __STACK__
#define __STACK__

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct stack_t
{
    struct stack_t *next;
} stack_t;

void stack_push(stack_t **stack, stack_t *elem);

stack_t *stack_pop(stack_t **stack);

int stack_size(stack_t *stack);

void stack_print(char *name, stack_t *queue, void print_elem(void *));

#endif
