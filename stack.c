#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void stack_push(stack_t **stack, stack_t *elem)
{

    // se a pilha nao existir
    if (!stack)
    {
        printf("ERRO: nao eh possivel inserir elementos pois a pilha nao existe.\n");
        return;
    }

    // se o elemento nao existir
    if (!elem)
    {
        printf("ERRO: nao eh possivel inserir o elemento na pilha pois ele nao existe.\n");
        return;
    }

    // se a pilha estiver vazia, recebe o primeiro elemento
    if ((*stack) == NULL)
    {
        elem->next = NULL;
        (*stack) = elem;
    }
    else
    {
        elem->next = *stack;
        *stack = elem;
    }

    return;
}

int stack_size(stack_t *stack)
{

    int size = 0;
    stack_t *aux;

    if (stack == NULL)
        return 0;

    aux = stack;
    while (aux != NULL)
    {

        aux = aux->next;
        size++;
    }

    return size;
}

stack_t *stack_pop(stack_t **stack)
{

    stack_t *aux;

    // se a pilha nao existir
    if (stack == NULL)
    {
        printf("ERRO: nao eh possivel remover o elemento pois a pilha nao existe.\n");
        return NULL;
    }

    // se a pilha estiver vazia
    if ((*stack) == NULL)
    {
        printf("ERRO: nao eh possivel remover o elemento na pilha pois ela esta vazia.\n");
        return NULL;
    }

    aux = (*stack);

    *stack = (*stack)->next;

    return aux;
}

void stack_print(char *name, stack_t *stack, void print_elem(void *))
{

    stack_t *ptr = stack;

    if (stack == NULL)
    {
        printf("%s []\n", name);
        return;
    }

    printf("%s [", name);

    while (ptr->next != stack)
    {
        print_elem(ptr);
        ptr = ptr->next;
        // se for o ultimo
        if (ptr->next != stack)
            printf(" ");
    }

    printf("]\n");

    return;
}
