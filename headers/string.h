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


#ifndef STRING_H
#define STRING_H

    #include "..\headers\vector.h"
    #include <stdbool.h>


    typedef char* string;
    _vectorDefineType(char)
    _vectorDefineType(string)

    string         _Str        (string str , string text);
    string         Strs        (string text, size_t size);
    string         Str         (string text             );
    string         strJoin     (string str1, string str2);
    void           strPushChar (string str , char   chr);
    vector(string) strSplit    (string text, char   chr);
    int            strCount    (string text, char   chr);
    bool           strCompare  (string a   , string b  );
    string         strClear    (string str             );

#endif
