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
  INT                 *kruskal_parent   = new INT[vex_count];
  INT                 *kruskal_kid      = new INT[vex_count];
  INT                 *kruskal_root     = new INT[vex_count];
  INT                 *prim_set         = new INT[vex_count];

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
  INT prim_unsolved = startv;
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

  memset(kruskal_parent, 0, sizeof(INT) * vex_count);
  for(UINT i = 0; i < vex_count; i ++){
    kruskal_parent[i] = -1;
    kruskal_root[i] = -1;
    kruskal_kid[i] = -1;
  }
  INT kruskal_count = 0;
  Is_Echo(EchoKrusKal(), ("\"=================================\"\n"));
  Is_Echo(EchoKrusKal(), (" Kruskal \n"));
  Is_Echo(EchoKrusKal(), ("\"=================================\"\n"));
  for(INT i = 0; i < edges.size(); i++){
    // Traverse Edges and find the unconnected, set to connected;
    INT left = edges.at(i)->left;
    INT right = edges.at(i)->right;
    if(kruskal_root[left] >= 0 && kruskal_root[right] == kruskal_root[left]) {
      Is_Echo(EchoKrusKal(), ("skipping left<%d>  right<%d> \n", left, right));
      continue;
    }else if(kruskal_root[left] >= 0 && kruskal_root[right] >= 0){
      Is_Echo(EchoKrusKal(), ("two circle combine left<%d>  right<%d>  parents<%d,%d> roots<%d, %d>\n",
        left, right, kruskal_parent[left], kruskal_parent[right], kruskal_root[left], kruskal_root[right]));
      INT top_of_stack = left;
      INT tochange = right;
      INT root_to_be = std::min(kruskal_root[left], kruskal_root[right]);
      if(root_to_be == kruskal_root[right]){
        top_of_stack = right;
        tochange = left;
      }

      while(kruskal_kid[top_of_stack] != -1){
        top_of_stack = kruskal_kid[top_of_stack];
      }

      while(kruskal_parent[tochange] != -1){
        tochange = kruskal_parent[tochange];
      }

      while(tochange >= 0) {
        INT kid = kruskal_kid[tochange];
        Is_Echo(EchoKrusKal(), ("bingding node<%d> => before: parent<%d>, kid<%d> root->%d \n", tochange, kruskal_parent[tochange], kruskal_kid[tochange], kruskal_root[tochange]));
        kruskal_root[tochange]    = root_to_be;
        kruskal_parent[tochange]  = top_of_stack;
        kruskal_kid[top_of_stack] = tochange;
        kruskal_kid[tochange]     = -1;
        Is_Echo(EchoKrusKal(), ("bingding node<%d> => now: parent<%d>, kid<%d> root->%d \n", tochange, kruskal_parent[tochange], kruskal_kid[tochange], kruskal_root[tochange]));
        top_of_stack = tochange;
        tochange = kid;
      }
      kruskal_edges.push_back(edges.at(i));
      kruskal_count += edges.at(i)->weight;

    }else if(kruskal_root[left] >= 0 || kruskal_root[right] >= 0) {
      if(kruskal_root[left] >= 0){
        Is_Echo(EchoKrusKal(), ("connecting-new-dot r<%d> child of l<%d> \n", right, left));
        kruskal_root[right] = kruskal_root[left];
        kruskal_parent[right] = left;
        kruskal_kid[left] = right;
      }else{
        Is_Echo(EchoKrusKal(), ("connecting-new-dot l<%d>  child of r<%d> \n", left, right));
        kruskal_root[left] = kruskal_root[right];
        kruskal_parent[left] = right;
        kruskal_kid[right] = left;
      }
      kruskal_edges.push_back(edges.at(i));
      kruskal_count += edges.at(i)->weight;
    }else{
      INT min = std::min(left, right);
      Is_Echo(EchoKrusKal(), ("new-circle left<%d>  right<%d>  root<%d> \n", left, right, min));
      kruskal_root[left] = min;
      kruskal_root[right] = min;
      if(min == left){
        kruskal_parent[right] = left;
        kruskal_kid[left] = right;
      }else{
        kruskal_parent[left] = right;
        kruskal_kid[right] = left;
      }
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


/**

 7
0 1 2 3 4 5 6
9
0 1 28
0 5 10
1 2 16
3 2 12
3 6 18
4 6 24
4 5 25
3 4 22
1 6 14
6

 */