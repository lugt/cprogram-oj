//
// Created by xc5 on 22/11/2018.
// 作者鲁冠廷2017152003, 参考以往实验内容
//
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>
#include <map>
#include <math.h>

#define         OK                    0
#define         FAIL                  1
#define         MAX_SIZE              10000
#define         NULLPTR               NULL
#define         TRUE                  true
#define         FALSE                 false

#define  Is_Print(cond, parm)  if(cond) printf parm
#define  Is_True(cond, parm)  if((!(cond))) { printf parm ; exit(1); }

typedef         char          CHAR;
typedef         int           INT;
typedef         long long     INT64;
typedef         unsigned int  UINT;
typedef         unsigned long long UINT64;
typedef         char**        CHPPTR;
typedef         char*         CHPTR;
typedef         const char*   CCHPTR;
typedef         bool          BOOL;
typedef         std::string   STRING;

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::stack;


inline BOOL Printing(){
  return FALSE;
}

INT compare_int(const void* lhs, const void *rhs){
  return *((INT *)lhs) - *((INT *)rhs);
}

enum MOVE{
  E_LEFT,
  E_RIGHT
};
typedef std::vector<MOVE>    MVSTK;

MVSTK * Get_path(UINT v) {
  MVSTK * path = new MVSTK();
  UINT cursor = v;
  while(cursor > 1) {
    if (cursor % 2 == 0) {
      path->push_back(E_LEFT);
    } else {
      path->push_back(E_RIGHT);
    }
    cursor /= 2;
  }
  return path;
}

UINT Calc_path_num(MVSTK *orig) {
  MVSTK *pStack = new MVSTK();
  for (UINT i = 0; i < orig->size(); i++) {
    MOVE t = (*orig)[i];
    pStack->push_back(t);
  }
  UINT cursor = 1;
  while(!pStack->empty()) {
    if (pStack->back() == E_LEFT) {
      cursor *= 2;
    } else {
      cursor = cursor * 2 + 1;
    }
    pStack->pop_back();
  }
  return cursor;
}


template <typename T>
class BiTreeNodeT {
public:

  BiTreeNodeT   *_parent;
  BiTreeNodeT   *_lhs;
  BiTreeNodeT   *_rhs;

  UINT                 lv;
  UINT                 lv_num;
  T                    _data;
  UINT                 total_num;

  int print() {
    std::cout << "\n LV:" << lv << ", LV_pos:" << lv_num << ", global_pos:" << total_num << "\n";
    return total_num;
  }

  BOOL is_left_null() {
    return (_lhs == NULL) || (_lhs != NULL && _lhs->_data != 0);
  }

  BOOL can_add_left() {
    return _lhs == NULL;
  }

  BOOL is_right_null() {
    return (_rhs == NULL) || (_rhs != NULL && _rhs->_data != 0);
  }

  BOOL can_add_right() {
    return _rhs == NULL;
  }

  void set_data(UINT64 i) {
    _data = i;
  }
};

template <typename T>
class BiTreeIterator;

template <typename T>
class BiTree{
private:
  std::vector<BiTreeNodeT<T> *> nodes;
  std::vector<BiTreeIterator<T> *> its;
  BiTreeNodeT<T> * root;
  UINT _max_pos;

public:

  BiTree(){
    _max_pos = 0;
    root = NULLPTR;
  }

  UINT size(){
    return (UINT) nodes.size();
  }

  void clear();

  BiTreeIterator<T> *iterator();
  BiTreeNodeT<T> * getRoot(){
    return root;
  }

  void setRoot(BiTreeNodeT<T> * node){
    root = node;
  }

  void insert (BiTreeNodeT<T> * obj, UINT pos_num){
    nodes.push_back(obj);
    if(pos_num >= _max_pos){
      _max_pos = pos_num;
    }
  }

  void Print(FILE * fptr);

  UINT get_max_pos() const;

};

template <typename T>
class BiTreeIterator{
private:
  BiTreeNodeT<T> *_root;
  BiTreeNodeT<T> *_node;
  BiTree<T>         *_tree;
  MVSTK          *path_stack;

public:

  BiTreeIterator(BiTree<T> & tree){
    _tree = &tree;
    _node = NULLPTR;
    _root = NULLPTR;
    path_stack = NULLPTR;
    sync();

  }

  BiTreeIterator(BiTree<T> * tree){
    _tree = tree;
    _node = NULLPTR;
    _root = NULLPTR;
    path_stack = NULLPTR;
    sync();
  }

  INT Remove() {
    BiTreeNodeT<T> * node = _node;
    if(node->_parent){
      if (node->_parent->_lhs == node){
        node->_parent->_lhs   =  NULLPTR;
        path_stack->pop_back();
        _node                 =  node->_parent;
        return 0;
      }
      if (node->_parent->_rhs == node){
        node->_parent->_rhs   =  NULLPTR;
        path_stack->pop_back();
        _node                 =  node->_parent;
        return 0;
      }
    }
    return 1;
  }

  void sync(){
    if(_tree->getRoot() == NULLPTR){
      BiTreeNodeT<T> * node = new BiTreeNodeT<T>();
      node->_lhs = NULLPTR;
      node->_rhs = NULLPTR;
      node->_parent = NULLPTR;
      node->_data = 0;
      _node = node;
      _root = node;
      _tree->setRoot(node);
      _tree->insert(node, 1);
    }else if(_root != _tree->getRoot() || _node == NULLPTR){
      _root = _tree->getRoot();
      _node = _root;
      if(path_stack){
        delete path_stack;
      }
      path_stack = new MVSTK();
    }
  }

  BiTreeNodeT<T> * Add_left (UINT val){
    sync();
    BiTreeNodeT<T> *parent = _node;
    if(parent) {
      if(parent->_lhs != NULLPTR) {
        Is_True(parent->_lhs == NULLPTR,
                ("Parent already has a left child \n"));
      }
    }
    BiTreeNodeT<T> *node = new BiTreeNodeT<T>();
    node->_lhs = NULLPTR;
    node->_rhs = NULLPTR;
    node->_parent = parent;
    node->_data = val;
    if(parent) {
      parent->_lhs = node;
      node->lv = parent->lv + 1;
      node->total_num = parent->total_num * 2;
      node->lv_num = node->total_num - (INT) (pow(2, node->lv - 1));
    }else{
      node->lv = 1;
      node->lv_num = 1;
      node->total_num = 1;
    }
    _node = node;
    _tree->insert(node, Calc_path_num(path_stack));
    return node;
  }

  BiTreeNodeT<T> *Add_right (UINT val){

    sync();

    BiTreeNodeT<T> * parent = _node;

    Is_True((parent != NULLPTR) && (parent->_rhs == NULLPTR),
            ("Parent already has a left child , [P:%d] , [C:%d] , inserting-val:%d \n", parent->print(), parent->_rhs->print(), val));

    BiTreeNodeT<T> *node = new BiTreeNodeT<T>();
    node->_lhs        = NULLPTR;
    node->_rhs        = NULLPTR;
    node->_data       = val;
    node->_parent     = parent;

    if(parent) {
      parent->_rhs    = node;
      node->lv        = parent->lv + 1;
      node->total_num = parent->total_num * 2 + 1;
      node->lv_num    = node->total_num - (UINT) pow(2, node->lv - 1);
    }
    _node = node;
    _tree->insert(node, Calc_path_num(path_stack));
    return node;
  }

  void Goto_pos(UINT pos_num){
    sync();
    MVSTK *temp_path = Get_path(pos_num);
    path_stack = Get_path(pos_num);
    _node = _root;
    while(!temp_path->empty()){
      MOVE t = temp_path->back();
      temp_path->pop_back();
      if(t == E_LEFT){
        if(_node->_lhs == NULLPTR){
          Add_left(0);
        }else{
          _node = _node->_lhs;
        }
      }else if(t == E_RIGHT) {
        if(_node->_rhs == NULLPTR){
          Add_right(0);
        }else{
          _node = _node->_rhs;
        }
      }
    }
  }

  void Goto_pos_no_create(UINT pos_num){
    sync();
    MVSTK *temp_path = Get_path(pos_num);
    path_stack = Get_path(pos_num);
    _node = _root;
    while(!temp_path->empty()){
      MOVE t = temp_path->back();
      temp_path->pop_back();
      if(t == E_LEFT){
        if(_node->_lhs == NULLPTR){
          _node = NULLPTR;
          path_stack = NULLPTR;
          return;
        }else{
          _node = _node->_lhs;
        }
      }else if(t == E_RIGHT) {
        if(_node->_rhs == NULLPTR){
          _node = NULLPTR;
          path_stack = NULLPTR;
          return;
        }else{
          _node = _node->_rhs;
        }
      }
    }
  }

  void Go_left(){
    sync();
    if(_node != NULLPTR){
      if(_node->_lhs){
        path_stack->push_back(E_LEFT);
        _node = _node->_lhs;
      }else{
        Add_left(0);
      }
    }else{
      Add_left(0);
    }
  }

  void Go_right(){
    sync();
    if(_node != NULLPTR){
      if(_node->_rhs){
        path_stack->push_back(E_RIGHT);
        _node = _node->_rhs;
      }else{
        Add_right(0);
      }
    }else{
      Add_left(0);
    }
  }

  INT Set_val(INT64 val){
    if(_node){
      _node->set_data(val);
    }
    return 0;
  }

  INT64 Get_val(){
    if(_node) {
      return _node->_data;
    }else{
      return 0;
    }
  }

  void clear(){
    _node = NULLPTR;
    _root = _tree->getRoot();
    if(path_stack) {
      delete path_stack;
    }
    path_stack = new MVSTK();
  }

  void Go_up(){
    sync();
    if(_node != _root && _node->_parent != NULLPTR){
      _node = _node->_parent;
      if(!path_stack->empty()) {
        path_stack->erase(path_stack->begin());
      }
    }
  }

  BOOL Is_left(T i) {
    if(_node->_lhs == NULLPTR) return i == 0;
    return _node->_lhs->_data == i;
  }

  BOOL Is_right(T i) {
    if(_node->_rhs == NULLPTR) return i == 0;
    return _node->_rhs->_data == i;
  }

  BOOL Is_Root() {
    sync();
    if(_node == _root) {
      return TRUE;
    }
    return FALSE;
  }
};

template <typename T>
BiTreeIterator<T> *BiTree<T>::iterator() {
  BiTreeIterator<T> * it = new BiTreeIterator<T>(this);
  its.push_back(it);
  return it;
}

template <typename T>
void BiTree<T>::clear() {
  nodes.clear();
  for (UINT i = 0; i < its.size(); ++i) {
    (its[i])->clear();
  }
  root = NULLPTR;
  _max_pos = 0;
}

template <typename T>
UINT BiTree<T>::get_max_pos() const {
  return _max_pos;
}

template <typename T>
void BiTree<T>::Print(FILE *fptr) {
  fprintf(fptr, "[BiTree] nodes:%d, max_pos:%d as follows : \n", size(), get_max_pos());
  UINT     i, lines   = 0;
  UINT     j          = 0;
  UINT     line_width = 0;
  UINT     max_width  = 0;
  UINT     now_max    = _max_pos;
  BiTreeIterator<T> * bi = iterator();

  for (i = 1; i <= now_max; i *= 2, lines++); //calc for lines
  max_width = i; // set max_width
  fprintf(fptr,"[BiTree] lines:%d -- \n", lines);

  for (i = 0, line_width = 1; i < lines; i++, line_width *= 2) {
    for (j = 0; j < (max_width - line_width); j++) {
      putchar(' ');
    }
    for (j = 0; j < line_width; j++) {
      bi->Goto_pos_no_create(line_width + j);
      fprintf(fptr, "%c ", (T) bi->Get_val());
    }
    fprintf(fptr, "\n");
  }
}

enum KIND{
  LOWER = 1,
  ROOT = 2,
  PRINT = 3
};

template <typename T>
class BiTreeAlgo{
public:
  static INT Check_all_leaves_recurse(BiTreeNodeT<T> * now, INT &count){
    if(now){
      Check_all_leaves_recurse(now->_lhs, count);
      Check_all_leaves_recurse(now->_rhs, count);
      if(now->_data != 0 && !now->is_left_null() && !now->is_right_null()){
        count ++;
      }
    }
    return count;
  }

  static INT Print_pre_leaves_recurse(BiTreeNodeT<T> * now){
    if(now){
      if(now->_data != 0 && now->_data != '#'){
        cout << (T) now->_data << " ";
      }
      Print_pre_leaves_recurse(now->_lhs);
      Print_pre_leaves_recurse(now->_rhs);
    }
    return 0;
  }

  static INT Print_mid_leaves_recurse(BiTreeNodeT<T> * now){
    if(now){
      Print_mid_leaves_recurse(now->_lhs);
      if(now->_data != 0 && now->_data != '#'){
        cout << (T) now->_data << " ";
      }
      Print_mid_leaves_recurse(now->_rhs);
    }
    return 0;
  }

  static INT Print_after_leaves_recurse(BiTreeNodeT<T> * now){
    if(now){
      Print_after_leaves_recurse(now->_lhs);
      Print_after_leaves_recurse(now->_rhs);
      if(now->_data != 0 && now->_data != '#'){
        cout << (T) now->_data << " ";
      }
    }
    return 0;
  }

  static INT Print_bfs_leaves_recurse(BiTreeNodeT<T> * now, KIND lower){
    if(now){
      if(now->_data != 0 && now->_data != '#' && lower != LOWER){
        cout << (T) now->_data << " ";
      }
      if(lower == PRINT){
        return 0;
      }
      Print_bfs_leaves_recurse(now->_lhs, PRINT);
      Print_bfs_leaves_recurse(now->_rhs, PRINT);
      Print_bfs_leaves_recurse(now->_lhs, LOWER);
      Print_bfs_leaves_recurse(now->_rhs, LOWER);
    }
    return 0;
  }



  static INT Mirrorfy(BiTreeNodeT<T> * now){
    if(now){
      Mirrorfy(now->_lhs);
      Mirrorfy(now->_rhs);
      BiTreeNodeT<T> * temp = now->_lhs;
      now->_lhs = now->_rhs;
      now->_rhs = temp;
    }
    return 0;
  }
};



INT main() {

  INT                         trials , num;
  std::string                 type;
  BiTree<CHAR>               chartree;
  BiTreeIterator<CHAR>      *it = chartree.iterator();


  string      all_data;
  std::cin    >> trials;
  for (UINT j = 0; j < trials; j++) {
    chartree.clear();
    cin >> all_data;
    it->Goto_pos(1);
    UINT i = 0;
    while(TRUE){
      if(all_data.size() <= i) break;
      num = all_data[i];
      if(it->Is_left(0)){
        // can go
        it->Go_left();
        it->Set_val(num);
        if(num == '#'){
          it->Go_up();
        }
        i++;
      }else if(it->Is_right(0)){
        // can go
        it->Go_right();
        it->Set_val(num);
        if(num == '#'){
          it->Go_up();
        }
        i++;
      }else{
        if(it->Is_Root()){
          break; // Failed
        }else{
          it->Go_up();
        }
      }
    }
    // 版权所有, 过程可参考实验8/9已提交内容。
    BiTreeAlgo<CHAR>::Mirrorfy(chartree.getRoot());
    if(Printing()) {
      chartree.Print(stdout);
      Is_Print(TRUE, ("%s", "-------- END --------\n"));
    }
    BiTreeAlgo<CHAR>::Print_pre_leaves_recurse(chartree.getRoot());
    printf("\n");
    BiTreeAlgo<CHAR>::Print_mid_leaves_recurse(chartree.getRoot());
    printf("\n");
    BiTreeAlgo<CHAR>::Print_after_leaves_recurse(chartree.getRoot());
    printf("\n");
    BiTreeAlgo<CHAR>::Print_bfs_leaves_recurse(chartree.getRoot(), ROOT);
    printf("\n");
  }

  getchar();
  getchar();
  return 0;
}

/**



**/
