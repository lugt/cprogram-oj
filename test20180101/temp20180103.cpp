#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>

int plater[3] = {0};
void hanoi (int plates, char from[], char medium[], char to[]){

    printf(" \n\n hanoi ( 盘子数量: %d, 从%s 到 %s) \n",plates,from, to);

    if(plates == 1){
        printf("plates = 1, 10 :: %s  -- 把最上面的移动到 -- >  %s\n", from, to);
    }else{
        // 把stick1柱子上的所有块，除了最下方的一块之外都移动到sitck2，
        // 把最大的一块移动到sitck3
        hanoi(plates - 1 , from, to ,medium);
        printf("15 :: %s  -- 把最上面的移动到 -- >  %s\n", from, to);
        hanoi(plates - 1 , medium, from ,to);
    }
    //printf("1: [%d] 2:[%d] 3:[%d] \n", plater[0], plater[1], plater[2]);
}

struct evt{
    void * m;
    void * n;
};

void listIterator(){
    std::list<evt> lst;
    struct evt emm;
    emm.m = reinterpret_cast<void *>(1);
    emm.n = reinterpret_cast<void *>(2);
    lst.push_back(emm);
    lst.push_back(emm);
    lst.push_back(emm);
    lst.push_back(emm);
    lst.push_back(emm);
    for(std::list<evt>::iterator it = lst.begin(); it != lst.end(); it++){
        it->m = it._M_node;
        it->n = it._M_node;
    }
}


int m2ain() {
    listIterator();
    plater[0] = 4;
    hanoi(plater[0],"A","B","C");
}