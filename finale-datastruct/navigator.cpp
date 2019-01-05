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


class CONTEXT{
public:
  vector<std::string> backward;
  vector<std::string> forward;
};


INT rrn = 0;
void pr (INT *a, INT dc){
  d(cout << "Round " << ( rrn ++ ) << " [");
  ff(dc, i, {
    cout << a[i] << ((i != dc - 1) ? " " : "");
  });
  d(cout << "]");
  cout << endl;
}

void ip (INT *a, INT i, INT j) {
  INT m = a[i];
  a[i] = a[j];
  a[j] = m;
}

void ss (INT *a, INT dc){
  INT * array= new INT[dc + 5];
  ff(dc, o, {
    array[o+1] = a[o];
  })
  for(INT i = 2; i <= dc; i++) {
    array[0] = array[i];
    for (INT j = i - 1; j >= 1; j--) {
      if (array[j] > array[0]) {
        array[j + 1] = array[j];
        array[j] = array[0];
      } else {
        array[j + 1] = array[0];
        break;
      }
    }
    pr(array + 1, dc);
  }
}

using std::string;

static std::string *cur = NULLPTR;

BOOL Parse_command(CONTEXT &ctx, std::string &command){
  std::string host;
  if(command == "QUIT") return false;
  if(command == "VISIT"){
    cin >> host;
    ctx.backward.push_back(*cur);
    ctx.forward.clear();
    cur = new std::string(host);
    cout << host << endl;
  }
  if(command == "BACK"){
    if(cur == NULLPTR || ctx.backward.empty()){
      cout << "Ignored\n";
      return true;
    }
    std::string t = ctx.backward.back();
    ctx.backward.pop_back();
    ctx.forward.push_back(*cur);
    cur = new std::string(t);
    cout << t << endl;
  }
  if(command == "FORWARD"){
    if(cur == NULLPTR || ctx.forward.empty()){
      cout << "Ignored\n";
      return true;
    }
    std::string t = ctx.forward.back();
    ctx.forward.pop_back();
    ctx.backward.push_back(*cur);
    cur = new std::string(t);
    cout << t << endl;
  }
  return true;
}

void one_trial(){
  // what should I do?
  CONTEXT ctx;
  std::string command;
  cur = new std::string("http://www.acm.org/");
  while (true){
    cin >> command;
    if(!Parse_command(ctx, command)){
      break;
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
}
