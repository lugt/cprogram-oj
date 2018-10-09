#include <iostream>
#include <iomanip>

// STL Includings
#include <stack>
#include <vector>
#include <queue>

#define Is_Echo(cond,parm) if(cond) printf parm

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;
using std::endl;
using std::stack;
using std::vector;
using std::string;
using std::queue;

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

using namespace std;
const vector<int> * kmp_next(string &m)
{
    static vector<int> next(m.size());
    next[0]=0;
    int temp;
    for(int i=1; i<next.size(); i++)
    {
        temp=next[i-1];
        while(m[i]!=m[temp]&&temp>0)
        {
            temp=next[temp-1];
        }
        if(m[i]==m[temp])
            next[i]=temp+1;
        else next[i]=0;
    }
    return &next;
}

bool Kmp_search(string text, string m, int &pos)
{
    const vector<int> * next=kmp_next(m);
    int tp=0;
    int mp=0;
    for(tp=0; tp<text.size(); tp++)
    {
        while(text[tp]!=m[mp]&&mp)
            mp=(*next)[mp-1];
        if(text[tp]==m[mp])
            mp++;
        if(mp==m.size())
        {
            pos=tp-mp+1;
            return true;
        }
    }
    if(tp==text.size())
        return false;
}

int main()
{
    int pos=0;
    Kmp_search("abcacbc", "ca", pos);
    cout<<"position = "<<pos+1<<endl;
    return 0;
}
