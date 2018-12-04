//
// Created by lugt on 2018/11/20
//

#include <iostream>
#include <stdio.h>

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
#define Get_some_thing memset
#define Put_some_thing strcmp
#define INTPTR extern
#define NULLPTR NULL
#define FALSE ((BOOL) 0)
#define TRUE  ((BOOL) 1)

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

class LISTVEC{

  INT size;
  CHAR **names;

public:
  INT getSize() const {
    return size;
  }

  LISTVEC(INT size_){
    this->size = size_;
    names = new CHPTR[size];
  }
  void Set_Name(CHPTR name, UINT pos){
    Is_True((pos < size), ("Set_Name :: Pos<%d> bigger (or eq) than Size!<%d>", pos, size));
    names[pos] = name;
  }

  CHPTR Get_Name(UINT pos){
    Is_True((pos < size), ("Get_Name :: Pos<%d> bigger (or eq) than Size<%d>!", pos, size));
    return names[pos];
  }

};

INT Get_first_unvisited(INT *pInt, INT size);

void add_vex_pos(LISTVEC &ve, CHPTR name, UINT i) {
  ve.Set_Name(name, i);
}

INT get_vex_pos(LISTVEC &ve, CHPTR name){
  for(UINT i = 0; i < ve.getSize(); i++){
    if(strcmp(ve.Get_Name(i), name) == 0){
      return i;
    }
  }
  Is_True(FALSE, ("Cannot locate for node <%s> \n", name));
  return -1;
}

INT Get_one_unvisited(INT *node_previous, INT *conn, INT size, INT pos){
  for(UINT i = 0; i < size ; i++){
    BOOL out = Is_connected(conn, size, pos, i);
    if(out == TRUE && node_previous[i] == 0){
      Is_Echo(Echo(), ("[Get_one_unvisited] Unvisited pos<%d> \n", i));
      return i;
    }
  }
  return -1;
}

INT Get_first_unvisited(INT *pInt, INT size) {
  for(UINT i = 0; i < size; i++){
    if(pInt[i] == 0){
      return i;
    }
  }
  return -1;
}

class Tuple{
public:
  INT left;
  INT right;
  INT weight;
public:
  Tuple(int l, int r, int w){
    left = l;
    right = r;
    weight = w;
  }
};

struct simpleCompareLess{
  bool operator()(Tuple * const &a, Tuple * const &b) const
  {
    return a->weight < b->weight;
  }
} customLess;

void ShortPath(INT *conn, INT vex_count, INT *output, INT *visited,
               INT *visited_count){
  for(UINT i = 0; i < vex_count; i++) {
    visited[i] = 0x3f3f3f3f;
  }

  for (UINT i = 0; i < vex_count; i++) {
    BOOL found = FALSE;
    for (UINT j = 0; j <vex_count; j++){
      if(Get_connected(conn, vex_count, j, i) != 0){
        found = TRUE;
        break;
      }
    }
    if(!found){
      output[i] = -1;
      visited[i] = 0;
      (*visited_count) ++;
    }
  }
  while(TRUE) {
    BOOL found = FALSE;
    for (UINT i = 0; i < vex_count; i++) {
      if(visited[i] == 0x3f3f3f3f){
        found = TRUE;
        INT max = 0;
        for (UINT j = 0; j <vex_count; j++){
          if(Get_connected(conn, vex_count, j, i) > 0){
            if(visited[j] == 0x3f3f3f3f){
              found = FALSE;
              break;
            }
            if(Get_connected(conn, vex_count, j, i) + visited[j] > max){
              max = Get_connected(conn, vex_count, j, i) + visited[j];
              output[i] = j;
            }
          }
        }
        if(found){
          visited[i] = max;
          (*visited_count)++;
          break;
        }
      }
    }
    if(!found){
      break;
    }
  }
}


INT Get_latest(INT l, INT r) {
  if(l == 0x3f3f3f3f) return r;
  return l < r ? l : r;
}


void LastestCheck(INT *conn, INT vex_count,
                  INT *earliest, INT *visited, INT gmax) {

  INT visited_counta = 0;
  INT *visited_count = &visited_counta;

  for(UINT i = 0; i < vex_count; i++) {
    visited[i] = 0x3f3f3f3f;
  }

  for (UINT i = 0; i < vex_count; i++) {
    BOOL found = FALSE;
    for (UINT j = 0; j <vex_count; j++){
      if(Get_connected(conn, vex_count, i, j) != 0){
        found = TRUE;
        break;
      }
    }
    if(!found){
      visited[i] = gmax;
      earliest[i] = gmax;
      //(*visited_count) ++;
    }
  }

  while(TRUE) {
    BOOL found = FALSE;
    for (UINT i = 0; i < vex_count; i++) {
      if(visited[i] == 0x3f3f3f3f){ //chudubuweiling
        found = TRUE;
        INT min = 0x3f3f3f3f;
        for (UINT j = 0; j <vex_count; j++){
          if(Get_connected(conn, vex_count, i, j) > 0){
            if(visited[j] == 0x3f3f3f3f){
              found = FALSE;
              break;
            }
            if(visited[j] - Get_connected(conn, vex_count, i, j)  < min){
              min = visited[j] - Get_connected(conn, vex_count, i, j);
            }
          }
        }
        if(found){
          visited[i] = min;
          (*visited_count)++;
          break;
        }
      }
    }
    if(!found){
      break;
    }
  }
}

void one_trial(){
  INT         vex_count  = 0,
    edge_count = 0,
    lhs        = 0,
    rhs        = 0;
  cin         >> vex_count;
  INT        *conn      = New_connections(vex_count);
  INT         weight;
  cin         >> edge_count;
  for (UINT i = 0; i < edge_count; i++){
    cin >> lhs >> rhs >> weight;
    Set_connections(conn, vex_count, lhs, rhs, weight);
  }
  INT * out     = new INT[vex_count];
  INT * visited = new INT[vex_count];
  INT   visited_count = 0;
  ShortPath(conn, vex_count, out, visited, &visited_count);

  if(Echo()) Print_conn(conn, vex_count);

  INT visit_max = 0;
  for(UINT i = 0; i < visited_count; i++){
    if(visited[i] > visit_max) visit_max = visited[i];
    cout << visited[i] << " ";
  }

  cout << endl;

  INT *lastestVisited = new INT[vex_count];

  LastestCheck(conn, vex_count, visited, lastestVisited, visit_max);

  for(UINT i = 0; i < vex_count; i++){
    cout << lastestVisited[i] << " ";
  }

  cout << endl;

}


INT main(){
  INT trials = 0;
  //cin >> trials;
  //while(trials--) one_trial();
  one_trial();
  getchar();
  getchar();
  getchar();
}

/**
样例输入
9
12
0 1 3
0 2 10
1 3 9
1 4 13
2 4 12
2 5 7
3 6 8
3 7 4
4 7 6
5 7 11
6 8 2
7 8 5
样例输出
0 3 10 12 22 17 20 28 33
0 9 10 23 22 17 31 28 33
 */
