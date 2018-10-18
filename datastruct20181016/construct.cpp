//
// Created by xc5 on 23/9/2018.
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
typedef         long          INT64;
typedef         unsigned int  UINT;
typedef         unsigned long UINT64;
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

class BiTreeNodeT {
public:
  struct BiTreeNodeT   *_parent;
  struct BiTreeNodeT   *_lhs;
  struct BiTreeNodeT   *_rhs;
  UINT                 lv;
  UINT                 lv_num;
  UINT64               _data;
  UINT                 total_num;
  int print() {
    std::cout << "lv:" << lv << ", lv_num:" << lv_num << ", total_num:" << total_num << endl;
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

};


class BiTree{
private:
  std::vector<BiTreeNodeT *> nodes;

public:

  UINT size(){
    return nodes.size();
  }

  void clear(){
    nodes.clear();
  }

  BiTreeNodeT * Add_node_as_left(UINT64 val, BiTreeNodeT *parent){
    if(parent) {
      Is_True(parent->_lhs == NULL,
              ("Parent already has a left child , [P:%d] , [C:%d] \n", parent->print(), parent->_lhs->print()));
    }
    BiTreeNodeT *node = new BiTreeNodeT();
    node->_lhs = NULL;
    node->_rhs = NULL;
    node->_parent = parent;
    node->_data = val;
    if(parent) {
      parent->_lhs = node;
      node->lv = parent->lv + 1;
      node->total_num = parent->total_num * 2;
      node->lv_num = node->total_num - pow(2, node->lv - 1);
    }else{
      node->lv = 1;
      node->lv_num = 1;
      node->total_num = 1;
    }
    nodes.push_back(node);
    return node;
  }

  BiTreeNodeT * Add_node_as_right(UINT val, BiTreeNodeT *parent){
    Is_True((parent != NULL) && (parent->_rhs == NULL),
            ("Parent already has a left child , [P:%d] , [C:%d] , inserting-val:%d \n", parent->print(), parent->_rhs->print(), val));
    BiTreeNodeT *node = new BiTreeNodeT();
    node->_lhs        = NULL;
    node->_rhs        = NULL;
    node->_data       = val;
    node->_parent     = parent;
    if(parent) {
      parent->_rhs    = node;
      node->lv = parent->lv + 1;
      node->total_num = parent->total_num * 2 + 1;
      node->lv_num = node->total_num - pow(2, node->lv - 1);
    }else{
      node->lv = 1;
      node->lv_num = 1;
      node->total_num = 1;
    }

    nodes.push_back(node);
    return node;
  }
  BiTreeNodeT * Remove_Node_Subtree(BiTreeNodeT * node){
    if(node->_parent){
      if(node->_parent->_lhs == node){
        node->_parent->_lhs = NULL;
      }
      if(node->_parent->_rhs == node){
        node->_parent->_rhs = NULL;
      }
    }
    return node;
  }
};


enum MOVE{
  E_LEFT,
  E_RIGHT
};

static BiTree                  tree_1;
static BiTreeNodeT            *root = NULL;
UINT                           fail;

void Insert_Node(UINT64 ch, stack<BiTreeNodeT *> &);


void Clear(){
  root = NULL;
  tree_1.clear();
}

INT leav_count = 0;

INT Check_all_leaves_recurse(BiTreeNodeT * now){
  if(now){
    Check_all_leaves_recurse(now->_lhs);
    Check_all_leaves_recurse(now->_rhs);
    if(now->_data != 0 && !now->is_left_null() && !now->is_right_null()){
      leav_count ++;
    }
  }
  return leav_count;
}

INT Print_pre_leaves_recurse(BiTreeNodeT * now){
  if(now){
    if(now->_data != 0){
      cout << (CHAR) now->_data;
    }
    Print_pre_leaves_recurse(now->_lhs);
    Print_pre_leaves_recurse(now->_rhs);
  }
  return leav_count;
}

INT Print_mid_leaves_recurse(BiTreeNodeT * now){
  if(now){
    Print_mid_leaves_recurse(now->_lhs);
    if(now->_data != 0){
      cout << (CHAR) now->_data;
    }
    Print_mid_leaves_recurse(now->_rhs);
  }
  return leav_count;
}

INT Print_after_leaves_recurse(BiTreeNodeT * now){
  if(now){
    Print_after_leaves_recurse(now->_lhs);
    Print_after_leaves_recurse(now->_rhs);
    if(now->_data != 0){
      cout << (CHAR) now->_data;
    }
  }
  return leav_count;
}

UINT64 getVal(stack<MOVE> *pStack, BiTreeNodeT* root) {
  if(!root) return 0;
  for(;pStack->size() > 0;){
    MOVE t = pStack->top();
    pStack->pop();
    if(t == E_LEFT && root->_lhs != NULL){
      root = root->_lhs;
    }else if(t == E_RIGHT && root->_rhs != NULL){
      root = root->_rhs;
    }else{
      return 0;
    }
  }
  return root->_data;
}

stack<MOVE> *getPath(UINT j, UINT v) {
  stack<MOVE> * path = new stack<MOVE>();
  UINT cursor = j + v;
  while(cursor > 1) {
    if (cursor % 2 == 0) {
      path->push(E_LEFT);
    } else {
      path->push(E_RIGHT);
    }
    cursor /= 2;
  }
  return path;
}


void Print_all(){
  UINT     i;
  UINT     lines  = 0;
  UINT     j      = 0;
  UINT     line_width;
  UINT     max_width = 0;

  for (i = 1; i <= tree_1.size(); i *= 2, lines++); //calc for lines
  max_width = i; // set max_width

  printf("[Print_all]\nlines:%d\n", lines);

  for (i = 0, line_width = 1; i < lines; i++, line_width *= 2) {
    for (j = 0; j < (max_width - line_width); j++) {
      putchar(' ');
    }
    for (j = 0; j < line_width; j++) {
      std::stack<MOVE> *path = getPath(j, line_width);
      UINT64 val = getVal(path, root);
      cout << (char) val << ",";
    }
    cout << endl;
  }
}

INT main() {

  INT                     trials, count , num, parsed;
  std::string             type;
  stack<BiTreeNodeT *>    cur_parents;
  CHAR                    ch;

  std::cin    >> trials;
  for(UINT i = 0; i < trials; i++) {
    parsed = 0;
    for(;(ch = (CHAR) getchar()) && ch != '\n' && ch != EOF && ch != '\r';){
      parsed ++;
      if(isalpha(ch)) {
        Insert_Node((UINT) ch, cur_parents);
      }else if(ch == '0'){
        Insert_Node((UINT) ch, cur_parents);
        cur_parents.pop();
      }else{
        break;
      }
    }

    if(Printing()) {
      Is_Print(Printing(), ("%s", ("-------- END --------")));
    }

    if(parsed > 0) {
      leav_count = 0;
      Is_Print(Printing(), ("leaves: "));
      Print_pre_leaves_recurse(root);
      cout << endl;
      Print_mid_leaves_recurse(root);
      cout << endl;
      Print_after_leaves_recurse(root);
      cout << endl;

      // =========================================
      // Clearing the stacks used as intermediate
      // =========================================

      Clear();
      while (cur_parents.size() > 0) cur_parents.pop();
    }else{
      i--;
      fail++;
      if(fail > 4){
        break;
      }
    }
  }

  getchar();
  getchar();
  return 0;
}

void Insert_Node(UINT64 data_, std::stack<BiTreeNodeT*> &cur_parents) {

  Is_Print(Printing(), (" -- Adding %c \n", data_));

  if(cur_parents.size() == 0){
    BiTreeNodeT * node = tree_1.Add_node_as_left(data_, NULL);
    root = node;
    cur_parents.push(node);
  }else{
    BiTreeNodeT *top = cur_parents.top();
    for(;;){
      if(top->can_add_left()){
        cur_parents.push(tree_1.Add_node_as_left(data_, top));
        break;
      }else if(top->can_add_right()){
        cur_parents.push(tree_1.Add_node_as_right(data_, top));
        break;
      }else{
        if(top->_parent) {
          top = top->_parent;
        }else{
          Is_True(FALSE, ("[Error] cannot add to tree %c", data_));
        }
      }
    }
  }

  Is_Print(Printing(), ("%s", (Print_all(), "-----------------------")));
}

/**
     * 样例输入
      3
      AB0C00D00
      AB00C00
      ABC00D00E00
      样例输出
      2
      2
      3
     * */
//.push(type);