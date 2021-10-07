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


#include "../headers/node.h"
#include <stdlib.h>


node Node()
{
    node new_node = malloc(sizeof(_Node));
    new_node->type = 0x00;
    new_node->arguments = Vec(string, 24);

    return new_node;
}


block Block()
{
    block new_block = malloc(sizeof(_Block));
    new_block->main = Vec(node, 1024);
    new_block->brach1 = Vec(node, 1024);
    new_block->brach1 = Vec(node, 1024);

    return new_block;
}
