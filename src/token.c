#include "..\headers\token.h"
#include <malloc.h>


token Token()
{
    token new_token     = malloc(sizeof(_Token));
    new_token->argument = Str("");
    new_token->type     = 0x00;

    return new_token;
}
