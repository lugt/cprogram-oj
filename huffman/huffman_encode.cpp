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

vector<string> output0;
map<CHAR, string> huffman_map;

template<typename T>
void print_leaf(BiNode<T> *node){
  if (node != NULL){
    print_leaf(node->_lhs);
    if (node->_lhs == NULL && node->_rhs == NULL){
      stringstream out;
      huffman_map.insert(std::make_pair((CHAR) node->_data, node->huffman_code));
      out << (CHAR) node->_data <<  " :" << node->huffman_code;
      output0.push_back(out.str());
    } //fprintf(stderr, "%c\t%s\n", node->_data, node->huffman_code.c_str());
    print_leaf(node->_rhs);
  }
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

template<typename T>
INT huffman_tree_create(
  BiNode<T> **tree,
  map<CHAR, UINT> &word)
{
  vector<BiNode<T> *>       huffman_tree_node;
  map<CHAR, UINT>::iterator it_t;

  for (it_t = word.begin(); it_t != word.end(); it_t++){
    BiNode<T> *node = new BiNode<T>();
    node->_data = it_t->first;
    node->_weight = it_t->second;
    node->_lhs = NULL;
    node->_rhs = NULL;
    huffman_tree_node.push_back(node);
  }

  while (huffman_tree_node.size() > 0){ // Has nodes
    sort(huffman_tree_node.begin(), huffman_tree_node.end(), sort_by_weight);
    if (huffman_tree_node.size() == 1){ // Only one root
      *tree = huffman_tree_node[0];
      huffman_tree_node.erase(huffman_tree_node.begin()); //remove last one
    }else{
      BiNode<T> *node_1 = huffman_tree_node[0];
      BiNode<T> *node_2 = huffman_tree_node[1];
      huffman_tree_node.erase(huffman_tree_node.begin());
      huffman_tree_node.erase(huffman_tree_node.begin());
      BiNode<T> *node = new BiNode<T>();
      node->_weight = node_1->_weight + node_2->_weight;
      if(node_1->_weight < node_2->_weight) {
        node->_lhs = node_1;
        node->_rhs = node_2;
      }else{
        node->_lhs = node_1;
        node->_rhs = node_2;
        //node->_lhs = node_2;
        // node->_rhs = node_1;
      }
      node_1->_parent = node;
      node_2->_parent = node;
      huffman_tree_node.push_back(node);
    }
  }

  return 0;
}

INT main(){
  map<CHAR, UINT> inputmap;
  INT             trails    = 0;
  UINT            count     = 0;
  CHAR            ch        = 0;
  vector<CHAR>    chs;
  BiNode<CHAR>   *tree;

  cin  >>  trails;
  for(UINT i = 0; i < trails; i++){

    chs.clear();
    huffman_map.clear();
    inputmap.clear();
    tree = NULL;

    cin >> count;
    for (UINT j = 0; j < count; j++){
      cin >> ch;
      if(!ch || ch == ' '){
        j--;
        continue;
      }
      chs.push_back(ch);
    }

    for (UINT j = 0; j < count; j++){
      UINT num = 0;
      cin >> num;
      inputmap.insert(std::make_pair(chs[j], num));
    }

    huffman_tree_create(&tree, inputmap);
    get_huffman_code(tree);
    print_leaf(tree);

    if(Echo()){
      real_print();
    }

    for(UINT one = 0; one < chs.size() ; one++) {
      if(huffman_map.count(chs[one]) == 0){
        cout << "ERROR!";
      }
      cout << chs[one] << " :" << huffman_map.at((CHAR) chs[one]) << endl;
    }

    string encode_plain;
    cin >> encode_plain;
    if(encode_plain == ""){
      cin >> encode_plain;
    }

    for(UINT one = 0; one < encode_plain.size(); one++){
      cout << huffman_map.at(encode_plain[one]);
    }
    cout << endl;

    string decode_text;
    cin >> decode_text;
    BiNode<CHAR> *start = tree;

    stringstream outpn;
    BOOL is_error = FALSE;
    for(UINT one = 0; one < decode_text.size(); one++){
      if(start == NULLPTR) {
        is_error = TRUE;
        break;
      }
      if(decode_text[one] == '0'){
          start = start->_lhs;
          if(start->_data > 0){
            outpn << (CHAR) start->_data;
            start = tree;
          }
      }else if(decode_text[one] == '1'){
          start = start->_rhs;
          if(start->_data > 0){
            outpn << (CHAR) start->_data;
            start = tree;
          }
      }
    }
    if(is_error || start != tree){
      cout << "error!";
    }else{
      cout << outpn.str();
    }
    cout << endl;
  }
  return 0;
}

void real_print() {
  for(INT i = output0.size() - 1; i >= 0 ; i--){
    cout << output0.at(i) << endl;
  }
  output0.clear();
}

/**

样例输入
2 5 A B C D E 15 4 4 3 2
ABDEC
00000101100
4 A B C D
7 5 2 4
ABAD
1110110

样例输出
A :1
B :010
C :011
D :001
E :000
1010001000011
error!
A :0
B :10
C :110
D :111
0100111
DAC

*/