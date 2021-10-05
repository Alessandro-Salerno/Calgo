#include  "..\headers\string.h"
#include "..\headers\ttypes.h"


typedef struct
{
    token_t type;
    string argument;
} _Token;

typedef _Token* token;

token Token();
