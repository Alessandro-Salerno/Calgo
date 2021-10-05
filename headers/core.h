#ifndef MODULE_X
#define MODULE_X

#include "..\headers\token.h"
#include "..\headers\node.h"
#include "..\headers\vector.h"


_vectorDefineType(token)
vector(token) lexerSegmentCode(string code);
#endif
