//
// Created by lugt on 2019/5/5.
//

#ifndef GRAPH_XIAOXIAOLE_H
#define GRAPH_XIAOXIAOLE_H

#include "defs.h"


typedef struct Assemble_t {

} ASSEMBLE;

typedef struct Reduction_t {

} REDUCTION_RESULT;

/*******************************************************************
 *
 *  Reduction Context
 *  Origin Assemble, Path, History Score
 *
 ******************************************************************/
typedef struct Reduction_ctx_t {

} REDUCTION_CTX;

typedef INT    CROSS_NODE;

EXTERN INT main (INT args, CHPPTR argv);
EXTERN void *Cross_malloc(INT size);
EXTERN REDUCTION_RESULT Reduce_assemble(ASSEMBLE *assemble);
EXTERN CROSS_NODE *Create_rectangle(INT width, INT height);
EXTERN void Cross_memory_push();
EXTERN void Cross_memory_pop();

#endif //GRAPH_XIAOXIAOLE_H
