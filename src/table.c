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


#include "../headers/table.h"
#include <string.h>


table Table(int colums)
{
    vector(string) buff      = Vec(string, 128);
    table          new_table = malloc(sizeof(_Table));

    new_table->colums = colums;
    new_table->buffer = buff;

    return new_table;
}


void tabPush(table tab, string text, ...)
{
    va_list arguments;
    va_start(arguments, text);
    vecPush(string, tab->buffer, text);

    for (int i = 0; i < tab->colums - 1; i++)
    {
        string argument = va_arg(arguments, string);
        vecPush(string, tab->buffer, argument);
    }
    
    va_end(arguments);
}


int tabFindMaxLengthInColum(table tab, int colum)
{
    int maxlen = 0,
        curlen = 0;

    for (int i = colum; i < tab->buffer->len; i += tab->colums)
    {
        curlen = strlen(tab->buffer->buffer[i]);

        if (i == 0 | curlen > maxlen)
            maxlen = curlen;
    }

    return maxlen;
}


void tabDrawTopBorder(table tab)
{
    printf("\n+");

    for (int i = 0; i < tab->colums; i++)
    {
        for (int j = 0; j < tabFindMaxLengthInColum(tab, i) + 2; j++)
            printf("-");

        printf("+");
    }
}


void tabDrawTextRow(table tab, int row)
{
    int startidx = tab->colums * row;

    printf("\n|");

    for (int i = 0; i < tab->colums; i++)
    {
        int curidx = startidx + i,
            maxlen = tabFindMaxLengthInColum(tab, i),
            curlen = strlen(tab->buffer->buffer[curidx]),
            empty  = maxlen - curlen + 1;

        printf(" %s", tab->buffer->buffer[curidx]);

        for (int j = 0; j < empty; j++)
            printf(" ");

        printf("|");
    }
}


void tabDraw(table tab)
{
    tabDrawTopBorder(tab);

    for (int i = 0; i < tab->buffer->len / tab->colums; i++)
    {
        tabDrawTextRow(tab, i);
        tabDrawTopBorder(tab);
    }

    printf("\n");
}
