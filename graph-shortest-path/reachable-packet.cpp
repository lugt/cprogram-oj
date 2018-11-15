//
// Created by lugt on 2018/11/6.
//

/***
 *
问题 A: 图的顶点可达闭包
时间限制: 1 Sec  内存限制: 128 MB
提交: 777  解决: 279
[提交][状态][讨论版]
题目描述
给定有向图的邻接矩阵A，其元素定义为：若存在顶点i到顶点j的有向边则A[i,j]=1，若没有有向边则A[i,j]= 0。试求A的可达闭包矩阵A*，其元素定义为：若存在顶点i到顶点j的有向路径则A*[i,j]=1，若没有有向路径则A*[i,j]= 0。

输入
第1行顶点个数n

第2行开始的n行有向图的邻接矩阵，元素之间由空格分开

输出
有向图的可达闭包矩阵A*，元素之间由空格分开

样例输入
4
0 1 0 1
0 0 1 0
0 0 0 0
0 0 0 0
样例输出
0 1 1 1
0 0 1 0
0 0 0 0
0 0 0 0
提示
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

#define INT_MAX  0x7f7f7f7f

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

//
//void  Dijkstra(std::vector<Tuple *> edges, INT *w, INT s, INT vex_count){
//  INT *s        = new INT[vex_count];
//  INT *d        = new INT[vex_count];
//  INT *previous = new INT[vex_count];
//  for (INT i = 0; i < vex_count; i++) {
//    d[i] = 0x3f3f3f3f;
//    previous[i] = -1;
//  }
//  d[s] = 0;
//  vector<INT> s;
//
//  while (!q.empty()) {
//
//  }
//	       while Q is not an empty set      // Dijkstra算法主体
//			 u := Extract_Min(Q)
//			 S.append(u)
//			 for each edge outgoing from u as (u,v)
//				    if d[v] > d[u] + w(u,v)             // 拓展边（u,v）。w(u,v)为从u到v的路径长度。
//					  d[v] := d[u] + w(u,v)         // 更新路径长度到更小的那个和值。
//					  previous[v] := u              // 纪录前趋顶点
//  }
//}


INT get_max_bit(INT lhs, INT rhs){
  return lhs || rhs;
}

INT get_min_bit(INT lhs, INT rhs){
  return lhs && rhs;
}

void Warshall_bit(INT *r, INT num)
{
  INT   i;
  INT   j;
  INT   k;
  INT  *temp = New_connections(num);
  for (k = 0; k < num; k++)
  {
    for (i = 0; i < num; i++) {
      for (j = 0; j < num; j++) {
        INT result = get_max_bit(Get_connected(r,  num, i, j),
                             get_min_bit(Get_connected(r, num, i, k),
                                     Get_connected(r, num, k, j)));
        Set_connections(temp, num, i, j, result);
      }
    }
    for (i = 0; i < num; i++)
      for (j = 0; j < num; j++) {
        INT result = Get_connected(temp, num, i, j);
        Set_connections(r, num, i, j, result);
      }
  }

}

INT get_min(INT lhs, INT rhs){
  if(lhs == INT_MAX) return rhs;
  return (lhs < rhs) ? lhs : rhs;
}

INT get_sum(INT lhs, INT rhs){
  if(lhs == INT_MAX || rhs == INT_MAX) return INT_MAX;
  return lhs + rhs;
}

void Warshall(INT num, INT *r)
{
  INT   i;
  INT   j;
  INT   k;
  INT  *temp = New_connections(num + 1);
  for (k = 1; k <= num; k++)
  {
    for (i = 1; i <= num; i++) {
      for (j = 1; j <= num; j++) {
        INT result = get_min(Get_connected(r,  num, i, j),
                      get_sum(Get_connected(r, num, i, k),
                              Get_connected(r, num, k, j)));
        Set_connections(temp, num, i, j, result);
      }
    }
    for (i = 1; i <= num; i++)
      for (j = 1; j <= num; j++) {
        INT result = Get_connected(temp, num, i, j);
        Set_connections(r, num, i, j, result);
      }
  }

}



void one_trial() {
  INT vex_count = 0;
  INT weight;


  cin >> vex_count;
  INT *conn = New_connections(vex_count);

  for (UINT i = 0; i < vex_count; i++) {
    for (UINT j = 0; j < vex_count; j++) {
      cin >> weight;
      //if (weight == 0) weight = INT_MAX;
      Set_connections(conn, vex_count, i, j, weight);
    }
  }


  //Print_conn(conn, vex_count);

  Warshall_bit(conn, vex_count);

  Print_conn(conn, vex_count);

//  for (UINT i = 0; i < vex_count; i++)
//    for (UINT j = 0; j < vex_count; j++)
//      cout << Get_connected(conn, vex_count, i, j);
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

