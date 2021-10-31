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


#ifndef TABLE_H
#define TABLE_H

    #include "../headers/calgo.h"
    #include <stdarg.h>


    typedef struct
    {
        int            colums;
        vector(string) buffer;
    } _Table;

    typedef _Table* table;

    table Table                   (int   colums                 );
    void  tabPush                 (table tab,   string, ...     );
    int   tabFindMaxLengthInColum (table tab,   int    colum    );
    void  tabDrawTopBorder        (table tab                    );
    void  tabDrawTextRow          (table tab,   int    row      );
    void  tabDraw                 (table tab                    );

#endif
