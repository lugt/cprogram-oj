//
// Created by lugt on 2018/11/27.
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

template <typename T>
BOOL compare(T a, T b){
  return (a > b);
}

template<typename T>
BOOL comp_eq(T a, T b) {
  return a == b;
}

template<typename T>
INT find_data_binary(T * vec, INT vec_count, T num){
  INT l = 0;
  INT r = vec_count - 1, m;
  while(r >= l){
    m = (INT) (((r - l) / 2.0) + l);
    if(comp_eq(num, vec[m])) return m;
    if(compare(num, vec[m])){
      l = m + 1;
    }else{
      r = m - 1;
    }
  }
  return -1;
}

const int BUCKET_NUM = 10;

struct ListNode{
  explicit ListNode(int i=0):mData(i),mNext(NULL){}
  ListNode* mNext;
  int mData;
};

ListNode* insert(ListNode* head,int val){
  ListNode dummyNode;
  ListNode *newNode = new ListNode(val);
  ListNode *pre,*curr;
  dummyNode.mNext = head;
  pre = &dummyNode;
  curr = head;
  while(NULL!=curr && curr->mData<=val){
    pre = curr;
    curr = curr->mNext;
  }
  newNode->mNext = curr;
  pre->mNext = newNode;
  return dummyNode.mNext;
}


ListNode* Merge(ListNode *head1,ListNode *head2){
  ListNode dummyNode;
  ListNode *dummy = &dummyNode;
  while(NULL!=head1 && NULL!=head2){
    if(head1->mData <= head2->mData){
      dummy->mNext = head1;
      head1 = head1->mNext;
    }else{
      dummy->mNext = head2;
      head2 = head2->mNext;
    }
    dummy = dummy->mNext;
  }
  if(NULL!=head1) dummy->mNext = head1;
  if(NULL!=head2) dummy->mNext = head2;

  return dummyNode.mNext;
}

void BucketSort(int n,int arr[]){
  vector<ListNode*> buckets(BUCKET_NUM,(ListNode*)(0));
  for(int i=0;i<n;++i){
    int index = arr[i]/BUCKET_NUM;
    ListNode *head = buckets.at(index);
    buckets.at(index) = insert(head,arr[i]);
  }
  ListNode *head = buckets.at(0);
  for(int i=1;i<BUCKET_NUM;++i){
    head = Merge(head,buckets.at(i));
  }
  for(int i=0;i<n;++i){
    arr[i] = head->mData;
    head = head->mNext;
  }
}


int min(int x, int y) {
  return x < y ? x : y;
}

void merge_sort(int arr[], int len) {
  int* a = arr;
  int* b = (int*) malloc(len * sizeof(int));
  int seg, start;
  for (seg = 1; seg < len; seg += seg) {
    for (start = 0; start < len; start += seg + seg) {
      int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
      int k = low;
      int start1 = low, end1 = mid;
      int start2 = mid, end2 = high;
      while (start1 < end1 && start2 < end2)
        b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
      while (start1 < end1)
        b[k++] = a[start1++];
      while (start2 < end2)
        b[k++] = a[start2++];
    }
    int* temp = a;
    a = b;
    b = temp;
  }
  if (a != arr) {
    int i;
    for (i = 0; i < len; i++)
      b[i] = a[i];
    b = a;
  }
  free(b);
}

class KeyType {
public:
    INT key;
    UINT64 msg;
    UINT seq;
};

typedef struct BiNode{
  BiNode * lchild;
  BiNode * rchild;
  KeyType data;
} BiTree;


BOOL Delete(BiTree *&p){
  BiTree *q, *s;
  if (!p->rchild && !p->lchild)
  {
    delete p;
    p = NULL;
  }
  else if(!p->rchild){
    q=p->lchild;
    p->data = q->data;
    p->lchild=q->lchild;
    p->rchild=q->rchild;
    delete q;
  }
  else if(!p->lchild){
    q=p->rchild;
    p->data = q->data;
    p->lchild=q->lchild;
    p->rchild=q->rchild;
    delete q;
  }
  else{
    q=p;
    s=p->lchild;
    while(s->rchild){
      q=s;
      s=s->rchild;
    }
    p->data = s->data;
    if(q!=p)
      q->rchild = s->lchild;
    else
      q->lchild = s->lchild;
    delete s;
  }
  return true;
}

BOOL DeleteBST(BiTree *T, INT key){
  if(!T)
    return false;
  else{
    if(key == T->data.key) {
      return Delete(T);
    }
    else if(key < T->data.key)
      return DeleteBST(T->lchild, key);
    else
      return DeleteBST(T->rchild, key);
  }
}



BOOL InsertBST(BiTree *&T, KeyType e){
  if(!T)
  {
    BiTree * s = new BiNode();
    s->data = e;
    s->lchild = s->rchild = NULL;
    T=s;
  }
  else if(e.key == T->data.key)
    return false;
  if (e.key < T->data.key)
    InsertBST(T->lchild, e);
  else
    InsertBST(T->rchild, e);
  return true;
}

INT searchCount = 0;

BOOL SearchBST(BiTree *t, KeyType key, BiTree *f, BiTree **p){
  if(!t) {
    *p=f;
    return false;
  } else if (key.key == (t->data.key)) {
    searchCount ++;
    *p=t;
    return true;
  } else if (key.key < t->data.key) {
    searchCount++;
    return SearchBST(t->lchild, key, t, p);
  } else {
    searchCount ++;
    return SearchBST(t->rchild, key, t, p);
  }
}


KeyType *getKeyType(const INT *vec, UINT i) {
  KeyType *k = new KeyType();
  k->seq = i;
  k->key = vec[i];
  k->msg = 0;
  return k;
}

INT find_block_id(INT temp, INT blk_cnt, const vector<INT> &partial_max) {
  INT blk_id = -1;
  for (UINT i = 0; i < blk_cnt; i++) {
      searchCount ++;
      if (temp <= partial_max[i]) {
        blk_id = i;
        break;
      }
    }

  if(blk_id == -1){
      blk_id = blk_cnt - 1;
  }
  return blk_id;
}

INT find_in_block(INT temp, const vector<vector<KeyType> *> &blocks, INT blk_id) {
  INT out = -1;
  for(UINT i = 0; i < blocks[blk_id]->size(); i++){
      searchCount ++;
      KeyType m = blocks[blk_id]->at(i);
      if(m.key == temp){
        out = m.seq;
        break;
      }
    }
  return out;
}

void insertData(INT data_count, INT blk_cnt, const INT *vec,
                const vector<INT> &partial_max,
                const vector<vector<KeyType> *> &blocks) {
  for (UINT i = 0; i < data_count; i++) {
    BOOL flag = FALSE;
    for (UINT j = 0; j < blk_cnt; j++) {
      if (vec[i] <= partial_max[j]) {
        KeyType *k = getKeyType(vec, i);
        blocks[j]->push_back(*k);
        flag = TRUE;
        break;
      }
    }
    if (!flag) {
      blocks[blk_cnt - 1]->push_back(*getKeyType(vec, i));
    }
  }
}

INT createBlocks(INT blk_cnt, vector<INT> &partial_max,
                 vector<vector<KeyType> *> &blocks) {
  INT max_val = 0;
  for (UINT i = 0; i < blk_cnt; i++){
    cin >> max_val;
    partial_max.push_back(max_val);
    blocks.push_back(new vector<KeyType>());
  }
  return max_val;
}

void one_trial(){

  INT  data_count  = 0;
  INT  temp = 0, q_count = 0, blk_cnt = 0;
  cin >> data_count;
  INT *vec = new INT[data_count];

  typedef vector<INT> I32VEC;
  I32VEC                       partial_max;
  vector<vector<KeyType> *>    blocks;
  vector<BiTree *>             trees;

  for(UINT i = 0; i < data_count; i++){
    cin >> temp;
    vec[i] = temp;
  }

  cin >> blk_cnt;

  // Construct Blocks;
  temp = createBlocks(blk_cnt, partial_max, blocks);
  insertData(data_count, blk_cnt, vec, partial_max, blocks);
  cin >> q_count;
  for(UINT i = 0; i < q_count; i++){
    cin  >> temp;
    searchCount = 0;
    INT blk_id = find_block_id(temp, blk_cnt, partial_max);
    INT out = find_in_block(temp, blocks, blk_id);
    if(out >= 0){
      cout << (out+1) << "-" <<  searchCount << endl;
    }else{
      cout << "error" << endl;
    }
  }
}

INT main(){
  INT trials = 0;
  //cin >> trials;
  //while(trials--)
  one_trial();
  getchar();
  getchar();
  getchar();
  return 0;
}

/**
18
22 12 13 8 9 20 33 42 44 38 24 48 60 58 74 57 86 53
3
22 48 86
6
13
5
48
40
53
90

*/
