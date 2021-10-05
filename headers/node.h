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


#ifndef NODE_H
#define NODE_H

    #include "..\headers\token.h"
    #include "..\headers\ntypes.h"


    typedef struct
    {
        node_t         type;
        vector(string) arguments;
    } _Node;

    typedef _Node* node;
    _vectorDefineType(node)

    typedef struct
    {
        vector(node) main;
        vector(node) brach1;
        vector(node) branch2;
    } _Block;

    typedef _Block* block;
    _vectorDefineType(block)

#endif
