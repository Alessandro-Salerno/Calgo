#include <stdlib.h>


#define _vectorDefineType(type) \
    typedef struct \
    { \
        type* buffer; \
        size_t size; \
        size_t len; \
    } _Vector_##type; \
    \
    _Vector_##type* _vectorNew_##type(size_t size) \
    { \
        _Vector_##type* new_vector = malloc(sizeof(_Vector_##type)); \
        new_vector->buffer         = calloc(sizeof(type), size); \
        new_vector->size           = size; \
        new_vector->len            = 0; \
        return new_vector; \
    } \
    \
    void _vectorPush_##type(_Vector_##type* self, type item) \
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
