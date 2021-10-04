#include <malloc.h>
#include <string.h>
#include "..\headers\string.h"


string Str(string text)
{
    string str = calloc(1024, 1);

    for (int i = 0; i < strlen(text); i++)
        str[i] = text[i];

    return str;
}


string strJoin(string str1, string str2)
{
    string str = calloc(strlen(str1) + strlen(str2), 1);
    int i, j;

    for (i = 0; i < strlen(str1); i++)
        str[i] = str1[i];

    for (j = 0; j < strlen(str2); j++)
    {
        str[i] = str2[j];
        i++;
    }

    return str;
}


string strPushChar(string str, char chr)
{
    string new_str = Str(str);
    new_str[strlen(new_str)] = chr;

    return new_str;
}

strings strSplit(string text, char chr)
{
    text = strJoin(text, &chr);

    int     initial  = strlen(text);
    int     capacity = initial;

    strings list     = calloc(capacity, 1);
    string  buffer   = calloc(capacity, 1);

    int     length   = 0;
    int     index    = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == chr)
        {
            list[length] = buffer;
            buffer       = calloc(capacity, 1);
            index        = 0;
            length++;

            continue;
        }

        buffer[index] = text[i];
        index++;
    }

    free(buffer);
    return list;
}


int strCount(string text, char chr)
{
    int times = 0;

    for (int i = 0; i < strlen(text); i++)
        if (text[i] == chr)
            times++;

    return times;
}


bool strCompare(string a, string b)
{
    if (strlen(a) != strlen(b))
        return false;

    for (int i = 0; i < strlen(a); i++)
        if (a[i] != b[i])
            return false;

    return true;
}
