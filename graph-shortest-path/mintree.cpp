//
// Created by lugt on 2018/11/6.
//

// Kruskal

// Prim

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

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


void  Dijkstra(Graph G, INT *w, INT s, INT vex_count){
  INT *s        = new INT[vex_count];
  INT *d        = new INT[vex_count];
  INT *previous = new INT[vex_count];
  for (i = 0; i < vex_count; i++) {
    d[v] = 0x3f3f3f3f;
    previous[v] = -1;
  }
  d[s] = 0;
  vector<INT> s;
  
  while (!q.empty()) {

  }
	       while Q is not an empty set      // Dijkstra算法主体
			 u := Extract_Min(Q)
			 S.append(u)
			 for each edge outgoing from u as (u,v)
				    if d[v] > d[u] + w(u,v)             // 拓展边（u,v）。w(u,v)为从u到v的路径长度。
					  d[v] := d[u] + w(u,v)         // 更新路径长度到更小的那个和值。
					  previous[v] := u              // 纪录前趋顶点
  }
  

void one_trial(){
  INT         vex_count  = 0,
              edge_count = 0,
              lhs        = 0,
              rhs        = 0;

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

  std::vector<Tuple *> edges;
  std::vector<Tuple *> kruskal_edges;
  std::vector<Tuple *> prim_edges;
  std::vector<Tuple *> prim_work;
  INT                 *kruskal_set   = new INT[vex_count];
  INT                 *prim_set      = new INT[vex_count];

  INT weight;
  cin >> edge_count;
  for(UINT i = 0; i < edge_count; i++){
    CHPTR     node_name = new CHAR[1000];
    cin       >> node_name;
    lhs       =  get_vex_pos(vex_pos, node_name);
    node_name = new CHAR[1000];
    cin       >> node_name >> weight;
    rhs       =  get_vex_pos(vex_pos, node_name);
    Set_connections(conn, vex_count, lhs, rhs, weight);
    Set_connections(conn, vex_count, rhs, lhs, weight);
    Tuple  *p = new Tuple(lhs, rhs, weight);
    edges.push_back(p);
  }

  if(Echo()) Print_conn(conn, vex_count);

  CHPTR node_name = new CHAR[1000];
  cin >> node_name;
  INT startv = get_vex_pos(vex_pos, node_name);

  //=====================================================
  // Prim
  //=====================================================
  memset(prim_set, 0, sizeof(INT) * vex_count);
  INT prim_count = 0;
  INT prim_shortest_len = 0;
  INT prim_shortest_edge = 0;
  INT prim_unsolved = 0;
  std::vector<Tuple *> temp(edges);
  INT prim_shortest_target = 0;

  INT count_of_connect = 1;
  prim_set[startv] = 1;
  while(count_of_connect < vex_count){

    prim_shortest_edge   = 0;
    prim_shortest_len    = 0;
    prim_shortest_target = 0;

    BOOL found = FALSE;
    for(UINT i = 0; i <temp.size(); i++) {
      if(temp.at(i)->left == prim_unsolved || temp.at(i)->right == prim_unsolved){
        INT target = (temp.at(i)->left == prim_unsolved) ? (temp.at(i)->right) : (temp.at(i)->left);
        if(prim_set[target] == 1){
          continue;
        }
        if(prim_shortest_len == 0 || temp.at(i)->weight <= prim_shortest_len){
          prim_shortest_edge     = i;
          prim_shortest_len      = temp.at(i)->weight;
          prim_shortest_target   = target;
          Is_Echo(Echo(), ("[short-edge] edge<%d> l<%d> r<%d>, weight:<%d> \n", i, temp.at(i)->left , temp.at(i)->right, temp.at(i)->weight));
          found = TRUE;
        }
      }
    }

    if(!found){
      for(UINT i = 0; i <temp.size(); i++) {
        if(prim_set[temp.at(i)->left] > 0 && prim_set[temp.at(i)->right] > 0){
          continue;
        }else if(prim_set[temp.at(i)->left] == 0 && prim_set[temp.at(i)->right] == 0){
          continue;
        }
        INT target = (prim_set[temp.at(i)->left] > 0) ? (temp.at(i)->right) : (temp.at(i)->left);
        if(prim_shortest_len == 0 || temp.at(i)->weight <= prim_shortest_len){
          prim_shortest_edge     = i;
          prim_shortest_len      = temp.at(i)->weight;
          prim_shortest_target   = target;
          Is_Echo(Echo(), ("[backup-short-edge] edge<%d> l<%d> r<%d>, weight:<%d>\n", i, temp.at(i)->left , temp.at(i)->right, temp.at(i)->weight));
        }
      }
    }

    Is_Echo(Echo(), ("**   [saving-edge] edge<%d> l<%d> r<%d>, weight:<%d>\n", prim_shortest_edge, temp.at(prim_shortest_edge)->left , temp.at(prim_shortest_edge)->right, temp.at(prim_shortest_edge)->weight));
    if(prim_shortest_target == temp.at(prim_shortest_edge)->right){
      prim_edges.push_back(temp.at(prim_shortest_edge));
    }else{
      prim_edges.push_back(
        new Tuple(
        temp.at(prim_shortest_edge)->right,
        prim_shortest_target,
        temp.at(prim_shortest_edge)->weight));
    }
    temp.erase(temp.begin() + prim_shortest_edge);

    prim_set[prim_shortest_target] = 1;
    prim_count                    += prim_shortest_len;
    prim_unsolved                  = prim_shortest_target;
    count_of_connect ++;
    // Has someone to solve
  }


  //=====================================================
  // Kruskal
  //=====================================================
  std::sort(edges.begin(), edges.end(), customLess);

  memset(kruskal_set, 0, sizeof(INT) * vex_count);
  INT kruskal_count = 0;
  INT max_circle = 100;
  for(INT i = 0; i < edges.size(); i++){
    // Traverse Edges and find the unconnected, set to connected;
    INT left = edges.at(i)->left;
    INT right = edges.at(i)->right;
    if(kruskal_set[left] > 0 && kruskal_set[right] == kruskal_set[left]) {
      Is_Echo(EchoKrusKal(), ("skipping left<%d>  right<%d> \n", left, right));
      continue;
    }else if(kruskal_set[left] > 0 && kruskal_set[right] > 0){
      Is_Echo(EchoKrusKal(), ("two circle combine left<%d>  right<%d> circle<%d,%d> \n", left, right, kruskal_set[left], kruskal_set[right]));
      INT a = kruskal_set[left];
      INT b = kruskal_set[right];
      INT min = std::min(kruskal_set[left], kruskal_set[right]);
      for(UINT j = 0; j < vex_count ; j++){
        if(kruskal_set[j] == a || kruskal_set[j] == b) {
          Is_Echo(EchoKrusKal(), ("bingding node<%d>  => circle<%d => %d> \n", j, kruskal_set[j], min));
          kruskal_set[j] = min;
        }
      }
      kruskal_edges.push_back(edges.at(i));
      kruskal_count += edges.at(i)->weight;
    }else if(kruskal_set[left] > 0 || kruskal_set[right] > 0) {
      INT max = std::max(kruskal_set[left], kruskal_set[right]);
      Is_Echo(EchoKrusKal(), ("connecting-new-dot left<%d>  right<%d> into circle<%d> \n", left, right, max));
      kruskal_set[left] = max;
      kruskal_set[right] = max;
      kruskal_edges.push_back(edges.at(i));
      kruskal_count += edges.at(i)->weight;
    }else{
      Is_Echo(EchoKrusKal(), ("new-circle left<%d>  right<%d> circle<%d> \n", left, right, max_circle));
      kruskal_set[left] = max_circle;
      kruskal_set[right] = max_circle;
      max_circle++;
      kruskal_edges.push_back(edges.at(i));
      kruskal_count += edges.at(i)->weight;
    }
  }

  cout << kruskal_count << endl;

  cout << "prim:" << endl;
  for(UINT i = 0; i < prim_edges.size(); i++){
    cout << vex_pos.Get_Name(prim_edges.at(i)->left)  << " "
         << vex_pos.Get_Name(prim_edges.at(i)->right) << " "
         << prim_edges.at(i)->weight << endl;
  }
  cout << "kruskal:" << endl;
  for(UINT i = 0; i < kruskal_edges.size(); i++){
    if(kruskal_edges.at(i)->left <= kruskal_edges.at(i)->right) {
      cout << vex_pos.Get_Name(kruskal_edges.at(i)->left) << " "
           << vex_pos.Get_Name(kruskal_edges.at(i)->right) << " "
           << kruskal_edges.at(i)->weight << endl;
    }else{
      cout << vex_pos.Get_Name(kruskal_edges.at(i)->right) << " "
           << vex_pos.Get_Name(kruskal_edges.at(i)->left) << " "
           << kruskal_edges.at(i)->weight << endl;
    }
  }
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
