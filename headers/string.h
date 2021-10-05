#ifndef STRING_H

#define STRING_H
#include <stdbool.h>


typedef char* string;
typedef string* strings;

string Str(string text);
string strJoin(string str1, string str2);
string strPushChar(string str, char chr);
strings strSplit(string text, char chr);
int strCount(string text, char chr);
bool strCompare(string a, string b);

#endif
