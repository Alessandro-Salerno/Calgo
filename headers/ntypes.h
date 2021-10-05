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
