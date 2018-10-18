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


template<typename T>
class Stacks{
  std::stack<T> stlist;
};

template<typename T2>
struct ListNode{
  int        pos;
  ListNode  *head;
  ListNode  *next;
  union {
    INT   *intData;
    void  *voidData;
    CHPTR  charData;
    T2    *tData;
    UINT uintData;
  } kid;
};

//typedef       ListNode<INT>       LNODE;
typedef         CHAR                LNODE;
typedef         std::stack<LNODE>   STLSTK;


typedef struct Node {
  int num;
  struct Node *next;
  struct Node *prev;
} LinkList;

LinkList * Create_list(INT n, INT shift) {

  LinkList      *head   = new LinkList[n];
  INT            i      = 1;

  for (i = 0; i < n; i++) {
    if(i   !=   n - 1) {
      head[i].next = &head[i + 1];
    }else{
      head[i].next = &head[0];
    }

    if(i   !=   0) {
      head[i].prev = &head[i - 1];
    }else{
      head[i].prev = &head[n - 1];
    }

    head[i].num         = (shift  + i ) % n;
    if(head[i].num  == 0){
      head[i].num       = n;
    }
  }
  return head;
}

void Checkout_list(LinkList *L, INT m)
{
  INT i;
  LinkList *p, *q, *lhs, *rhs;
  p = L;
  while (p->next != p) {
    for (i = 1; i < m; i++)
    {
      p   = p->next;
    }
    printf("%d ", p->num);
    lhs       = p->prev;
    rhs       = p->next;
    Is_Print(Printing(), ("[Checkout_list] removing ofst:%8d, %3d <- [%3d] -> %3d\n",
      (INT)(p-L), lhs->num, p->num, rhs->num));
    lhs->next = rhs;
    rhs->prev = lhs;
    p         = rhs;
  }
  printf("%d \n", p->num);
}

INT main() {

  INT         trials   = 100;
  INT         total_num, first_num, period_num;
  LinkList   *L;

  while (trials > 0){
    if(!(std::cin      >> total_num)){
      return 0;
    }
    std::cin
                       >> period_num
                       >> first_num;
    L                  =  Create_list(total_num, first_num);
    Checkout_list(L, period_num);
  }
  return 0;
}