//
// Created by lugt on 2018/11/15.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

/**
 * 追星
题目描述
城市总共有N座。yintama是右京女神的狂热粉，当他得知右京女神将要在城市N举办演唱会的时候，马上开始准备动身前往城市N。原本他可以直接乘飞机直达城市N，然而贫穷使他屈服，他必须选择总花费最少的那条路径。设总共有N座城市(2<=N<=1000），城市编号分别为1,2,3......N。M条航线(1<=M<=2000)，每条航线连接两座城市，并且可以往返（无向）。yintama目前在身在城市1，求最后yintama参加右京女神演唱会所需要的最少花费。（PS：重边考虑一下？）

输入
有多组输入。

第一行输入一个N、M，代表城市的总数，以及航线的总数。

接下来M行，每行输入三个数字u v w，代表城市u、v之间存在航线，机票花费为w。

输出
每行输出一个数，代表yintama参加右京女神演唱会所需的最少花费。

样例输入
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
 */
// STL Includings
using std::cout;
using std::cin;
using std::cout;
using std::cin;
using std::endl;

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

INT Extract_Min(std::vector<INT> &vex, INT * dist){
  INT min_node = -1;
  INT min_len = INT_MAX;
  for(INT i = 0; i < vex.size(); i++){
    INT u = vex[i];
    if(dist[u] <= min_len){
      min_len = dist[u];
      min_node = u;
    }
  }
  if(min_node == -1) return vex[0];
  return min_node;
}


std::vector<INT> S;

void  Dijkstra(std::vector<Tuple *> &edges, INT start, INT vex_count, INT *distance, INT *previous){
  for (INT i = 0; i < vex_count; i++) {
    distance[i] = INT_MAX;
  }
  distance[start] = 0;
  std::vector<INT> q;

  for(INT i = 0; i < vex_count; i++){
    q.push_back((INT) i);
  }

  while (!q.empty()) {
    INT u = Extract_Min(q, distance);
    for(std::vector<INT>::iterator it = q.begin(); it != q.end(); it++){
      if((*it) == u){
        q.erase(it);
        break;
      }
    }
    for (INT i = 0; i < edges.size(); i++){
      if(edges[i]->left == u){
        INT v = edges[i]->right;
        if(distance[u] != INT_MAX && distance[v] > distance[u] + edges[i]->weight){
          INT outl = distance[u];
          INT outr = edges[i]->weight;
          distance[v] = outl + outr;           // 更新路径长度到更小的那个和值。
          previous[v] = u;                     // 纪录前趋顶点
        }
      }
    }
  }
}
  

void one_trial(){
  INT  vex_count  = 0;
  INT  temp = 0;

  cin >> vex_count;

  std::vector<Tuple *> edges;

  INT ed_count = 0;
  cin >> ed_count;
  for(UINT i = 0; i < ed_count; i++){
    INT l, r;
      cin >> l >> r;
      cin >> temp;
      Tuple *p = new Tuple(l- 1, r-1, temp);
      edges.push_back(p);
    p = new Tuple(r- 1, l-1, temp);
    edges.push_back(p);
  }

  INT * distance = new INT[vex_count];
  INT * previous = new INT[vex_count];

  //Print_conn(conn, vex_count);
  Dijkstra(edges, 0, vex_count, distance, previous);
  //Print_conn(conn, vex_count);
  cout << distance[vex_count - 1] << endl;
}


INT main(){
  INT trials = 0;
  one_trial();
  getchar();
  getchar();
  getchar();
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
