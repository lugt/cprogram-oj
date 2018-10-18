//
// Created by xc5 on 23/9/2018.
//

#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>

#define         OK                    0
#define         FAIL                  1
#define         MAX_SIZE              10000
#define         NULLPTR               NULL
#define         TRUE                  true
#define         FALSE                 false

#define  Is_Print(cond, parm)  if(cond) printf parm


#define  Df_do_seq(a, b, c)              \
    std::cin        >> b;                \
    if(a.c(b - 1) >= 0){              \
        a.print();                       \
    }

#define  Df_do_dseq(a, b1, b2, c)        \
    std::cin        >> b1 >> b2;         \
    if(a.c(b1 - 1, b2) >= 0){             \
        a.print();                       \
    }

#define  Df_do_ddseq(a, b1, b2, c)        \
    std::cin        >> b1 >> b2;         \
    if(a.c(b1 - 1, b2 - 1) >= 0){             \
        a.print();                       \
    }

#define  Df_do_fseq(a, b1, b2, c)        \
    std::cin        >> b1 >> b2;         \
    if(a.c(b1, b2) >= 0){             \
        a.print();                       \
    }

typedef         char          CHAR;
typedef         int           INT;
typedef         long          INT64;
typedef         unsigned int  UINT;
typedef         unsigned long UINT64;
typedef         char**        CHPPTR;
typedef         char*         CHPTR;
typedef         const char*   CCHPTR;
typedef         bool          BOOL;
typedef         std::string   STRING;


INT compare_int(const void* lhs, const void *rhs);

inline BOOL Printing(){
  return FALSE;
}

INT compare_int(const void* lhs, const void *rhs){
  return *((INT *)lhs) - *((INT *)rhs);
}


typedef struct Node {
  int num;
  struct Node *next;
  struct Node *prev;
} LNODE;

INT main() {

  //std::queue<INT>         myq_a, myq_b, myq_c;
  INT                     count_ma = 0, count_mb =0, count_mc = 0;
  INT                     total_ma = 0, total_mb = 0, total_mc = 0;
  INT                     trials, i, num;
  std::string             type;
  std::queue<std::string> first;
  //std::queue<INT>         second;

  std::cin    >> trials;
  for(i = 0; i < trials; i++) {
    std::cin >> type;
    first.push(type);
  }
  for(i = 0; i < trials; i++) {
    std::cin >> num;
    type = first.front();
    first.pop();
    if(type == "A"){
      count_ma ++;
      total_ma += num;
    }else if(type == "B"){
      count_mb ++;
      total_mb += num;
    }else if(type == "C") {
      count_mc ++;
      total_mc += num;
    }
  }

  std::cout << (total_ma / count_ma) << std::endl
    << (total_mb / count_mb) << std::endl
    << (total_mc / count_mc) << std::endl;

  return 0;
}