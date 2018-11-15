//
// Created by lugt on 2018/11/6.
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

/***
 * 问题 B: DS图应用--最短路径
题目描述
给出一个图的邻接矩阵，再给出指定顶点v0，求顶点v0到其他顶点的最短路径

输入
第一行输入t，表示有t个测试实例

第二行输入n，表示第1个图有n个结点

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其他结点如果相连则为1，无连接则为0，数据之间用空格隔开

第四行输入v0，表示求v0到其他顶点的最短路径距离

以此类推输入下一个示例

输出
每行输出v0到某个顶点的最短距离和最短路径

每行格式：v0编号-其他顶点编号----[最短路径]，具体请参考示范数据

样例输入
1
5
0 5 0 7 15
0 0 5 0 0
0 0 0 0 1
0 0 2 0 0
0 0 0 0 0
0
样例输出
0-1-5----[0 1 ]
0-2-9----[0 3 2 ]
0-3-7----[0 3 ]
0-4-10----[0 3 2 4 ]
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
  INT  temp;

  cin >> vex_count;

  std::vector<Tuple *> edges;
  INT * conn = New_connections(vex_count);

  for(UINT i = 0; i < vex_count; i++){
    for(UINT j = 0; j < vex_count; j++) {
      cin >> temp;
      if(temp == 0) temp = INT_MAX;
      Set_connections(conn, vex_count, i, j, temp);
      Tuple *p = new Tuple(i, j, temp);
      edges.push_back(p);
    }
  }

  cin >> temp; // as start-point

  INT * distance = new INT[vex_count];
  INT * previous = new INT[vex_count];

  //Print_conn(conn, vex_count);
  Dijkstra(edges, temp, vex_count, distance, previous);
  //Print_conn(conn, vex_count);

  for(INT i = 0; i < vex_count; i++){
    if(temp == i) continue;
    if(distance[i] != INT_MAX){
      std::vector<INT> list;
      INT end = i;
      list.clear();
      while(end != temp){
        list.push_back(end);
        end = previous[end];
      }
      cout << temp << "-" << i << "-"<< distance[i] << "----";
      cout << "[" << temp << " ";
      for(INT j =  list.size() - 1; j >= 0; j--){
        cout << list[j] << " ";
      }
      cout << "]" << endl;
    }
  }
}


INT main(){
  INT trials = 0;
  cin >> trials;
  while(trials--) one_trial();
  getchar();
  getchar();
  getchar();
}
