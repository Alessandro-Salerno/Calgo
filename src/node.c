#include "..\headers\node.h"
#include <malloc.h>


node Node()
{
    node new_node = malloc(sizeof(_Node));
    new_node->arguments = calloc(1024, 1);
    new_node->type = 0x00;
}


nodes NodeArray(int capacity)
{
    nodes new_array = malloc(sizeof(_Nodearray));
    new_array->buffer = calloc(capacity, sizeof(node));
    new_array->length = 0;

    return new_array;
}


block Block()
{
    block new_block = malloc(sizeof(_Block));
    new_block->main = NodeArray(1024);
    new_block->brach1 = NodeArray(1024);
    new_block->brach1 = NodeArray(1024);

    return new_block;
}


blocks BlockArray(int capacity)
{
    blocks new_array = malloc(sizeof(_BlockArray));
    new_array->buffer = calloc(capacity, sizeof(block));
    new_array->length = 0;

    return new_array;
}
