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


#include "../headers/string.h"
#include <stdlib.h>
#include <string.h>


string _Str(string str, string text)
{
    for (int i = 0; !strIsNullChar(text, i); i++)
        str[i] = text[i];

    return str;
}


string Strs(string text, size_t size)
{
    string str = calloc(size, 1);
    return _Str(str, text);
}


string Str(string text)
{
    return Strs(text, 1024);
}


string strJoin(string str1, string str2)
{
    int len1   = strlen(str1),
        len2   = strlen(str2);

    string str = Strs(str1, len1 + len2);
    int    i   = len1 - 1,
           j   = 0;

    for (; j < len2; j++)
    {
        str[i] = str2[j];
        i++;
    }

    return str;
}


void strPushChar(string str, char chr)
{
    str[strlen(str)] = chr;
}

vector(string) strSplit(string text, char chr)
{
    strPushChar(text, chr);
    
    string buffer       = Str("");
    vector(string) list = Vec(string, strCount(text, chr) * 2);

    for (int i = 0; !strIsNullChar(text, i); i++)
    {
        if (text[i] == chr)
        {
            vecPush(string, list, buffer);
            buffer = Str("");

            continue;
        }

        strPushChar(buffer, text[i]);
    }

    return list;
}


int strCount(string text, char chr)
{
    int times = 0;

    for (int i = 0; !strIsNullChar(text, i); i++)
        if (text[i] == chr)
            times++;

    return times;
}


bool strCompare(string a, string b)
{
    if (strlen(a) != strlen(b))
        return false;

    for (int i = 0; !strIsNullChar(a, i); i++)
        if (a[i] != b[i])
            return false;

    return true;
}


bool strIsNullChar(string  str, int index)
{
    return str[index] == '\0';
}


string strClear(string str)
{
    for (int i = 0; !strIsNullChar(str, i); i++)
        str[i] = '\0';

    return str;
}
