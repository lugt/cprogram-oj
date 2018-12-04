

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>


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
  
  cout << pos << " "; 
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

typedef struct {
    INT key;
    UINT64 msg;
    UINT seq;
} KeyType;

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
    /*
    p->data = p->lchild->data;
    p->lchild=p->lchild->lchild;
    p->rchild=p->lchild->rchild;
    */
    p->data = q->data;
    p->lchild=q->lchild;
    p->rchild=q->rchild;

    delete q;
  }
  else if(!p->lchild){	
    q=p->rchild;
    /*
    p->data = p->rchild->data;
    p->lchild=p->rchild->lchild;
    p->rchild=p->rchild->rchild;
    */
    p->data = q->data;
    p->lchild=q->lchild;
    p->rchild=q->rchild;

    delete q;  }
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


BOOL InsertBST(BiTree **T, KeyType e){
  if(!(*T))
  {
    BiTree * s = new BiNode();
    s->data = e;
    s->lchild = s->rchild = NULL;
    *T=s;
    return true;
  }
  else if(e.key == (*T)->data.key)
    return false;
  if (e.key < (*T)->data.key)
    InsertBST(&((*T)->lchild), e);
  else
    InsertBST(&((*T)->rchild), e);
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


void Traverse_BST(BiTree *t) {

  if (!t) {
    return;
  }

  Traverse_BST(t->lchild);
  cout << t->data.key << " ";
  Traverse_BST(t->rchild);

}

void one_trial(){
  INT  data_count  = 0;
  INT  temp, q_count;
  BiTree * tree = NULL;
  cin >> data_count;
  INT *vec = new INT[data_count];

  for(UINT i = 0; i < data_count; i++){
    cin >> temp;
    vec[i] = temp;
    KeyType *k = new KeyType();
    k->key = temp;
    k->seq = i;
    k->msg = 0;
    InsertBST(&tree, *k);
  }


  Traverse_BST(tree);
  cout << endl;

  cin >> q_count;

  for(UINT i = 0; i < q_count; i++){

    BiTree *f = NULL, *p = NULL;
    KeyType *k = new KeyType();

    cin  >> temp;
    k->key = temp;
    k->msg = 0;
    searchCount = 0;
    BOOL out = SearchBST(tree, *k, f, &p);
    if(out){
      cout << f->data.seq << endl;
    }else{
      cout << "error" << endl;
    }
    cout << endl;
  }
}

INT main(){
  INT trials = 0;
  cin >> trials;
  while(trials --) one_trial();
  getchar();
  getchar();
  getchar();
}

/**

 INPUT

1
6
22 33 55 66 11 44
3
77
50
10

 */
