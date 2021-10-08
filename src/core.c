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


vector(token) lexerSegmentCode(string code)
{
    string        keywords[] = {
                        "MAIN",
                        "OUTPUT",
                        "INPUT",
                        "DECLARE",
                        "SET",
                        "IF",
                        "ELSE",
                        "END",
                        "FOR",
                        "WHILE"
                    };

    string        buffer     = Str("");
    vector(token) list       = Vec(token, 50000);
    
    for (int i = 0; !strIsNullChar(code, i); i++)
    {
        if (isalpha(code[i]) | isdigit(code[i]))
            strPushChar(buffer, code[i]);
        
        else if (!strCompare(buffer, ""))
        {
            token_t toktype = 0;
            while (!strCompare(buffer, keywords[toktype]) & toktype <= CALGO_STOP_TOKEN - CALGO_START_TOKEN)
                toktype++;

            if (toktype >= CALGO_STOP_TOKEN)
                lexerThrowFatalError("Invalid keyword found.", -3);

            buffer = strClear(buffer);

            for (; code[i] != ';' & code[i + 1] != '\n'; i++)
                strPushChar(buffer, code[i]);

            token new_token = Token();
            new_token->argument = Str(buffer);
            new_token->type = CALGO_START_TOKEN + toktype;
            
            vecPush(token, list, new_token);
            buffer = strClear(buffer);
        }
    }

    return list;
}


vector(node) parserParseTokens(vector(token) toks)
{
    // WARNING: Code has been improved, but is still pretty bad.
    // Gonna fix it later
    
    string       buffer = Str("");
    vector(node) list   = Vec(node, toks->len);

    for (int i = 0; i < toks->len; i++)
    {
        token tok      = toks->buffer[i];

        node new_node  = Node();
        new_node->type = tok->type;
        vecPush(string, new_node->arguments, tok->argument);

        strPushChar(tok->argument, ' ');

        for (int j = 0; !strIsNullChar(tok->argument, j); j++)
        {
            #define argchr tok->argument[j]

            if (argchr == ' ' | argchr == ',' | argchr == '(' | argchr == ')')
            {
                if (!strCompare(buffer, ""))
                    vecPush(string, new_node->arguments, Str(buffer));
                
                buffer = strClear(buffer);
            }

            switch (argchr)
            {
                case ' ':
                    break;

                case '"':
                    strPushChar(buffer, '"');

                    j++;
                    for (; argchr != '"'; j++)
                        strPushChar(buffer, argchr);

                    strPushChar(buffer, '"');
                    break;

                case ',':
                    vecPush(string, new_node->arguments, Str("COMMA"));
                    break;

                case '(':
                    vecPush(string, new_node->arguments, Str("EXP"));
                    break;

                case ')':
                    vecPush(string, new_node->arguments, Str("/EXP"));
                    break;

                default:
                    strPushChar(buffer, tok->argument[j]);
                    break;
            }
        }

        vecPush(node, list, new_node);
        buffer = strClear(buffer);
    }

    return list;
}


vector(block) parserParseNodes(vector(node) nodes)
{
}
