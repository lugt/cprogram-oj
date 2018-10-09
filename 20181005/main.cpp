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

void Print_Out(UINT a) {

}

void Print_Arr(UINTVEC a) {

}


UINTVEC Integer_to_binary(UINT input){

    UINTVEC res;
    UINT    a   = input;

    Print_Out(a);

    while(a > 0){
        res.push_back(input % 2);
        a /= 2;
    }

    Print_Arr(res);

    return res;
}

void Print_Double(F8 r){
    cout<<fixed<<setprecision(4)<<r<<endl;   //输出小数点后4
}


int main()
{

    F8     data   = 0;
    UINT   counts = 0;
    INT    lhs, rhs;
    cin    >>  counts;

    while(counts --){
        cin >> data << Parse_Integer(data) << "." << Parse_Remain(data) << endl;
        //Print_Double(r);
    }

    return 0;
}

