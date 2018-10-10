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
    return true;
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

BOOL KMP_search(string text, CCHPTR match, UINT match_len, INT &pos)
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
    string inputstr;

    cin >> times;
    while(times--) {
        cin >> inputstr;

        if(inputstr.empty()) continue;

        inputstr += "$";

        Is_Echo(("Input:%s\n", inputstr.c_str()));

        INT      lastoccur = -1;
        UINT     len       = 0;
        INT      max = 0;
        UINT     max_pos = 0;
        string   max_str;
        UINT     suflen    = inputstr.size();
        CCHPTR   suffix    = inputstr.c_str();
        CCHPTR   cursor;


        for(INT i = 0; i < suflen ; i++){
            cursor = i + suffix;
            len = suflen - i;
            const INTVEC *next_arr = KMP_next(cursor, len);
            Is_Echo(("%s,","next-arr:"));
            for(UINT j = 0; j < len; j++){
                Is_Echo(("%d,", next_arr->at(j)));
            }
            Is_Echo(("%s,","\n"));
            for(UINT j = 0; j < len; j++){
                if(next_arr->at(j) >= max && next_arr->at(j) <= (len-1) / 2){
                    max_pos = i + j;
                    max = next_arr->at(j);
                    if(max != 0) max_str = inputstr.substr(i, max);
                }
            }
            Is_Echo(("str:%s, max: %d, max_pos(fixed):%d \n", cursor, max, max_pos));
        }

        if(max == 0){
            cout << "-1" << endl;
        }else {
            Is_Echo(("max_str:%s, inputstr:%s, len: %d, max_pos:%d, start_pos = %d\n",max_str.c_str(), inputstr.c_str(), max, max_pos, max_pos - max));
            string out = inputstr.substr(max_pos - max, max);
            Is_Echo(("out_str:%s,",out.c_str()));
            cout << max << endl;
        }
    }
    return 0;
}