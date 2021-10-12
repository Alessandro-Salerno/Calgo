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
#include <time.h>
// You're about to read some of the worst code in your life. Be ware. 


void mainShowHelpPage()
{
    printf("      COMMAND  ARGUMENT  DESCRIPTION: \n");
    printf("Calgo  parse     file    | Parses the file and outputs the result \n");
    printf("Calgo  bench     file    | Parses the file 1000 times and prints the time taken \n");
    // GONNA ADD IT LATER: printf("Calgo  draw      file    | Draws the variable table (for now) \n");

    exit(0);
}


string mainLoadFile(string path)
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

    string code = Str("");
    fread(code, 1, fsize, file);
    fclose(file);

    return code;
}


vector(node) mainParse(string code)
{
    vector(node) nodes = lexerRun(code);

    for (int i = 0; i < nodes->len; i++)
    {
        printf("Type: %x \t Arguments: ", nodes->buffer[i]->type);

        for (int j = 0; j < nodes->buffer[i]->arguments->len; j++)
            printf("%s | ", nodes->buffer[i]->arguments->buffer[j]);

        printf("\n");
    }

    exit(0);
    return nodes;
}


vector(node) mainBenchmark(string code)
{
    vector(node) nodes;
    
    clock_t t;
    t = clock();

    for (int i = 0; i < 1000; i++)
        nodes = lexerRun(code); 

    t = clock() - t;
    printf("Time taken: %f ms \n", (double)(t));
    
    exit(0);
    return nodes;
}


int main(int argc, char* argv[])
{
    printf("Calgo Flowchart builder\nCopyright 2021 Alessandro Salerno\nDeveloped at: ITIS A. Avogadro, Torino\n\n");

    if (argc == 1)
    {
        printf("Insufficient number of arguments. Use argument 'help'\n");
        return -1;
    }

    if (argc == 2)
        if (strCompare(argv[1], "help"))
            mainShowHelpPage();

    string code = mainLoadFile(argv[2]);
    
    if (argc == 3)
        if (strCompare(argv[1], "parse"))
            mainParse(code);
        else if (strCompare(argv[1], "bench"))
            mainBenchmark(code);

    printf("Error: Invalid command '%s' \n", argv[1]);
    return -4;
}
