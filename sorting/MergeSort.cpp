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



void ip (INT *a, INT i, INT j) {
    INT m = a[i];
    a[i] = a[j];
    a[j] = m;
}

class Q{
public:
  bool operator<(Q &second){
    return data->compare(*second.data) > 0;
  }

  void set(std::string *pString) {
    data = pString;
  }
  std::string *data;
};

INT rrn = 0;
void pr (Q *a, INT dc){
  d(cout << "Round " << ( rrn ++ ) << " [");
  ff(dc, i, {
    cout << a[i].data->c_str() << ((i != dc - 1) ? " " : "");
  });
  d(cout << "]");
  cout << endl;
}

void merge_sort(Q arr[], int len) {
  Q   *a = arr;
  Q   *b = (Q *) malloc(len * sizeof(Q));
  INT  seg, start;
  for (seg = 1; seg < len; seg += seg) {
    for (start = 0; start < len; start += seg + seg) {
      INT  low  = start,
          mid  = std::min(start + seg, len),
          high = std::min(start + seg + seg, len);
      INT  k = low;
      INT  start1 = low, end1 = mid;
      INT  start2 = mid, end2 = high;
      while (start1 < end1 && start2 < end2)
        b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
      while (start1 < end1)
        b[k++] = a[start1++];
      while (start2 < end2)
        b[k++] = a[start2++];
    }
    std::swap(a, b);
    pr(a, len);
  }
  if (a != arr) {
    int i;
    for (i = 0; i < len; i++)
      b[i] = a[i];
    b = a;
  }
  free(b);
}

void ss (INT dc){
  Q *arr = new Q[dc];
  ff (dc, i, {
    std::string *str = new std::string();
    cin >> (*str);
    arr[i].set(str);
  });
  merge_sort(arr, dc);
}

void one_trial(){
  // what should I do?
  INT   dc;
  cin >> dc;
  ss(dc);
  cout << endl;
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
