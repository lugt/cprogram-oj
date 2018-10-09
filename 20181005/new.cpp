//
// Created by lugt on 2018/10/5.
//

#include <iostream>
#include <iomanip>

// STL Includings
#include <stack>
#include <vector>

#define Is_Echo(cond,parm) if(cond) printf parm

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::endl;
using std::stack;
using std::vector;

typedef int                    INT;
typedef unsigned int           UINT;
typedef long long int          INT64;
typedef bool                   BOOL;
typedef long long unsigned int UINT64;
typedef vector<INT>            INTVEC;
typedef vector<UINT>           UINTVEC;
typedef vector<UINT64>         UINT64VEC;
typedef vector<double>         F8VEC;
typedef double                 F8;

inline BOOL Echo(){
    return true;
}

#define Max_Value 100

typedef struct Num{
    INT base[Max_Value];
    INT top;
}Num;

void InitNum(Num &S){
    S.top=0;
}

INT Stack_Push(Num &S, INT a){
    if(S.top>=Max_Value)
        return -1;
    S.top++;
    S.base[S.top]=a;
    return 1;
}

INT Stack_Pop(Num &S, INT &a){

    if(S.top<=0)
        return -1;

    a=S.base[S.top];
    S.top--;
    return 1;
}

INT Empty(Num &S){
    if(S.top==0)
        return 1;
    else
        return 0;
}

void Num_1(Num &S,INT a,INT k){
    InitNum(S);
    INT e;
    while(a){
        Stack_Push(S, a % k);
        a=a/k;}
    while(!Empty(S)){
        Stack_Pop(S, e);
        if(e>=10)
            cout<<char(e%10+65);
        else
            cout<<e;}
}

void Num_2(Num &S,double a,INT k){
    InitNum(S);
    INT b,i,e,j=0;
    for(i=0;i<3;i++){
        Stack_Push(S, a * k);
        b=a*k;
        a=a*k-b;
    }
    for(j=1;j<=3;j++){
        if(S.base[j]>=10)
            cout<<char(S.base[j]%10+65);
        else
            cout<<S.base[j];
    }
}
INT main(){
    INT t,k,m;
    double a,n;
    Num S;
    cin>>t;
    while(t--){
        cin>>a>>k;
        m=a;
        n=a-m;
        Num_1(S,m,k);
        cout<<".";
        Num_2(S,n,k);
        cout<<endl;
    }
    return 0;
}
