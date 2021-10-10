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


#ifndef TTYPES_H
#define TTYPES_H

    typedef enum
    {
        CALGO_START_NODE   = 0x000,
        CALGO_OUTPUT_NODE  = 0x001,
        CALGO_INPUT_NODE   = 0x002,
        CALGO_DECLARE_NODE = 0x003,
        CALGO_SET_NODE     = 0x004,
        CALGO_IF_NODE      = 0x005,
        CALGO_ELSE_NODE    = 0x006,
        CALGO_END_NODE     = 0x007,
        CALGO_FOR_NODE     = 0x008,
        CALGO_WHILE_NODE   = 0x009,
        CALGO_STOP_NODE    = 0x009 + 1
    } node_t;

#endif
