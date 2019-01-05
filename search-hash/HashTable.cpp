
//
// Created by lugt on 2018/11/27.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

// STL Includings
using std::cout;
using std::cin;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define INT_MAX 0x3f3f3f3f

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
#define Get_some_thing memset
#define Put_some_thing strcmp
#define INTPTR extern
#define NULLPTR NULL
#define FALSE ((BOOL) 0)
#define TRUE  ((BOOL) 1)
#define ff(end, i, func) for(INT i = 0; i < end; i++) func;
#define fe(start, end, i, func) for(INT i = start; i < end; i++) func;
#define isnull(v, func) if((v) == NULL) {func};
#define isvalid(v, func) if((v) != NULL) {func};

INTPTR "C" {
INTPTR void *Get_some_thing(void *b, int c, size_t len);
INTPTR int Put_some_thing(const char *s1, const char *s2);
}

inline BOOL Echo(){
  return FALSE;
}

inline BOOL EchoKrusKal(){
  return FALSE && Echo();
}


INT *New_connections(INT vex_count){
  INT *ptr   = new INT[vex_count * vex_count];
  memset(ptr, 0, vex_count * vex_count);
  return ptr;
}


INT *Conn_position(INT *conn, INT size, INT lval, INT rval){
  Is_True((size > lval && size > rval), ("[Conn_pos] size<%d> smaller than lval<%d> rval<%d>\n",
    size, lval, rval));
  return &conn[lval * size + rval];
}

void Set_connections(INT *conn, INT size, INT lval, INT rval, INT is_connect){
  (*Conn_position(conn,size,lval,rval)) = is_connect;
}


BOOL Is_connected(INT *conn, INT size, INT lval, INT rval){
  return (*Conn_position(conn,size,lval,rval)) != 0;
}

INT Get_connected(INT *conn, INT size, INT lval, INT rval){
  return (*Conn_position(conn,size,lval,rval));
}


void Print_conn(INT *conn, INT size){
  for(UINT i = 0; i < size;  i++){
    for (UINT j = 0; j < size ; j++){
      cout << Get_connected(conn, size, i, j) << ((j == size - 1) ?("\n"):(" "));
    }
    //cout << endl;
  }
}

UINT Count_column(INT *conn, INT size, INT col){
  UINT count = 0;
  for(UINT i = 0; i < size;  i++){
    if(Is_connected(conn, size, i, col)){
      count ++;
    }
  }
  return count;
}

UINT Count_line(INT *conn, INT size, INT line){
  UINT count = 0;
  for(UINT i = 0; i < size;  i++){
    if(Is_connected(conn, size, line, i)){
      count ++;
    }
  }
  return count;
}

class LNODE {
public:
  INT     data;
  LNODE * next;
  LNODE () {
    data= 0x3f3f3f3f;
    next= NULLPTR;
  }
};

void Insert_to_table(LNODE * &hsh, INT data){
  if(!hsh){
    hsh= new LNODE();
    hsh->data= data;
  } else {
    while (hsh) {
      hsh = hsh->next;
    }
    hsh = new LNODE();
    hsh->data = data;
  }
}

void one_trial(){
  INT n, queries;
  cin>>n;
  LNODE* array[11+ 5];
  for (INT i = 0; i < 16; i++)
    array[i] = NULLPTR;

  for (INT i = 0; i < n; i++) {
    INT goal;
    cin >> goal;
    Insert_to_table(array[goal % 11], goal);
  }

  cin >> queries;
  while (queries--) {
    INT target;
    INT timeCount = 0;
    cin >> target;
    LNODE *root = array[target % 11];
    if (!root) {
      cout << "error" << endl;
      array[target % 11] = new LNODE();
      array[target % 11]->data = target;
    } else {
      while(true){
        timeCount++;
        if (root->data == target) {
          cout << target % 11 << ' ' << timeCount << endl;
          break;
        } else {
          if (!root->next) {
            cout << "error" << endl;
            root->next = new LNODE();
            root->next->data = target;
            break;
          }
          root = root->next;
        }
      }
    }

  }
}


INT main(){
  //  INT trials = 0;
  //cin >> trials;
  //while(trials--)
  one_trial();
  getchar();
  getchar();
  getchar();
}

/**
8
11 22 33 44 55 66 77 88
3
22
88
99*/
