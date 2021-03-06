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

#ifndef CALGO_H
#define CALGO_H

    #include "../headers/core.h"
    #include <stdio.h>
    #include <time.h>


    void         calgoShowHelpPage (                  );
    string       calgoLoadFile     (string       path );
    vector(node) calgoParse        (string       code );
    vector(node) calgoBenchmark    (string       code );
    void         calgoDrawTable    (vector(node) nodes);

#endif
