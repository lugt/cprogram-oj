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

#define         SIZE_K_MAX    100000
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
 

typedef         CHAR                LNODE;
typedef         std::stack<LNODE>   STLSTK;
 
UINT64 Str_Push(STLSTK *list, CCHPTR str){
  UINT64          i       = 0;
  UINT64          len     = strlen(str);
  for(i = 0; i < len; i++){
    list->push(str[i]);
  }
  return len;
}

STRING outstr = "";
 
INT Str_Sequence_Check (STLSTK * orig, CCHPTR in,  UINT64 len, CCHPTR out){
 
  std::stringstream sstr;
 
  UINT64          i        = 0;
  UINT64          cur_in   = 0;
  UINT64          cur_out  = 0;
 
  while (len > 0 && cur_in != len){
    orig->push(in[cur_in++]);
    sstr << "in\n" ;
 
    CHAR    st   = orig->top();
 
    while(out[cur_out] == st){
      orig->pop();
      if(!orig->empty()) {
        st       = orig->top();
      }else{
        st = '$';
      }
      cur_out++;
      sstr << "out\n" ;
 
      if(cur_out >= len){
        break;
      }
 
     }
  }
 
  outstr = sstr.str();
  if(cur_out < len) return -1;
  return 0;
 
}
 
CHAR Get_counter(CHAR in){
  switch(in){
    case '{':
      return '}';
 
    case '[':
      return ']';
 
    case '(':
      return ')';
 
    case '}':
      return '{';
 
    case ']':
      return '[';
 
    case ')':
      return '(';
 
    default:
      return '\n';
  }
}
 
//=============================================================================
// Main Entry
// @param INT argc
//=============================================================================
int main(INT argc, CHPPTR argv) {
 
  INT             n        = 0;
  INT             p        = 0;
  INT             diff     = 0;
  CHAR            ch       = 0;
  STLSTK         *my;
  CHPTR           chbuf    = new char[SIZE_K_MAX];
  INT             pos      = 0;
 
#if 0
  length          =       Str_Push(&my, "something");
  Is_Print(Printing(), ("sizeof(LNODE)  == %d \n", sizeof(LNODE)));
#endif
 
  std::cin        >>  n;
  while(n--){
 
    memset(chbuf, 0, sizeof(char) * SIZE_K_MAX);
    std::cin.getline(chbuf, 2000);
 
    pos           =   0;
    p             =   (INT) (strlen(chbuf));
    ch            =   chbuf[pos];
    diff          =   0;
    my            =   new STLSTK();
    pos++;
    while(ch != EOF && ch != '\n') {
      if(ch == '{' || ch == '[' || ch == '('){
        my->push(ch);
      }else if(ch == '}' || ch == ']' || ch == ')'){
        if(!my->empty()){
          if(my->top() == Get_counter(ch)){
            my->pop();
          }else{
            my->push(Get_counter(ch));
            my->pop();
            diff ++;
          }
        }else {
          my->push(Get_counter(ch));
          my->pop();
          diff ++;
        }
      }
      if(pos >= p) {
        break;
      }
      ch = (CHAR) chbuf[pos++];
    }
    diff += my->size();
    std::cout << diff << "\n";
  }
 
  getchar();
  getchar();
  return 0;
}