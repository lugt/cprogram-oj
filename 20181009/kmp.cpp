#include <iostream>
#include <iomanip>

// STL Includings
#include <stack>
#include <vector>
#include <queue>
#include <stdio.h>

#define Is_Echo(parm) if(Echo()) printf parm

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
    return false;
}

using namespace std;

/***
 *
 * Calculate the possible forward movement from failing position
 *
 * */
const INTVEC * KMP_next(string &match_str) {

    INT             temp = 0;
    INTVEC          *next = new INTVEC(match_str.size());
    INT i = 1;
    (*next) [0] = -1;

    while (i < match_str.size() - 1) {
        if (temp == -1 || match_str[i] == match_str[temp]) {
            Is_Echo((" I:%d I+1:%d, Condition:Match, next[%d], plus one, res:%d\n", i, i+1, temp, temp+1));
            (*next)[++i] = ++temp;
        } else {
            Is_Echo((" I:%d I+1:%d, Condition:Not-Match,goto:next[%d] -> (temp <= %d) \n", i, i+1, temp, (*next)[temp]));
            temp = (*next)[temp];
        }
    }
    (*next)[0] = -1;
    return next;
    //abcaacbbcbadabcacbd
}

BOOL KMP_search(string text, string match, INT &pos)
{
    const INTVEC *next = KMP_next(match);
    INT tp = 0;
    INT mp = 0;

    for (tp = 0; tp < next->size(); tp++) {
       // cout << (*next)[tp] << " ";
    }
    //cout << endl;

    for (tp = 0; tp < text.size(); tp++) {
        while (text[tp] != match[mp] && mp) {
            mp = (*next)[mp - 1];
        }
        if (text[tp] == match[mp]) {
            mp++;
        }
        if (mp == match.size()) {
            pos = tp - mp + 1;
            return true;
        }
    }
    if (tp == text.size()) {
        return false;
    }
}

INT main()
{
    INT times;
    INT pos  =  -1;
    string inputstr, matchstr, repl, inputst;

    cin >> times;
    while(times--) {
        cin >> inputstr >> matchstr >> repl;
        inputst = inputstr;
        pos = -1;
        Is_Echo(("Input:%s; Match:%s\n", inputstr.c_str(), matchstr.c_str()));
        KMP_search(inputstr, matchstr, pos);
        if (pos > -1) {
            inputstr = inputst.substr(0, pos) + repl + inputst.substr(pos + matchstr.size());
        }
        Is_Echo(("position = %d \n", pos+1));
        cout << inputst << endl << inputstr << endl;
    }
    return 0;
}

/***

3
qwertyuiop
tyu
aabbccdd
ccc
aaaabababac
abac
样例输出
-1 0 0
5
-1 0 1
0
-1 0 0 1
8

 */