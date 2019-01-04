//
// Created by lugt on 2018/3/26.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>
#include <ctime>
//#include "list.h"

using std::cin;
using std::cerr;
using std::cout;
using std::string;
using std::endl;

struct userNode
{
    struct tm birth;
    userNode * next;
    userNode(int y,int m, int d){
        birth.tm_year = y - 1900;
        birth.tm_mon = m - 1;
        birth.tm_mday = d;
        next = NULL;
    };

    // one is greater == 1, one is smaller == -1
    int compare(userNode * one){
        if(one->birth.tm_year > birth.tm_year){
            return 1;
        }else if(one->birth.tm_year == birth.tm_year){
            if(one->birth.tm_mon > birth.tm_mon){
                return 1;
            }else if(one->birth.tm_mon == birth.tm_mon){
                if(one->birth.tm_mday > birth.tm_mday){
                    return 1;
                }else if(one->birth.tm_mday == birth.tm_mday){
                    return 0;
                }else {
                    return -1;
                }
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }

};

int add_in_order(userNode ** list_, userNode * newOne){
    int position = 0;
    userNode * prev;
    if(newOne == NULL) return -1;

    if(*list_ == NULL){
        *list_ = newOne;
        return 0;
    }

    userNode * list = *list_;
    prev = list;

    while(list != NULL){
        if(list->compare(newOne) >= 0){
            if(list->next != NULL){
                prev = list;
                list = list->next;
                position ++;
            }else{
                list->next = newOne;
                position ++;
                break;
            }
        }else{
            if(prev != list){
                newOne->next = list;
                prev->next = newOne;
                break;
            }else{
                // add to be the first;
                newOne->next = list;
                *list_ = newOne;
                break;
            }
        }
    }
    return position;
}

int list_size(userNode * now){
    int a = 0;
    while(now != NULL){
        a ++;
        now = now->next;
    }

    return a;
}

userNode * get_n_of_list(userNode * list, int n){

    if(list == NULL) return NULL;

    while(n > 0 && list != NULL){
        list = list->next;
        n--;
    }

    return list;
}


int delete_one(userNode * list, userNode * one){
    int a;
    for(a = 0 ; a < list_size(list) ; a++){
        if(get_n_of_list(list, a) == one){
            if(one->next != NULL && a != 0){
                get_n_of_list(list, a - 1)->next = one->next;
                delete one;
                return 1;
            }else if(one->next == NULL){

            }
        }

    }
    return 0;
}

userNode * create(int n)
{
    int i,y,m,d;
    userNode * pFirst = NULL, * now = NULL, * next = NULL;
    for(i=0;i<n;i++)
    {
        srand(static_cast<unsigned int>(time(NULL)));
        y = static_cast<int>(random() % 10 + 2000);
        m = static_cast<int>(random() % 12);
        d = static_cast<int>(random() % 25);
        //cin >> y >> m >> d;
        add_in_order(&pFirst,new userNode(y,m,d));
    }
    return pFirst;
}

string show_single(userNode * now){
    char str[1000] = {};
    strftime(str, 100, "%Y-%m-%d", & now->birth);
    return std::string(str);
}

/// Display a list
/// \param list
void show(userNode * list)
{
    int a, total = list_size(list);
    for(a = 0; a < total ; a++)
    {
        cout << show_single(get_n_of_list(list,a)) << endl;
    }
}

int main()
{
    int n = 10;
    userNode * list_1 = create(n);
    show(list_1);
    //cout << show_single(get_n_of_list(list_1, 1));
    return 0;
}
