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


#ifndef NTYPES_H
#define NTYPES_H

    typedef enum
    {
        CALGO_OUTPUT_NODE  = 0xA00,
        CALGO_INPUT_NODE   = 0xA01,
        CALGO_DECLARE_NODE = 0xA02,
        CALGO_SET_NODE     = 0xA03,
        CALGO_IF_NODE      = 0xA04,
    } node_t;

#endif
