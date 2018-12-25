#include<iostream>
#include<algorithm>

using namespace std;

class Date{
public:
  int y,m,d;
  int julianDay;
  bool operator<(const Date&t1) {
    if(y<t1.y) return true;
    else if(y==t1.y&&m<t1.m) return true;
    else if(y==t1.y&&m==t1.m&&d<t1.d) return true;
    else return false;
  }

};

class Point{
public:
  Date time;
  string type;
  int val1,val2;
  Point(){}
};

bool cmp(Point p1,Point p2){
  if(p1.type=="open"&&p2.type=="open"&&p1.time<p2.time){
    return true;
  }else if(p1.type=="close"&&p2.type=="close"&&p1.time<p2.time){
    return true;
  }else if(p1.type=="open"&&p2.type=="close"){
    return true;
  }else return false;
}

int main(){
  int n,m;
  cin>>n>>m;
  Point pp[1000];
  char ch;
  for(int i=0;i<n;i++){
    cin>>pp[i].time.y>>ch>>pp[i].time.m>>ch>>pp[i].time.d>>pp[i].type>>pp[i].val1>>pp[i].val2;
  }
  sort(pp,pp+n,cmp);
  for(int i=m-1;i<n;i++){
    int sum1,sum2,day=0;
    sum1=pp[i].val1,sum2=pp[i].val2;
    for(int t=i-1;t>=0;t--){
      if(pp[i].type==pp[t].type){
        sum1+=pp[t].val1;
        sum2+=pp[t].val2;
        day++;
        if(day==m-1) break;
      }
    }
    if(day==m-1){
      double ave1=sum1/m,ave2=sum2/m;
      cout<<pp[i].time.y<<ch<<pp[i].time.m<<ch<<pp[i].time.d<<' '<<pp[i].type<<' '<<ave1<<' '<<ave2<<endl;
    }
  }
}