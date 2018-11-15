//
// Created by 2017152003 on 2018/11/6.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

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

INT         max_d      = 0;  //max distance

inline BOOL Echo(){
  return FALSE;
}

class Node{
public:
  INT x;
  INT y;
  INT computerNo;
  Node(int n, int x_, int y_){
    computerNo = n;
    x = x_;
    y = y_;
  }
};

typedef std::vector<Node *> NGroup;
typedef std::vector<NGroup> NNet;

double calc_distance(Node *a, Node*b){
  return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

void
fix_computer(INT no, NGroup &all, std::map<INT, INT> &numGroupMap, NNet &internet) {
  BOOL      found_group = FALSE;
  std::vector<INT> group_connected;
  for(INT i = 0; i < internet.size(); i++){
    NGroup * group = & internet.at(i);
    for(INT j = 0; j < group->size(); j++){
      Node * node = group->at(j);
      if(calc_distance(node, all.at(no)) <= max_d){
        // OK
        group_connected.push_back(i);
        found_group = TRUE;
        break;
      }
    }
  }
  if(!found_group) {
    INT newGroup = internet.size();
    NGroup *np = new NGroup();
    np->push_back(all[no]);
    internet.push_back(*np);
    numGroupMap.insert(std::make_pair(no, newGroup));
  }else{
    // New Group then
    if(group_connected.size() == 1){
      internet[group_connected[0]].push_back(all[no]);
      numGroupMap.insert(std::make_pair(no, group_connected.at(0)));
    }else if(group_connected.size() > 1){
      NGroup * first = &internet[group_connected[0]];
      for(INT i = 1; i < group_connected.size(); i++){
        //internet[group_connected[0]].
        first->insert(first->end(), internet[group_connected[i]].begin(), internet[group_connected[i]].end());
        for(NGroup::iterator it = internet[group_connected[i]].begin(); it != internet[group_connected[i]].end(); it++ ){
          Node * st = (*it);
          numGroupMap[st->computerNo] = group_connected[0];
        }
        internet[group_connected[i]].clear();
      }
      internet[group_connected[0]].push_back(all[no]);
      numGroupMap.insert(std::make_pair(no, group_connected.at(0)));
    }
  }

}

void one_trial() {
  INT         vex_count  = 0;
  INT         edge_count = 0;
  INT         lhs        = 0;
  INT         rhs        = 0;

  cin         >> vex_count;
  cin         >> max_d;

  std::map<INT, INT>   computerGroupMap;
  NNet                 internet;
  NGroup               all_computers;


  for (UINT i = 0; i < vex_count; i++) {
    INT       x, y;
    cin       >> x >> y;
    all_computers.push_back(new Node(i, x, y));
  }

  std::string action;

  while(cin >> action) {
    // Create Group
    INT computer_no, left, right;
    if (action == "O") {
      cin >> computer_no;
      computer_no --;
      fix_computer(computer_no, all_computers, computerGroupMap, internet);
    }else if (action == "S") {
      cin >> left >> right;
      left--;
      right--;
      INT gp1 = computerGroupMap.count(left) > 0 ? computerGroupMap.at(left) : -1;
      INT gp2 = computerGroupMap.count(right) > 0 ? computerGroupMap.at(right) : -1;
      if (gp1 == gp2 && gp1 != -1) {
        cout << "SUCCESS" << endl;
      } else {
        cout << "FAIL" << endl;
      }
    }
  }
}


INT main(){
  one_trial();
  getchar();
}