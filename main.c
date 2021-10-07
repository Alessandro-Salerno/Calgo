/***********************************************************************
                            Calgo Flowchart builder
                        Copyright 2021 Alessandro Salerno

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***********************************************************************/


#include "headers/core.h"
#include <stdio.h>


int main(int argc, char* argv[])
{
    printf("Calgo Flowchart builder\nCopyright 2021 Alessandro Salerno\nDeveloped at: ITIS A. Avogadro, Torino\n\n");

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

    vector(token) toks  = lexerSegmentCode(code);
    vector(node)  nodes = parserParseTokens(toks); 

    for (int i = 0; i < toks->len; i++)
        printf("Type: %x \t Argument: %s \n", toks->buffer[i]->type, toks->buffer[i]->argument);
    
    printf("\n");

    for (int i = 0; i < nodes->len; i++)
    {
        printf("Type: %x \t Arguments: ", nodes->buffer[i]->type);

        for (int j = 0; j < nodes->buffer[i]->arguments->len; j++)
            printf("%s / ", nodes->buffer[i]->arguments->buffer[j]);

        printf("\n");
    }

    return 0;
}
