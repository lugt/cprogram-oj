#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define         OK                    0
#define         FAIL                  1
#define         MAX_SIZE              1000000
#define         NULLPTR               NULL
#define         TRUE                  true
#define         FALSE                 false
typedef         char          CHAR;
typedef         int           INT;
typedef         long          INT64;
typedef         unsigned int  UINT;
typedef         unsigned long UINT64;
typedef         char**        CHPPTR;
typedef         char*         CHPTR;
typedef         const char*   CCHPTR;
typedef         bool          BOOL;
typedef         std::string   STRING;
inline BOOL Printing(){
    return FALSE;
}








template<typename T>
class Stacks{
    std::stack<T> stlist;
};

template<typename T2>
struct ListNode{
    int        pos;
    ListNode  *head;
    ListNode  *next;
    union {
        INT   *intData;
        void  *voidData;
        CHPTR  charData;
        T2    *tData;
        UINT uintData;
    } kid;
};

//typedef         ListNode<INT>       LNODE;
typedef         CHAR                LNODE;
typedef         std::stack<LNODE>   STLSTK;

UINT64 Str_Push(STLSTK *list, CCHPTR str){
    UINT64          i       = 0;
    UINT64          len     = strlen(str);
    for(i = 0; i < len; i++){
        list->push(str[i]);
    }
    return len;
}

STRING outstr = "";

INT Str_Sequence_Check (STLSTK * orig, CCHPTR in,  UINT64 len, CCHPTR out){
    std::stringstream sstr;
    UINT64          i        = 0;
    UINT64          cur_in   = 0;
    UINT64          cur_out  = 0;
    while (len > 0 && cur_in != len){
        orig->push(in[cur_in++]);
        sstr << "in\n" ;
        CHAR    st   = orig->top();
        while(out[cur_out] == st){
            orig->pop();
            if(!orig->empty()) {
                st = orig->top();
            }else{
                st = '$';
            }
            cur_out++;
            sstr << "out\n" ;
            if(cur_out >= len){
                break;
            }
        }
    }

    outstr = sstr.str();
    if(cur_out < len) return -1;
    return 0;

}

//=============================================================================
// Main Entry
// @param INT argc
//=============================================================================
int main(INT argc, CHPPTR argv) {

    INT             n        = 0;
    INT             p        = 0;
    INT             num      = 0;
    INT             direct   = 0;
    INT             length   = 0;
    STRING          input_str;
    STRING          outbnd_str;
    STLSTK          my, out;
    while(std::cin  >>  n) {
        std::cin      >>       input_str;
        std::cin      >>     outbnd_str;
        UINT64        len      = input_str.size();
        if(Str_Sequence_Check (&my, input_str.c_str(), len, outbnd_str.c_str()) >= 0){
            std::cout    << "Yes." << "\n";
            std::cout    << outstr;
            std::cout    << "FINISH" << "\n";
        }else{
            std::cout    << "No.\nFINISH\n";
        }
        input_str      =  "";
    }
    return 0;
}
