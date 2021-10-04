#include <stdio.h>
#include <malloc.h>
#include "..\headers\stack.h"


stack Stack(int capacity)
{
    stack new_stack   = malloc(sizeof(_Stack));
    new_stack->buffer   = calloc(capacity, sizeof(int));
    new_stack->length   = -1;
    new_stack->capacity = capacity;

    return new_stack;
}


void stackPush(stack list, int element)
{
    list->length++;

    if (list->length >= list->capacity)
    {
        list->capacity *= 2;
        list->buffer    = realloc(list->buffer, sizeof(int) * list->capacity);
    }

    list->buffer[list->length] = element;
}


void stackPop(stack list)
{
}

int stackGet(stack list, int index)
{
    return list->buffer[index];
}


void stackShow(stack list)
{
    if (list->length == -1)
    {
        printf("This stack is empty!\n");
        return;
    }

    for (int i = 0; i < list->length + 1; i++)
        printf("Element %i: %i\n", i, stackGet(list, i));

    printf("\n");
}
