#include  "..\headers\string.h"
#include "..\headers\ttypes.h"


typedef struct
{
    token_t type;
    string argument;
} _Token;

typedef _Token* token;

typedef struct 
{
    token* buffer;
    int length;
} _TokenArray;

typedef _TokenArray* tokens;

token Token();
tokens TokenArray(int capacity);
