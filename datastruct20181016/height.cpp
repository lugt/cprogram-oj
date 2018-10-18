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
#include <map>

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

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::stack;


inline BOOL Printing(){
  return FALSE;
}

INT compare_int(const void* lhs, const void *rhs){
  return *((INT *)lhs) - *((INT *)rhs);
}


typedef struct BiTreeNode {
  struct BiTreeNode   *_parent;
  struct BiTreeNode   *_lhs;
  struct BiTreeNode   *_rhs;
  UINT                 height;
  UINT                 ch_count;
} BiTreeNodeT;

class BiTree{
private:
  std::vector<BiTreeNodeT *> nodes;

public:
  BiTreeNodeT * Remove_Node(BiTreeNodeT *){}
  BiTreeNodeT * Add_Node(UINT val){
    BiTreeNodeT *node = new BiTreeNodeT();
    node->_lhs = NULL;
    node->_rhs = NULL;
    node->height = 0;
    node->ch_count = 0;
    node->_parent = NULL;
    nodes.push_back(node);
    return node;
  }
};

INT main() {

  INT                     trials, count , num;
  std::string             type;
  BiTree                  tree_1;

  std::cin    >> trials;
  for(UINT i = 0; i < trials; i++) {
    std::cin >> count;
    for(UINT t = 0; t < count ; t++){
      cin >> num;
      tree_1.Add_Node(num);
    }
    /**
     * 样例输入
      3
      3 1 2 3
      5 1 2 3 0 4
      13 1 2 3 4 0 5 6 7 8 0 0 9 10
      样例输出
      1 2 3
      1 2 4 3
      1 2 4 7 8 3 5 9 10 6
     * */
    //.push(type);
  }
  return 0;
}