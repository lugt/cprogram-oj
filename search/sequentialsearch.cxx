//
// Created by xc5 on 22/11/2018.
//

#include <iostream>
#include <stdio.h>

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

void one_trial(){
  INT   vex_count;
  INT   qcount;

  cin >> vex_count;

  INT  *nums = new INT[vex_count];
  INT   num;

  for(UINT i = 0; i < vex_count; i++ ){
    cin >> num;
    nums[i] = num;
  }

  cin >> qcount;

  INT   q;

  for(UINT i = 0; i < qcount; i++){

    INT flag = -1;
    cin >> q;
    for(UINT a = 0; a < vex_count; a++){
      if(nums[a] == q){
        flag = a;
        break;
      }
    }

    if (flag >= 0) {
      cout << (flag+1) << endl;
    } else {
      cout << "error" << endl;
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

