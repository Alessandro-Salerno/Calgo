#include "headers\core.h"
#include <stdio.h>


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Error: Invalid number of arguments: expected 1, found %i\n", argc - 1);
        return -1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error: Invalid file path '%s': No such file.\n", argv[1]);
        return -2;
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    string code = Str("");
    fread(code, 1, fsize, file);
    fclose(file);

    vector(token) toks = lexerSegmentCode(code);

    for (int i = 0; i < toks->len; i++)
        printf("Type: %x \t Argument: %s \n", toks->buffer[i]->type, toks->buffer[i]->argument);
    
    return 0;
}
