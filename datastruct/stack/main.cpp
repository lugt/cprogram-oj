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
  return TRUE;
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

UINT64 Str_Push(STLSTK *list, CCHPTR str){
  UINT64          i       = 0;
  UINT64          len     = strlen(str);
  for(i = 0; i < len; i++){
    list->push(str[i]);
  }
  return len;
}

void  Str_Print(STLSTK * list, UINT64 len){
  UINT64          i       = 0;
  for(i = 0 ; i < len ; i++ ){
    CHAR  st = list->top();
    list->pop();
    std::cout << st;
  }
  std::cout << std::endl;
}

INT Str_Check(STRING str, UINT max){
  for(INT i = 0; i < str.size() ; i++){
    if(str[i] > '0' + max){
      return -1;
    }
  }
  return 0;
}

STRING outstr = "";

INT Str_Sequence_Check (STLSTK * orig, CCHPTR in,  UINT64 len, CCHPTR out){

  std::stringstream sstr;

  Is_Print(Printing(), (" Seq Check, [lhs] = %lu  [rhs] = %s,\n", len, out));

  UINT64          i        = 0;
  UINT64          cur_in   = 0;
  UINT64          cur_out  = 0;

  while (len > 0 && cur_in != len){

    Is_Print(Printing(),
             (" [Seq_Check]::[while] again, cur_in : %ld, cur_out: %ld\n", cur_in, cur_out));

    Is_Print(Printing(),
             (" [Seq_Check]::[pushing] : %d \n", in[cur_in]));

    orig->push(in[cur_in++]);
    sstr << "in\n" ;

    CHAR    st   = orig->top();

    Is_Print(Printing(),
      (" [Seq_Check]::while-check: out[%lu] <%c> == st:<%c> \n", cur_out, out[cur_out], st));

    while(out[cur_out] == st){
      Is_Print(Printing(),
               (" [Seq_Check]::popping : cur_in:%lu, cur_out:%lu, to_pop:%d, stack_size:%ld \n",
                 cur_in, cur_out, orig->top(), orig->size()));
      orig->pop();
      if(!orig->empty()) {
        st       = orig->top();
        Is_Print(Printing(),
                 (" [Seq_Check]::inside-while-new-top, top:%c, size:%ld\n", st, orig->size()));
      }else{
        st = '$';
      }
      cur_out++;
      sstr << "out\n" ;

      if(cur_out >= len){
        Is_Print(Printing(),
                 (" [Seq_Check]::out-finished in:%lu, out:%lu \n", cur_in, cur_out));
        break;
      }


      Is_Print(Printing(),
               (" [Seq_Check]::inside-while-check: out[%lu] <%c> == st:<%c> \n", cur_out, out[cur_out], st));
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
  INT             num      = 0;
  INT             direct   = 0;
  INT             diff     = 0;
  CHAR            ch       = 0;
  STLSTK          my, out;
  CHPTR           chbuf    = new char[10000];
  BOOL            failed   = FALSE;
  INT             pos      = 0;

#if 0
  length          =       Str_Push(&my, "something");
  Is_Print(Printing(), ("sizeof(LNODE)  == %d \n", sizeof(LNODE)));
#endif

  std::cin        >>  n;
  while(n--){

    memset(chbuf, 0, sizeof(char) * 10000);
    std::cin.getline(chbuf, 2000);

    pos           =   0;
    p             =   (INT) (strlen(chbuf));
    ch            =   chbuf[pos];
    diff          =   0;

    if(p == 0) {
      n++;
      continue;
    }

    pos++;
    Is_Print(Printing(), (" readline : == %s \n", chbuf));

    while(ch != EOF && ch != '\n') {
      if(ch == '{' || ch == '[' || ch == '('){
        Is_Print(Printing(), (" [main]::push, ch=%c, stack-size:%ld, pos:%d\n", ch, my.size(), pos));
        my.push(ch);
      }else if(ch == '}' || ch == ']' || ch == ')'){
        if(!my.empty()){
          Is_Print(Printing(), (" [main]::check not-empty, ch=%c, pos:%d\n", ch, pos));
          if(my.top() == Get_counter(ch)){
            Is_Print(Printing(), (" [main]::check fit, stack-top:%c\n", my.top()));
            my.pop();
          }else{
            Is_Print(Printing(), (" [main]::not-fit because of missing lhs, stack-top:%c\n", my.top()));
            my.push(Get_counter(ch));
            my.pop();
            diff ++;
          }
        }else {
          Is_Print(Printing(), (" [main]::not-fit because of missing lhs, stack-top:%c\n", my.top()));
          my.push(Get_counter(ch));
          my.pop();
          diff ++;
        }
      }
      if(pos >= p) {
        Is_Print(Printing(), (" [main]::str finished for check\n"));
        break;
      }
      ch = (CHAR) chbuf[pos++];
    }
    Is_Print(Printing(), (" [main]::calculating diff, my.size=:%ld\n", my.size()));
    diff += my.size();
    std::cout << diff << "\n";
    if(Printing()) {
      if (!failed && my.size() == 0) {
        std::cout << "0\n";
      } else {
        std::cout << "error\n";
      }
    }
    my = * new STLSTK();
  }

  getchar();
  getchar();
  return 0;
}