#include "..\headers\ntypes.h"
#include "..\headers\string.h"


typedef struct
{
    node_t type;
    strings arguments;
} _Node;

typedef _Node* node;

typedef struct
{
    node* buffer;
    int length; 
} _Nodearray;

typedef _Nodearray* nodes;

typedef struct
{
    nodes main;
    nodes brach1;
    nodes branch2;
} _Block;

typedef _Block* block;

typedef struct
{
    block* buffer;
    int length;
} _BlockArray;

typedef _BlockArray* blocks;
