#include "..\headers\core.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


vector(token) lexerSegmentCode(string code)
{
    string buffer        = Str("");
    token  tok           = Token();
    vector(token) list   = Vec(token, 50000);
    
    for (int i = 0; i < strlen(code); i++)
    {
        if (code[i] != ' ' & code[i] != ';' & code[i] != '\n' & code[i] != '\t' & code[i] != '\r')
            buffer = strPushChar(buffer, code[i]);
        
        else if (code[i] == ' ' & !strCompare(buffer, "") | code[i] == ';')
        {
            if (strCompare(buffer, "OUTPUT"))
                tok->type = CALGO_OUTPUT_TOKEN;

            else if (strCompare(buffer, "INPUT"))
                tok->type = CALGO_INPUT_TOKEN;

            else if (strCompare(buffer, "DECLARE"))
                tok->type = CALGO_DECLARE_TOKEN;

            else if (strCompare(buffer, "SET"))
                tok->type = CALGO_SET_TOKEN;

            else if (strCompare(buffer, "IF"))
                tok->type = CALGO_IF_TOKEN;

            else if (strCompare(buffer, "ELSE"))
                tok->type = CALGO_ELSE_TOKEN;

            else if (strCompare(buffer, "END"))
                tok->type = CALGO_END_TOKEN;

            else if (strCompare(buffer, "FOR"))
                tok->type = CALGO_FOR_TOKEN;

            else if (strCompare(buffer, "WHILE"))
                tok->type = CALGO_WHILE_TOKEN;
            
            else
            {
                printf("Error: Invalid keyword %s", buffer);
                exit(-1);
            }

            free(buffer);
            buffer = Str("");

            while (code[i] != ';')
            {
                buffer = strPushChar(buffer, code[i]);
                i++;
            }

            tok->argument = Str(buffer);

            token new_token = Token();
            new_token->argument = tok->argument;
            new_token->type = tok->type;
            vecPush(token, list, new_token);

            free(buffer);
            buffer = Str("");
        }
    }

    return list;
}


blocks parserParseTokens(vector(token) toks)
{
}
