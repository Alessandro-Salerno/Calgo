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
        CALGO_START_TOKEN   = 0xB00,
        CALGO_OUTPUT_TOKEN  = 0xB01,
        CALGO_INPUT_TOKEN   = 0xB02,
        CALGO_DECLARE_TOKEN = 0xB03,
        CALGO_SET_TOKEN     = 0xB04,
        CALGO_IF_TOKEN      = 0xB05,
        CALGO_ELSE_TOKEN    = 0xB06,
        CALGO_END_TOKEN     = 0xB07,
        CALGO_FOR_TOKEN     = 0xB08,
        CALGO_WHILE_TOKEN   = 0xB09,
        CALGO_STOP_TOKEN    = 0xB09 + 1
    } token_t;

#endif
