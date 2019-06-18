#include <stdio.h>

#pragma pack(8) 

struct mm{
  int m;
  long double c;
  long long d;
};

int main(){
  printf("%lu\n", sizeof(struct mm));
}
