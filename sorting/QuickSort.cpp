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

void ip (INT *a, INT i, INT j) {
    INT m = a[i];
    a[i] = a[j];
    a[j] = m;
}

void qss (INT *a, INT dc, INT lo, INT hi){
  if(lo >= hi) return;
  INT pivot;
  INT i     = lo;
  INT j     = hi;
  INT flag = 0;
  while(i<j) {
    if (a[i] > a[j]) {
      pivot = a[i];
      a[i] = a[j];
      a[j] = pivot;
      if (flag == 0) {
        i++;
        flag = 1;
      } else {
        j--;
        flag = 0;
      }
    } else {
      if (flag == 0) {
        j--;
      } else {
        i++;
      }
    }
  }
  pr(a, dc);
  qss(a, dc, lo, i - 1);
  qss(a, dc, i + 1, hi);
}

void ss (INT *a, INT dc){
  // sort by quicksort
  INT pivot = a[0];
  qss(a, dc, 0, dc - 1);
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

/*
 * int n;
	cin>>n;
	int *array= new int[n+ 5];
	for(int i= 1; i<= n ;i++)
	   cin>>array[i];

	for(int i= 2; i<= n; i++){
		array[0]= array[i];
		for(int j= i- 1; j>= 1; j--){
			if(array[j]> array[0]){
				array[j+ 1]= array[j];
				array[j]= array[0];
			}
			else{
				array[j+ 1]= array[0];
				break;
			}
		}
		print(array, n);
 */
