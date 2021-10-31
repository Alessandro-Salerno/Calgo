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


#include "../headers/core.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


void lexerThrowFatalError(string err, int ecode)
{
    printf("Error: %s \n", err);
}


vector(node) lexerRun(string code)
{
    string        keywords[] = {
                        "Main",
                        "Output",
                        "Input",
                        "Declare",
                        "Set",
                        "If",
                        "Else",
                        "End",
                        "For",
                        "While"
                    };

    string        buffer     = Str("");
    vector(node)  list       = Vec(node, 512);
    int           previdx    = 0;
    
    for (int i = 0; !strIsNullChar(code, i); i++)
    {
        if (isalpha(code[i]) | isdigit(code[i]))
        {
            strPushChar(buffer, code[i]);
            previdx = i;
        }
        
        else if (!strCompare(buffer, ""))
        {
            node_t ntype = 0;
            while (!strCompare(buffer, keywords[ntype]) & ntype <= sizeof(keywords) / sizeof(string))
                ntype++;

            buffer = strClear(buffer);

            while (code[i] == ' ') i++;
            for (; code[i] != ';' & code[i + 1] != '\n'; i++)
                strPushChar(buffer, code[i]);

            node new_node = (node) { .type = ntype };
            new_node.arguments = Vec(string, 16);
            vecPush(string, new_node.arguments, Strs(buffer, i - previdx + 3));
            lexerSplitArguments(new_node);
            
            vecPush(node, list, new_node);
            buffer = strClear(buffer);
        }
    }

    free(buffer);
    return list;
}


void lexerSplitArguments(node n)
{
    string buffer  = Str("");
    int    previdx = 0;

    for (int i = 0; !strIsNullChar(n.arguments->buffer[0], i); i++)
    {
        #define argchr n.arguments->buffer[0][i]

        if (argchr == ' ' | argchr == ',' | argchr == '(' | argchr == ')')
        {
            if (!strCompare(buffer, ""))
            {
                vecPush(string, n.arguments, Strs(buffer, i - previdx + 3));
                buffer = strClear(buffer);
                previdx = i;
            }
        }

        switch (argchr)
        {
            case ' ':
                break;

            case '"':
                vecPush(string, n.arguments, "STR");

                i++;
                for (; argchr != '"'; i++)
                    strPushChar(buffer, argchr);

                break;

            case ',':
                vecPush(string, n.arguments, "COMMA");
                break;

            case '(':
                vecPush(string, n.arguments, "EXP");
                break;

            case ')':
                vecPush(string, n.arguments, "/EXP");
                break;

            default:
                strPushChar(buffer, argchr);
                break;
        }
    }

    if (!strCompare(buffer, "") && !strCompare(buffer, n.arguments->buffer[0]))
    {
        vecPush(string, n.arguments, buffer);
        return;
    }

    free(buffer);
}
