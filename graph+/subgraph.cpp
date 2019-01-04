#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/****
 *
 * 问题 D: DS图—图的连通分量
    时间限制: 1 Sec  内存限制: 128 MB
  提交: 567  解决: 318

  题目描述
    输入无向图顶点信息和边信息，创建图的邻接矩阵存储结构，计算图的连通分量个数。

  输入
    测试次数t

    每组测试数据格式如下：

    第一行：顶点数 顶点信息
    第二行：边数
    第三行开始，每行一条边信息

  输出
    每组测试数据输出，顶点信息和邻接矩阵信息

    输出图的连通分量个数，具体输出格式见样例。

    每组输出直接用空行分隔。

  样例输入
    3
    4 A B C D
    2
    A B
    A C
    6 V1 V2 V3 V4 V5 V6
    5
    V1 V2
    V1 V3
    V2 V4
    V5 V6
    V3 V5
    8 1 2 3 4 5 6 7 8
    5
    1 2
    1 3
    5 6
    5 7
    4 8

  样例输出
    A B C D
    0 1 1 0
    1 0 0 0
    1 0 0 0
    0 0 0 0
    2

    V1 V2 V3 V4 V5 V6
    0 1 1 0 0 0
    1 0 0 1 0 0
    1 0 0 0 1 0
    0 1 0 0 0 0
    0 0 1 0 0 1
    0 0 0 0 1 0
    1

    1 2 3 4 5 6 7 8
    0 1 1 0 0 0 0 0
    1 0 0 0 0 0 0 0
    1 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 1 1 0
    0 0 0 0 1 0 0 0
    0 0 0 0 1 0 0 0
    0 0 0 1 0 0 0 0
    3
 *
 */
// STL Includings
using std::cout;
using std::cin;
using std::cout;
using std::cin;
using std::endl;

#define Is_Echo(cond, parm) if(cond)  printf parm
#define Is_True(cond, parm) if(!(cond)) {printf parm; getchar(); getchar(); getchar(); exit(1);}

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


INT Get_first_unvisited(INT *pInt, INT size) {
  for(UINT i = 0; i < size; i++){
    if(pInt[i] == 0){
      return i;
    }
  }
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

BOOL Visit_Node_DFS(INT *node_previous, INT *node, INT size, INT pos){
  Is_Echo(Echo(), ("Visiting pos <%d> \n", pos));
  node_previous[pos] = 1;
  INT tobe = Get_one_unvisited(node_previous, node, size, pos);
  if(tobe == -1) return FALSE;
  while(tobe != -1){
    Is_Echo(Echo(), ("Whiling tobe<%d> \n", tobe));
    Visit_Node_DFS(node_previous, node, size, tobe);
    tobe = Get_one_unvisited(node_previous, node, size, pos);
  }
  return TRUE;
}

void Traverse_DFS(INT *node, INT size){
  INT *empty = new INT[size];
  memset(empty, 0, size * sizeof(INT));
  INT count = 0;
  while(Get_first_unvisited(empty, size) != -1){
    count ++;
    if(FALSE == Visit_Node_DFS(empty, node, size, Get_first_unvisited(empty, size))){
      //count --;
      Is_Echo(Echo(), ("Found single-node situation now<%d>\n", count));
    }
  }
  if(Echo()) {
    cout << "count:";
  }
  cout << count << endl << endl;
}

void one_trial(){
  INT         vex_count  = 0,
    edge_count = 0,
    lhs        = 0,
    rhs        = 0;
  CHPTR       str;
  str = "U";
  cin         >> vex_count;

  CHPTR      *all_nodes = new CHPTR[vex_count];
  INT        *conn      = New_connections(vex_count);


  LISTVEC    &vex_pos   = *new LISTVEC(vex_count);
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
    Set_connections(conn, vex_count, rhs, lhs, TRUE);
  }

  for(UINT i = 0; i < vex_count ; i++){
    cout << all_nodes[i] << ((vex_count == i+1) ? ("\n") : (" "));
  }
  Print_conn(conn, vex_count);
  Traverse_DFS(conn, vex_count);
}


INT main(){
  INT trials = 0;
  cin >> trials;
  while(trials--) one_trial();
}

/**
样例输入
2
D 5
V1 V2 V3 V4 V5
7
V1 V2
V1 V4
V2 V3
V3 V1
V3 V5
V4 V3
V4 V5
U

 */