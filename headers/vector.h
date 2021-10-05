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


#ifndef VECTOR_H
#define VECTOR_H

    #include <stdlib.h>


    #define _vectorDefineType(type) \
        typedef struct \
        { \
            type* buffer; \
            size_t size; \
            size_t len; \
        } _Vector_##type; \
        \
        static _Vector_##type* _vectorNew_##type(size_t size) \
        { \
            _Vector_##type* new_vector = malloc(sizeof(_Vector_##type)); \
            new_vector->buffer         = calloc(sizeof(type), size); \
            new_vector->size           = size; \
            new_vector->len            = 0; \
            return new_vector; \
        } \
        \
        static void _vectorPush_##type(_Vector_##type* self, type item) \
        { \
            if (self->len + 1 >= self->size) \
            { \
                self-> size *= 2; \
                self->buffer = realloc(self->buffer, self->size); \
            } \
            self->buffer[self->len] = item; \
            self->len++; \
        }


    #define _Vector(type) \
        _Vector_##type

    #define vector(type) \
        _Vector(type)*

    #define Vec(type, size) \
        _vectorNew_##type(size);

    #define vecPush(type, self, item) \
        _vectorPush_##type(self, item);

#endif
