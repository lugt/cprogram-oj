//
// Created by lugt on 2019/5/5.
//

#include "defs.h"
#include "xiaoxiaole.h"

INT main (INT args, CHPPTR argv) {

  // Generate Random Assemble
  // +Refine Assemble
  INT width = 10;
  INT height = 10;
  Create_rectangle(width, height);

  // Start of Reduction Process

}

REDUCTION_RESULT Reduce_assemble(ASSEMBLE *assemble) {

}


CROSS_NODE *Create_rectangle(INT width, INT height) {
  return (CROSS_NODE *) Cross_malloc(width * height * sizeof(CROSS_NODE));
}


//=============================================================================
//
//  Memory Status Save
//
//=============================================================================
void Cross_memory_push() {
  // Create a queue
}

//=============================================================================
//
//  Memory Status Restore
//
//=============================================================================
void Cross_memory_pop() {
  // free();
}

//=============================================================================
//
//  Memory Allocate New Portion of memory
//
//=============================================================================
void *Cross_malloc(INT size) {
  return malloc(size);
}