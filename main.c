/***********************************************************************
                            Calgo Flowchart builder
                   Copyright 2021 - 2022 Alessandro Salerno

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


#include "headers/calgo.h"
#include "headers/render.h"
#include <stdio.h>
// You're about to read some of the worst code in your life. Be ware. 


int main(int argc, char* argv[])
{
    string code;
    printf("Calgo Flowchart builder\nCopyright 2021 - Alessandro Salerno\nDeveloped at: ITIS A. Avogadro, Torino\n\n");

    if (argc == 1)
    {
        printf("Insufficient number of arguments. Use argument 'help'\n");
        return -1;
    }

    switch (argc)
    {
        case 2:
            if (strCompare(argv[1], "help"))
                calgoShowHelpPage();

            break;

        case 3:
            code = calgoLoadFile(argv[2]);

            if (strCompare(argv[1], "parse"))
                calgoParse(code);

            if (strCompare(argv[1], "bench"))
                calgoBenchmark(code);

            if (strCompare(argv[1], "draw"))
                calgoDrawTable(calgoParse(code));

            break;

        default:
            printf("Error: Invalid command '%s' with argument count of %d \n", argv[1], argc);
            return -4;
    }

    return 0;
}
