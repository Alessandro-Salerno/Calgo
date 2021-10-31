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


#include "../headers/calgo.h"
#include "../headers/table.h"


void calgoShowHelpPage()
{
    printf("      COMMAND  ARGUMENT  DESCRIPTION: \n");
    printf("Calgo  parse     file    | Parses the file and outputs the result \n");
    printf("Calgo  bench     file    | Parses the file 1000 times and prints the time taken \n");
    printf("Calgo  draw      file    | Draws the variable table (for now) \n");

    exit(0);
}


string calgoLoadFile(string path)
{
    FILE* file = fopen(path, "r");

    if (file == NULL)
    {
        printf("Error: Invalid file path '%s': No such file.\n", path);
        exit(-2);
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // This limits the size of the code to 1024 byts
    string code = Str("");
    size_t ret  = fread(code, 1, fsize, file);
    fclose(file);

    // Gotta figure out why this doesn't wor on Windows
#ifndef WIN32
    if (ret < fsize)
    {
        printf("Error: File read operation failed. Read %li of %li. \n", ret, fsize);
        exit(-7);
    }
#endif

    return code;
}


vector(node) calgoParse(string code)
{
    vector(node) nodes = lexerRun(code);

    for (int i = 0; i < nodes->len; i++)
    {
        printf("Type: 0x0%x \t Arguments: ", nodes->buffer[i]->type);

        for (int j = 0; j < nodes->buffer[i]->arguments->len; j++)
            printf("%s | ", nodes->buffer[i]->arguments->buffer[j]);

        printf("\n");
    }

    return nodes;
}


vector(node) calgoBenchmark(string code)
{
    vector(node) nodes;
    
    clock_t t;
    t = clock();

    for (int i = 0; i < 1000; i++)
        nodes = lexerRun(code); 

    t = clock() - t;
    printf("Time taken: %f ms \n", (double)(t / (CLOCKS_PER_SEC / 1000)));
    
    exit(0);
    return nodes;
}


void calgoDrawTable(vector(node) nodes)
{
    table tab = Table(3);

    tabPush(tab, "NAME", "TYPE", "DEFINITION");

    for (int i = 0; i < nodes->len; i++)
    {
        string name  = "",
               type  = "",
               value = Str("(undefined)");

        if (nodes->buffer[i]->type != CALGO_DECLARE_NODE)
            continue;

        type = nodes->buffer[i]->arguments->buffer[1];
        name = nodes->buffer[i]->arguments->buffer[2];

        if (nodes->buffer[i]->arguments->len == 3)
            goto tab_push;

        
        if (strCompare(nodes->buffer[i]->arguments->buffer[3], "STR"))
            sprintf(value, "\"%s\"", nodes->buffer[i]->arguments->buffer[4]);

        else if (strCompare(nodes->buffer[i]->arguments->buffer[3], "EXP"))
        {
            value = strClear(value);

            for (int j = 3; j < nodes->buffer[i]->arguments->len; j++)
            {
                if (strCompare(nodes->buffer[i]->arguments->buffer[j], "EXP"))
                    sprintf(value, "%s %s", value, "(");

                else if (strCompare(nodes->buffer[i]->arguments->buffer[j], "/EXP"))
                    sprintf(value, "%s %s", value, ")");

                else if (strCompare(nodes->buffer[i]->arguments->buffer[j], "STR"))
                {
                    j++;
                    sprintf(value, "%s \"%s\"", value, nodes->buffer[i]->arguments->buffer[j]);
                }
                
                else
                    sprintf(value, "%s %s", value, nodes->buffer[i]->arguments->buffer[j]);
            }
        }
        
        else
            value = nodes->buffer[i]->arguments->buffer[3];

        tab_push:
            tabPush(tab, name, type, value);
    }

    tabDraw(tab);
}
