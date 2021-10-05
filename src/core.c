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


#include "..\headers\core.h"
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
    int           len        = strlen(code);
    vector(token) list       = Vec(token, 50000);
    
    for (int i = 0; i < len; i++)
    {
        if (code[i] != ' ' & code[i] != ';' & code[i] != '\n' & code[i] != '\t' & code[i] != '\r')
            strPushChar(buffer, code[i]);
        
        else if (code[i] == ' ' & !strCompare(buffer, "") | code[i] == ';')
        {
            token_t toktype;
            for (toktype = 0; !strCompare(buffer, keywords[toktype]) & toktype <= CALGO_STOP_TOKEN - CALGO_START_TOKEN; toktype++)
                continue;

            if (toktype >= CALGO_STOP_TOKEN)
                lexerThrowFatalError("Invalid keyword found.", -3);

            buffer = strClear(buffer);

            for (; code[i] != ';'; i++)
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


vector(block) parserParseTokens(vector(token) toks)
{
}
