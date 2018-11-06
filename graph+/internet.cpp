//
// Created by lugt on 2018/11/6.
//

// Kruskal

// Prim

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

void Set_connections(INT *conn, INT size, INT lval, INT rval, BOOL is_connect){
  (*Conn_position(conn,size,lval,rval)) = is_connect ? 1 : 0;
}


BOOL Is_connected(INT *conn, INT size, INT lval, INT rval){
  return (*Conn_position(conn,size,lval,rval)) == 1;
}


void Print_conn(INT *conn, INT size){
  for(UINT i = 0; i < size;  i++){
    for (UINT j = 0; j < size ; j++){
      cout << Is_connected(conn, size, i, j) << ((j == size - 1) ?("\n"):(" "));
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

INT Get_one_unvisited(INT *node_previous, INT *node, INT size, INT pos){
  for(UINT i = 0; i < size ; i++){
    BOOL out = Is_connected(node, size, pos, i);
    if(out == TRUE && node_previous[i] == 0){
      Is_Echo(Echo(), ("[Get_one_unvisited] Unvisited pos<%d> \n", i));
      return i;
    }
  }
  return -1;
}

void Visit_Node_DFS(INT *node_previous, INT *node, INT size, INT pos){
  Is_Echo(Echo(), ("Visiting pos<%d> \n", pos));
  node_previous[pos] = 1;
  // Do something here.
  cout << pos << " "; // cou
  INT tobe = Get_one_unvisited(node_previous, node, size, pos);
  while(tobe != -1){
    Is_Echo(Echo(), ("Whiling tobe<%d> \n", tobe));
    Visit_Node_DFS(node_previous, node, size, tobe);
    tobe = Get_one_unvisited(node_previous, node, size, pos);
  }
}

void Traverse_DFS(INT *node, INT size){
  INT *empty = new INT[size];
  while(Get_first_unvisited(empty, size) != -1){
    Visit_Node_DFS(empty, node, size, Get_first_unvisited(empty, size));
  }
}

INT Get_first_unvisited(INT *pInt, INT size) {
  for(UINT i = 0; i < size; i++){
    if(pInt[i] == 0){
      return i;
    }
  }
  return -1;
}

void one_trial_dfs(){
  INT         vex_count  = 0, is_on = 0;
  cin         >> vex_count;
  INT        *conn      = New_connections(vex_count);
  cin         >>

  for(UINT i = 0; i < vex_count ; i++){
    for(UINT j = 0; j < vex_count ; j++){
        cin >> is_on;
        Set_connections(conn, vex_count, i, j, (is_on != 0));
    }
  }

  if(Echo()) Print_conn(conn, vex_count);
  Traverse_DFS(conn, vex_count);
  cout << endl;
}


void one_trial(){
  INT         vex_count  = 0,
    edge_count = 0,
    lhs        = 0,
    rhs        = 0;
  CHPTR       str = new CHAR [1000];

  cin         >> str;
  cin         >> vex_count;

  CHPTR     *all_nodes = new CHPTR[vex_count];
  INT        *conn      = New_connections(vex_count);


  LISTVEC    &vex_pos = *new LISTVEC(vex_count);
  for(UINT i = 0; i < vex_count; i++){
    CHPTR     node_name = new CHAR[1000];
    cin       >> node_name;
    all_nodes[i] = node_name;
    add_vex_pos(vex_pos, node_name, i);
  }

  cin >> edge_count;
  for(UINT i = 0; i < edge_count; i++){
    CHPTR     node_name = new CHAR[1000];
    cin       >> node_name;
    lhs       =  get_vex_pos(vex_pos, node_name);
    node_name = new CHAR[1000];
    cin       >> node_name;
    rhs       =  get_vex_pos(vex_pos, node_name);
    Set_connections(conn, vex_count, lhs, rhs, TRUE);
    if(*str == 'U')
      Set_connections(conn, vex_count, rhs, lhs, TRUE);
  }

  Print_conn(conn, vex_count);
  for(INT i = 0; i < vex_count; i++){
    INT count_line = 0, count_col = 0;
    cout << all_nodes[i];
    if(*str == 'D') {
      count_line = Count_line(conn, vex_count, i);
      count_col = Count_column(conn, vex_count, i);
      if(count_line + count_col != 0) {
        cout << ": ";
        cout << (count_line);
        cout << " " << (count_col);
        cout << " " << (count_line + count_col) << endl;
      }else{
        cout << endl;
      }
    }else{
      count_line = Count_line(conn, vex_count, i);
      if(count_line != 0) {
        cout << ": " << (count_line) << endl;
      }else{
        cout << endl;
      }
    }
  }
}


INT main(){
  INT trials = 0;
  cin >> trials;
  while(trials--) one_trial();
}

/**
INPUT
6
v1 v2 v3 v4 v5 v6
10
v1 v2 6
v1 v3 1
v1 v4 5
v2 v3 5
v2 v5 3
v3 v4 5
v3 v5 6
v3 v6 4
v4 v6 2
v5 v6 6
v1

OUTPUT:
15
prim:
v1 v3 1
v3 v6 4
v6 v4 2
v3 v2 5
v2 v5 3
kruskal:
v1 v3 1
v4 v6 2
v2 v5 3
v3 v6 4
v2 v3 5

 */