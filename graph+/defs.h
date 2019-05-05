//
// Created by lugt on 2019/5/5.
//

#ifndef GRAPH_DEFS_H
#define GRAPH_DEFS_H

//
// Created by lugt on 2018/11/6.
//

// Kruskal

// Prim

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include "memory.h"
#include <cstring>

// STL Includings
using std::cout;
using std::cin;
using std::cout;
using std::cin;
using std::endl;

#define Is_Echo(cond, parm) if(cond) printf parm;
#define Is_True(cond, parm) /*if(!(cond)) {printf parm; getchar(); getchar(); getchar(); exit(1);}*/

typedef int                    INT;
typedef unsigned int           UINT;
typedef long long int          INT64;
typedef bool                   BOOL;
typedef long long unsigned int UINT64;
typedef double                 F8;
typedef char                   CHAR;
typedef char*                  CHPTR;
typedef char**                 CHPPTR;
typedef const char*            CCHPTR;
typedef const char**           CCHPPTR;

/*printf parm; getchar(); getchar(); getchar(); exit(1);*/
#define EXTERN extern
#define NULLPTR NULL
#define FALSE ((BOOL) 0)
#define TRUE  ((BOOL) 1)

inline BOOL Echo(){
  return FALSE;
}

inline BOOL EchoKrusKal() {
  return FALSE;
}

#endif //GRAPH_DEFS_H
