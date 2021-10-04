typedef struct
{
    int* buffer;
    int  length;
    int  capacity;
} _Stack;

typedef _Stack* stack;

stack Stack(int capacity);
void stackPush(stack list, int element);
void stackPop(stack list);
int stackGet(stack list, int index);
void stackShow(stack list);
