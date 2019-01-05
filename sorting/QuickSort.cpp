#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

// STL Includings
using std::cout;
using std::cin;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

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
#define ff(end, i, func) for(INT i = 0; i < end; i++) func;
#define fe(start, end, i, func) for(INT i = start; i < end; i++) func;
#define isnull(v, func) if((v) == NULL) {func};
#define isvalid(v, func) if((v) != NULL) {func};
#define d(line) if(Echo()) { line; }

INTPTR "C" {
INTPTR void *Get_some_thing(void *b, int c, size_t len);
INTPTR int Put_some_thing(const char *s1, const char *s2);
}

inline BOOL Echo(){
  return FALSE;
}

template <typename T>
BOOL compare(T a, T b){
  return (a > b);
}

template<typename T>
BOOL comp_eq(T a, T b) {
  return a == b;
}

INT rrn = 0;
void pr (INT *a, INT dc){
  d(cout << "Round " << ( rrn ++ ) << " [");
  ff(dc, i, {
      cout << a[i] << ((i != dc - 1) ? " " : "");
  });
  d(cout << "]");
  cout << endl;
}

void ip (INT *a, INT j, INT i, INT g, INT dc) {
  if((i + j) < dc && (i + j + g) < dc){
    INT m = a[i+j];
    a[i+j] = a[i+j+g];
    a[i+j+g] = m;
  }
}

void ss (INT *a, INT dc){
  // sort by gap of dc
}

void one_trial(){
  // what should I do?
  INT   dc;
  cin >> dc;
  INT  *a = new INT[dc];
  ff (dc, i, {
      cin >> a[i]; 
  });
  d(cout << "Init [");
  d(ff (dc, i, {
      cout << a[i] << " "; 
  }));
  ss(a, dc);
  d(cout << "]" << endl);
  //  cout << endl;
}

INT main(){
  INT trials = 0;
  cin >> trials;
  while(trials--)
    one_trial();
  getchar();
  getchar();
  getchar();
}
