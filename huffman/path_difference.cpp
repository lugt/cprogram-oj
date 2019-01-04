//
// Created by lugt on 2018/10/28.
//

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
 
// STL Includings
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cstring>
#include <string.h>
#include <memory.h>
#include <sstream>
 
#define Is_Echo(parm) if(Echo()) printf parm
#define Is_True(cond, parm) if(!cond){ printf parm; exit(1);}
 
using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::endl;
using std::map;
using std::list;
using std::stack;
using std::vector;
using std::stringstream;
using std::string;
using std::queue;
using std::sort;
 
typedef int                    INT;
typedef unsigned int           UINT;
typedef long long int          INT64;
typedef bool                   BOOL;
typedef long long unsigned int UINT64;
typedef vector<INT>            INTVEC;
typedef vector<UINT>           UINTVEC;
typedef vector<UINT64>         UINT64VEC;
typedef vector<double>         F8VEC;
typedef double                 F8;
typedef char                   CHAR;
typedef char*                  CHPTR;
typedef char**                 CHPPTR;
typedef const char*            CCHPTR;
typedef const char**           CCHPPTR;
#define NULLPTR NULL
#define FALSE ((BOOL) 0)
#define TRUE  ((BOOL) 1)
 
inline BOOL Echo(){
  return FALSE;
}
 
enum MOVE {
    E_LEFT,
    E_RIGHT
};
typedef std::vector<MOVE> MVSTK;
 
MVSTK *Get_path(UINT v) {
  MVSTK *path = new MVSTK();
  UINT cursor = v;
  while (cursor > 1) {
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
  while (!pStack->empty()) {
    if (pStack->back() == E_LEFT) {
      cursor *= 2;
    } else {
      cursor = cursor * 2 + 1;
    }
    pStack->pop_back();
  }
  return cursor;
}
 
 
template<typename T>
class BiNode {
public:
 
    BiNode *_parent;
    BiNode *_lhs;
    BiNode *_rhs;
 
    string huffman_code;
 
    UINT lv;
    UINT lv_num;
    T    _data;
    UINT _weight;
    UINT total_num;
    BOOL _notavail;
 
    int print() {
      std::cout << "\n LV:" << lv << ", LV_pos:" << lv_num << ", global_pos:"
                << total_num << ", weight: " << _weight << "data:" << _data << "\n";
      return total_num;
    }
 
    void set_data(UINT64 i) {
      _data = i;
    }
};
 
 
void real_print();

template<typename T>
UINT find_max(BiNode<T> *pNode, CHAR *max_data, int parent_path);

#define LEN 512
 
BOOL sort_by_weight(void *lhs, void *rhs){
  return ((BiNode<CHAR> *) rhs)->_weight > ((BiNode<CHAR> *)lhs)->_weight;
}
 
template<typename T>
void print_huffman_pre(BiNode<T> *node){
  if (node != NULL){
    if(node->_data){
      fprintf(stderr, "%c\t%d\n", node->_data, node->_weight);
    }else{
      fprintf(stderr, "%c\t%d\n", 'X', node->_weight);
    }
    print_huffman_pre(node->_lhs);
    print_huffman_pre(node->_rhs);
  }
}
template<typename T>
void print_huffman_in(BiNode<T> *node){
  if (node != NULL){
    print_huffman_in(node->_lhs);
    fprintf(stderr, "%c\t%d\n", (node->_data == 0)?'x':node->_data, node->_weight);
    print_huffman_in(node->_rhs);
  }
}

map<CHAR, string> huffman_map;
INT max_path = 0;
CHAR last_lhs = 0;
CHAR last_rhs = 0;

template<typename T>
void print_leaf(BiNode<T> *node, UINT sum){
  if (node != NULLPTR && node->_data != '+'){

    Is_Echo(("[print_leaf] visit leaf<%s> : char<%c>, path<%u> \n", node->huffman_code.c_str(), (CHAR) node->_data, sum));
    sum += 1;

    BiNode<T> *cursor = node;
    UINT parent_away = 0;
    UINT max = 0;
    CHAR max_rhs_data = 0;
    while(cursor->_parent != NULLPTR && cursor->_parent != cursor){
      // go up
      max_rhs_data = cursor->_parent->_data;
      if(cursor == cursor->_parent->_lhs){
        max = find_max(cursor->_parent->_rhs, &max_rhs_data, 1);
      }else if(cursor == cursor->_parent->_rhs){
        max = find_max(cursor->_parent->_lhs, &max_rhs_data, 1);
      }else{
        Is_True(FALSE, ("cannot traverse parent, does not know left or right! cursor<%c>, parent<%c>",
          cursor->_data, cursor->_parent->_data));
      }
      cursor = cursor->_parent;
      parent_away ++;
      if(parent_away + max > max_path){
        max_path = parent_away + max;
        last_lhs = node->_data;
        last_rhs = max_rhs_data;
      }
    }

    print_leaf(node->_lhs, sum);
    print_leaf(node->_rhs, sum);
  }
}

template<typename T>
UINT find_max(BiNode<T> *pNode, CHPTR max_data, INT parent_path) {
  if(pNode != NULL && pNode->_data != '+'){
    Is_Echo(("[find_max] visiting node<%c>, huffman_code<%s> path<%d>\n", pNode->_data, pNode->huffman_code.c_str(), parent_path));
    UINT max = (UINT)parent_path, local_out = 0;
    CHAR local_max = pNode->_data;
    CHAR tobe_max = 0;
    local_out = find_max(pNode->_lhs, &tobe_max, parent_path + 1);
    if(local_out > max){
      max = local_out;
      local_max = tobe_max;
    }
    local_out = find_max(pNode->_rhs, &tobe_max, parent_path + 1);
    if(local_out > max){
      max = local_out;
      local_max = tobe_max;
    }
    *max_data = local_max;
    return max;
  }
  return 0;
}

template<typename T>
int get_huffman_code(BiNode<T> *node){
 
  if (node == NULL) return 1;
  BiNode<T>          *p = node;
  queue<BiNode<T> *>  q;
 
  q.push(p);
  while(q.size() > 0){
    p = q.front();
    q.pop();
    if (p->_lhs != NULL){
      q.push(p->_lhs);
      (p->_lhs)->huffman_code = p->huffman_code + "0";
    }
    if (p->_rhs != NULL){
      q.push(p->_rhs);
      (p->_rhs)->huffman_code = p->huffman_code + "1";
    }
  }
  return 0;
}
 
INT main(){
  INT             trails    = 0;
  UINT            num       = 0;
  UINT            count     = 0;
  CHAR            ch        = 0;
  vector<CHAR>    chs;
  BiNode<CHAR>   *tree;
 
  cin  >>  trails;
  for(UINT i = 0; i < (UINT) trails; i++){
 
    chs.clear();
    huffman_map.clear();
    max_path = 0;
    tree = NULL;
 
    string encode_plain;
    cin >> encode_plain;
    if(encode_plain.size() == 0){
      cin >> encode_plain;
    }
 
    BiNode<CHAR> *cursor = tree;
    BiNode<CHAR> *node   = NULLPTR;
    for(UINT one = 0; one < encode_plain.size(); one++){
      if(!tree){
        tree = cursor = node = new BiNode<CHAR>();
        cursor->_data     = encode_plain[one];
        if(encode_plain[one] >= 'A' && encode_plain[one] <= 'Z'){
          chs.push_back(encode_plain[one]);
        }
        cursor->_notavail = FALSE;
        //printf("First : Note->Data %c \n", node->_data);
      }else{
        node = new BiNode<CHAR>();
        node->_notavail = FALSE;
        node->_data     = (CHAR) encode_plain[one];
        //printf("Begin -- Note->Data %c \n", node->_data);
        while(TRUE){
          //  printf("Whiling \n");
            if(cursor->_lhs == NULL){
                cursor->_lhs = node; 
                node->_parent = cursor;
                cursor = node;
            //    printf("Set to left \n");
                break;
            } else if(cursor->_rhs == NULL){
                cursor->_rhs = node;
                node->_parent = cursor;
                cursor = node;
                //printf("Set to right \n");
                break;
            }
            cursor = cursor->_parent;
        }
        if(encode_plain[one] >= 'A' && encode_plain[one] <= 'Z'){
            chs.push_back(encode_plain[one]);
        }
        if((encode_plain[one] >= '0' && encode_plain[one] <= '9') || encode_plain[one] == '#'){
            node->_notavail = TRUE;
            node->_data     = '+';
            cursor = node->_parent;
        }
      }
    }

    get_huffman_code(tree);
    print_leaf(tree, 0);

    if(max_path > 0) {
      cout << max_path << ":" << last_lhs << " " << last_rhs << endl;
    }else{
      cout << max_path << ":" << endl;
    }
  }
   
  getchar();
  getchar();
  getchar();
  getchar();
  getchar();
  getchar();
  return 0;
}

