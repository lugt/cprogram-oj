#include <iostream>
#include <iomanip>
#include <stdio.h>

// STL Includings
#include <stack>
#include <vector>
#include <queue>
#include <cstring>

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
typedef char                   CHAR;
typedef char*                  CHPTR;
typedef char**                 CHPPTR;
typedef const char*            CCHPTR;
typedef const char**           CCHPPTR;

inline BOOL Echo(){
    return false;
}

/***
 *
 * Calculate the possible forward movement from failing position
 *
 * */
const INTVEC * KMP_next(CCHPTR match_str, UINT64 length) {

    INT             temp = 0;
    INTVEC          *next = new INTVEC(length);
    INT i = 1;
    (*next) [0] = -1;

    while (i < length - 1) {
        if (temp == -1 || match_str[i] == match_str[temp]) {
            //Is_Echo((" I:%d I+1:%d, Condition:Match, next[%d], plus one, res:%d\n", i, i+1, temp, temp+1));
            (*next)[++i] = ++temp;
        } else {
            //Is_Echo((" I:%d I+1:%d, Condition:Not-Match,goto:next[%d] -> (temp <= %d) \n", i, i+1, temp, (*next)[temp]));
            temp = (*next)[temp];
        }
    }
    (*next)[0] = -1;
    return next;
    //abcaacbbcbadabcacbd
}

BOOL KMP_search(string text, CCHPTR match, UINT64 match_len, INT &pos)
{
    const INTVEC *next = KMP_next(match, match_len);
    INT tp = 0;
    INT mp = 0;

    for (tp = 0; tp < text.size(); tp++) {
        while (text[tp] != match[mp] && mp) {
            mp = (*next)[mp - 1];
        }
        if (text[tp] == match[mp]) {
            mp++;
        }
        if (mp == match_len) {
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
    INT pos;
    string inputstr;

    cin >> times;
    while(times--) {
        cin >> inputstr;

        if(inputstr.empty()) continue;

        Is_Echo(("Input:%s\n", inputstr.c_str()));

        INT      lastoccur = -1;
        UINT     suflen    = inputstr.size();
        CCHPTR   suffix    = inputstr.c_str();
        CCHPTR   cursor;


        for(INT i = suflen - 1; i >= 1 ; i--){
            cursor = suffix + i;
            pos = -1;
            if(suflen - i > 0
            && cursor + suflen - i - 1 <= suffix + suflen
            && cursor                  <  suffix + suflen
            && cursor                  >= suffix) {
                //CCHPTR once = KMP_search(inputstr, cursor, suflen - i, pos);
                CCHPTR once = strstr(suffix, cursor); // glibc is faster
                if(once != NULL){
                    lastoccur = i;
                }
            }
        }

        if(lastoccur == -1){
            cout << "empty" << endl;
        }else {
            cout << inputstr.substr(static_cast<unsigned long>(lastoccur)) << endl;
        }
    }
    return 0;
}