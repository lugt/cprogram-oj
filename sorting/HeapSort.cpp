
//
// Created by lugt on 2018/11/27.
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
using std::swap;

#define INT_MAX 0x3f3f3f3f

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

inline BOOL Echo(){
  return FALSE;
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

void heapify(INT *nums, INT loc, INT n)
{
  INT left = 2 * loc + 1;
  INT right = 2 * loc + 2;
  if (left < n) {
    if (right < n) {
      if (nums[left] > nums[right]) {
        if (nums[right] < nums[loc]) {
          swap(nums[right], nums[loc]);
          heapify(nums, right, n);
        }
      } else {
        if (nums[left] < nums[loc]) {
          swap(nums[left], nums[loc]);
          heapify(nums, left, n);
        }
      }
    } else {
      if (nums[left] < nums[loc]) {
        swap(nums[left], nums[loc]);
        heapify(nums, left, n);
      }
    }
  }
}

void Print_hash_table(INT ***hash, INT len){
  ff(len, i, {
      isnull(hash[i], { cout << "NULL "; });	      
      isvalid(hash[i], {
	  INT **arr = hash[i];
	  ff(1000, j, {
	    isnull(arr[j], { cout << "NULL "; break; });
	    isvalid(arr[j], { cout << *(arr[j]) << " " ; });
	  });
      });
  });
  cout << endl;
}

void heap_sort(INT n)
{
  INT *nums;
  nums = new INT[n];
  for (INT i = 0; i < n; i++)
    cin >> nums[i];
  for (INT i = n / 2; i >= 0; i--) {
    heapify(nums, i, n);
  }

  cout << n << ' ';
  for (INT i = 0; i < n; i++) {
    cout << nums[i];
    if (i != n - 1)
      cout << ' ';
  }
  cout << endl;
  for (INT t = n - 1; t >= 1; t--) {
    swap(nums[0], nums[t]);
    heapify(nums, 0, t);
    cout << n << ' ';
    for (INT i = 0; i < n; i++) {
      cout << nums[i];
      if (i != n - 1)
        cout << ' ';
    }
    cout << endl;
  }
}

void one_trial(){
  // what should I do?
  INT    count = 0;
  cin >> count;
  heap_sort(count);
}


INT main(){
  //  INT trials = 0;
  //cin >> trials;
  //while(trials--)
  one_trial();
  getchar();
  getchar();
  getchar();
}

/**
8
11 22 33 44 55 66 77 88
3
22
88
99*/
