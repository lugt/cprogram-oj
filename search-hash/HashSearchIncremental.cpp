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

// #define INT_MAX 0x3f3f3f3f

#define Is_Echo(cond, parm) if(cond) printf parm;
#define Is_True(cond, parm) if(!(cond)) {printf parm; getchar(); getchar(); getchar(); exit(1);}

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

INTPTR "C" {
INTPTR void *Get_some_thing(void *b, int c, size_t len);
INTPTR int Put_some_thing(const char *s1, const char *s2);
}

inline BOOL Echo(){
  return FALSE;
}

INT searchCount = 0;

void Search_hash(INT **hash, INT hash_len, INT goalNum) {
  INT is_find=0,compare_times=1;
  INT key = goalNum;
  INT h = key%11;
  INT t = 1;
  while (hash[h] == NULLPTR || hash[h][0] != key){
    INT d;
    if (t%2==1){ // positive
      d = ((t+1)/2)*((t+1)/2);
    }else {
      d = -(t/2)*(t/2);
    }
    if (t>=hash_len || hash[h] == NULLPTR){
      is_find = -1;
      break;
    }
    h = (key%11+d+hash_len*t)%hash_len;
    t++;
    compare_times++;
  }
//				compare_times = (h%11 - key%11 +m)%m + 1;
  if (is_find == -1){
    printf("%d%s%d\n",is_find+1," ",compare_times);
  }else {
    printf("%d%s%d%s%d\n",is_find+1," ",compare_times," ",(h+1));
  }
}

void Print_hash_table(INT **hash, INT len){
  for (INT i = 0; i < len; i++) {
    if (hash[i] == NULLPTR) {
      printf("NULL");
    } else {
      printf("%d", hash[i][0]);
    }
    if (i < len - 1) {
      printf(" ");
    }
  }
  cout << endl;
}


void test(){
  INT k[] = {0, 1, -1, 4, -4, 9, -9};
//  for(INT i = 0; i < 7; i++){
//    Is_True(v(i) == k[i],
//	    ("v(%d) error now is %d, should be %d \n", i,
//	     v(i), k[i]));
//  }
}

void Insert_hash_num(INT **hash, INT hash_len, INT hash_nums) {
  for (int i = 0; i < hash_nums; i++) {
    int key;
    cin >> key;
    int h = key % 11;
    // create d
    int t = 1; // di = 1,2,3,..,m-1
    while (hash[h] != NULLPTR && hash[h][0] > 0) {
      int d;
      if (t % 2 == 1) { // positive
        d = ((t + 1) / 2) * ((t + 1) / 2);
      } else {
        d = -(t / 2) * (t / 2);
      }
      h = (key % 11 + d + hash_len) %
          hash_len; // Hi = (H(key) + di) MOD m   i=1,2,...,k(k<=m-1)
      t++;
    }
    hash[h] = new INT[1];
    hash[h][0] = key;
  }
}

void one_trial(){
  // what should I do?
  INT  hash_len = 0;
  INT  hash_in = 0;
  INT  temp = 0;
  cin >> hash_len >> hash_in;
  INT **hash = new INT*[hash_len];
  memset(hash, 0, sizeof(INT *) * hash_len);
  Insert_hash_num(hash, hash_len, hash_in);
  Print_hash_table(hash, hash_len);
  INT search_t = 0;
  cin >> search_t;
  for(INT i = 0; i < search_t; i++) {
    cin >> temp;
    Search_hash(hash, hash_len, temp);
  }
}

const int BUCKET_NUM = 10;

int min(int x, int y) {
  return x < y ? x : y;
}


INT main(){
  test();
  INT trials = 0;
  cin >> trials;
  while(trials--) one_trial();
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
