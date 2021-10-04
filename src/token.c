#include "..\headers\token.h"
#include <malloc.h>


token Token()
{
    token new_token     = malloc(sizeof(_Token));
    new_token->argument = Str("");
    new_token->type     = 0x00;

    return new_token;
}


tokens TokenArray(int capacity)
{
    tokens new_array = malloc(sizeof(_TokenArray));
    new_array->buffer = calloc(capacity, sizeof(token));
    new_array->length = 0;

    return new_array;
}
