#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define         OK                    0
#define         FAIL                  1
#define         MAX_SIZE              100
#define         NULLPTR               NULL

#define  Is_Print(cond, parm)  if(cond) printf parm


#define  Df_do_seq(a, b, c)              \
    std::cin        >> b;                \
    if(a.c(b - 1) >= 0){              \
        a.print();                       \
    }

#define  Df_do_dseq(a, b1, b2, c)        \
    std::cin        >> b1 >> b2;         \
    if(a.c(b1 - 1, b2) >= 0){             \
        a.print();                       \
    }

typedef         int           INT;
typedef         long          INT64;
typedef         unsigned int  UINT;
typedef         unsigned long UINT64;
typedef         char**        CHPPTR;
typedef         char*         CHPTR;
typedef         const char*   CCHPTR;
typedef         bool          BOOL;


INT compare_int(const void* lhs, const void *rhs);

inline BOOL Printing(){
    return false;
}


// ============================================================================ 
//  SeqList (ArrayList) 
// ============================================================================ 
template<typename T>
class SeqList{
private:
    INT      size;
    INT      max_size;
    T*       list;

public:
    SeqList(){
        size                =   0;
        max_size            =   0;
        list                =   NULLPTR;
    }

    void enlarge() {
        if(!list){
            INT      oldsz  =  max_size;
            max_size       +=  MAX_SIZE;
            INT     *nlist  =  new T[max_size];
            memcpy(nlist, list, sizeof(T) * oldsz);
            list            =  nlist;
        }else{
            max_size        =  MAX_SIZE;
            list            =  new T[max_size];
        }
    }

    INT insert(INT position, T data){

        Is_Print(Printing(), ("[SeqList::insert] position : %d, before.size: %d, data: %d \n", position, size, data));

        if(position < 0)   {
            std::cout      << "error\n";
            return -1;
        }
        if(position >= size + 1){
            std::cout      << "error\n";
            return -1;
        };

        while(max_size - 1 <= position){
            enlarge();
        }

        if(position <= size - 1){
            // move all data forward 
            INT      tpos  =  size - 1;
            while(tpos >= position){
                list[tpos + 1] = list[tpos];
                tpos --;
            }
        }

        list[position]     =  data;

        if(position + 1 > size){
            size = position + 1;
        }else{
            size ++;
        }

        return size;
    }

    INT remove(INT position){

        Is_Print(Printing(), ("[SeqList::remove] position : %d, before.size: %d", position, size));

        if(size <= position || position < 0){
            std::cout      << "error\n";
            return -1;
        }

        Is_Print(Printing(), (", data: %d\n", list[position]));

        INT      tpos  =  position;
        while(tpos < size - 1){
            list[tpos] = list[tpos + 1];
            tpos ++;
        }

        size--;
        return size;
    }

    INT *at(INT position){
        if(size <= position || position < 0){
            return NULLPTR;
        }else{
            return &list[position];
        }
    }

    INT find(T target){
        return -1;
    }

    INT sort(){
        Is_Print(Printing(), ("[Seq::sort] size : %d, elet_size: %d \n", size, sizeof(T)));
        qsort(list, size, sizeof(T), compare_int);
    }

    INT reduce(){
        INT       i        = 0;
        for(i = 1; i < size; i++){

            Is_Print(Printing(), ("[Seq::reduce] i:%d \n", i));

            if(i > 0 && list[i] == list[i-1]){

                Is_Print(Printing(),
                         ("[Seq::reduce] merging %d and %d, data: %d \n",
                                 i, i-1, list[i]));
                remove(i);

                if(i < size - 1){
                    Is_Print(Printing(),
                             ("[Seq::reduce] repointing to %d, data:%d \n",
                                     i, list[i]));
                }else{
                    Is_Print(Printing(),
                             ("[Seq::reduce] fast-finish \n"));
                    return  0;
                }
            }
        }
    }

    INT  get_size(){
        return size;
    }

    INT  get_max_size(){
        return max_size;
    }

    void print(){
        INT  p             = 0;
        if(Printing()) {
            std::cout      <<  size   << " ";
        }

        for( ; p < size; p++){
            std::cout      << list[p];
            //if(p != size - 1)  
            std::cout      << " ";
        }
        std::cout          <<  "\n";
    }


    INT multi_insert(INT position, INT num, T* data){
        if(position < 0 || position > size){
            std::cout      <<    "error\n";
            return -1;
        }
        INT           i    =     0;
        for(i = 0; i < num ; i++){
            insert(position + i, data[i]);
        }
        return  0;
    }

    INT multi_del(INT position, INT num){
        if(position < 0 || position > size){
            std::cout << "error\n";
            return -1;
        }
        if(size - position + 1 < num){
            std::cout << "error\n";
            return -1;
        }
        INT           i    =     0;
        for(i = 0; i < num ; i++){
            remove(position);
        }
        return  0;
    }

    INT rotate(INT direction, INT length){

        if(direction == 0 ){
            direction = -1;
        }else if(direction == 1){
            direction = 1;
        }else{
            return -1;
        }

        INT       *nlist   =   new T[max_size];
        INT        i       =   0;
        INT        new_pos =   0;
        memcpy(nlist, list, sizeof(T) * size);
        for(i = 0; i < get_size(); i++){
            new_pos        = calc_new_pos(i, length, direction);
            nlist[new_pos] = list[i];
        }
        //delete     list; 
        list       =   nlist;
        return     0;
    }

    INT calc_new_pos(INT orig, INT length, INT direction){

        INT new_pos = orig;
        INT len     = direction * length;

        new_pos     = (orig + len);
        while(new_pos < 0){
            new_pos += size;
        }
        new_pos = new_pos % size;

        Is_Print(Printing(), ("[calc_new_pos] (size:%d) orig:%d,  length:%d,  direction:%d, output: %d\n",
                size, orig, length, direction, new_pos));
        return new_pos;
    }

};

INT compare_int(const void* lhs, const void *rhs){
    return *((INT *)lhs) - *((INT *)rhs);
}

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


typedef         ListNode<INT> LNODE;

template<typename T>
class LinkList{

private:
    INT      size;
    INT      max_size;
    T*       head;
    T*       tail;
    T*       last;

public:
    LinkList(){
        size                =   0;
        max_size            =   0;
        head                =   NULLPTR;
        tail                =   NULLPTR;
        last                =   NULLPTR;
    }


    void printInternal(){
        INT  p             = 0;
        if(Printing()) {
            std::cout      << "Internal Print :  [" << size   << "] \n";
            for( ; p < size; p++){
                std::cout      << "{ #" << (UINT64) locate(p) << "# , next:" << (UINT64) locate(p)->next <<", data: " << (UINT) locate(p)->kid.uintData;
                //if(p != size - 1)  
                std::cout      << "} ";
                std::cout          <<  "\n";
            }
            std::cout          <<  "\n";
        }

    }

    //=========================================================================
    // enlarge
    //=========================================================================    
    void enlarge() {
        if(head){
            INT      oldsz  =  max_size;

            if(!tail || tail <= head) {
                tail        =  head;
            }

            if(!last || last <= head) {
                last        =  head;
            }

            UINT     ofst   =  tail - head;
            UINT     ofstl  =  last - head;
            max_size       +=  MAX_SIZE;
            T       *nlist  =  new T[max_size];
            memcpy(nlist, head, sizeof(T) * oldsz);
            head            =  nlist;
            tail            =  head + ofst;
            last            =  head + ofstl;
        }else{
            max_size        =  MAX_SIZE;
            head            =  new T[max_size];
            tail            =  head;
            last            =  head;
            Is_Print(Printing(), ("[LinkList::enlarge] sizeof(void *) = %d, first-time, "
                                  "head %u , tail %u, last:%u \n", sizeof(void *), (UINT64) head, (UINT64) tail, (UINT64) last));
        }
    }

    //========================================================================
    // locate
    //========================================================================
    T  *locate(UINT pos){

        INT  i             =  0;
        T   *target        =  head;

        if(pos < 0 || pos >= size){
            return   NULLPTR;
        }

        for(i = 0 ; i < pos; i++){
            if(target != NULLPTR)       target   =  target->next;
            else{
                Is_Print(Printing(), ("[locate] error : target->next is going "
                                      " to be NPD, pos: %d, i: %d", pos, i));
                exit(-1);
            }
        }

        return target;
    }

    T   *operator[] (UINT pos){
        return locate(pos);
    }

    //=========================================================================
    // insert
    //=========================================================================    
    INT insert(INT position, UINT data){

        Is_Print(Printing(), ("[LinkList::insert] position : %d, before.size: %d,"
                              "data: %u \n", position, size, (UINT) data));

        if(position < 0)   {
            std::cout      << "error\n";
            return -1;
        }

        if(position >= size + 1){
            std::cout      << "error\n";
            return -1;
        };

        while(max_size - 1 <= position){
            enlarge();
        }

        T      *orig         =  NULLPTR;
        T      *orig_b4      =  NULLPTR;
        T      *now          =  last + 1;

        last ++;

        now->kid.uintData = data;
        now->next         = NULLPTR;

        if(position <= size - 1){
            // move all data forward 
            if(position > 0){
                orig_b4       = locate(position - 1);
                if(!orig_b4){
                    Is_Print(Printing(), ("[LinkList::insert] error! locate(%d) failed! \n", position));
                    return -1;
                }
                orig          = orig_b4->next;
                if(!orig){
                    Is_Print(Printing(), ("[LinkList::insert] error! locate(%d) failed! \n", position));
                    return -1;
                }
                orig_b4->next = now;
                now->next      = orig;
                Is_Print(Printing(), ("[LinkList::insert] size = 0, adding as middle (not empty) "
                                      "pos: %d, now[pos]:%llu,  orig[pos]: %llu , data: %u \n", position, (UINT64) now, (UINT64) now->next, (UINT) data));
            }else{
                now->next     =  head;
                head          =  now;
                Is_Print(Printing(), ("[LinkList::insert] size = 0, adding as first (not empty) "
                                      "pos: %d, new_head:%llu,  orig_head: %u , data: %llu \n", position, (UINT64) now, (UINT64) now->next, (UINT) data));
            }
        }else if(size > 0){
            // Adding to the last
            tail->next        =  now;
            tail              =  tail->next;
            Is_Print(Printing(), ("[LinkList::insert] size = 0, adding as tail (not empty) "
                                  "pos: %d, data: %u \n", position, (UINT) data));
        }else{  /** size == 0*/
            head             = now;
            tail             = now;
            Is_Print(Printing(), ("[LinkList::insert] size = 0, adding as first (from empty) "
                                  "position: %d, data: %u \n", position, (UINT)  data));

        }

        if(position + 1 > size){
            size = position + 1;
        }else{
            size ++;
        }

        return size;
    }

    //=========================================================================
    // remove
    //=========================================================================    
    INT remove(INT position){


        Is_Print(Printing(), ("[LinkList::remove] position : %d, before.size: %d", position, size));
        printInternal();

        if(size <= position || position < 0){
            std::cout      << "error\n";
            return -1;
        }

        Is_Print(Printing(), (", head: %llu\n", (UINT64) head));

        T       *lhs   =  NULLPTR;
        T       *rhs   =  NULLPTR;
        INT      tpos  =  position;

        if(tpos < size - 1){
            rhs = locate(tpos + 1);
        }

        if(tpos > 0){
            T * lhs    =  locate(tpos - 1);
            if(!lhs){
                Is_Print(Printing(), ("[LinkList::remove] position : %d, error going to pos: %d \n", position, tpos));
                exit(-1);
            }else{
                lhs->next = rhs;
                if(rhs == NULLPTR)
                    tail =  lhs;
            }
        }else{
            head       =  rhs;
        }

        size--;

        Is_Print(Printing(), ("[LinkList::remove] position : %d, after.size: %d", position, size));
        printInternal();
        return size;
    }

    //=========================================================================
    // at
    //=========================================================================  
    INT  at(INT position){
        if(size <= position || position < 0){
            std::cout << "error\n" ;
            return -1;
        }else{
            T     *now   =   locate(position);
            if(!now){
                Is_Print(Printing(), ("cannot goto pos [%d], locating returned NULLPTR \n", position));
                return  -1;
            }
            return now->kid.uintData;
        }
    }

    //=========================================================================
    // sort
    //=========================================================================  
    INT sort(){
        Is_Print(Printing(), ("[LinkList::sort] size : %d, elet_size: %d \n", size, sizeof(T)));
        //qsort(head, size, sizeof(T), compare_t); 
    }

    //=========================================================================
    // reduce
    //=========================================================================  
    INT reduce(){
        INT       i        = 0;
        for(i = 1; i < size; i++){

            Is_Print(Printing(), ("[LinkList::reduce] i:%d \n", i));

            if(i > 0 && locate(i).uintData == locate(i-1)->kid.uintData){

                Is_Print(Printing(),
                         ("[LinkList::reduce] merging %d and %d, data: %u \n",
                                 i, i-1, locate(i).uintData));
                remove(i);

                if(i < size - 1){
                    Is_Print(Printing(),
                             ("[LinkList::reduce] repointing to %d, data:%u \n",
                                     i, locate(i).uintData));
                }else{
                    Is_Print(Printing(),
                             ("[LinkList::reduce] fast-finish \n"));
                    return  0;
                }
            }
        }
    }

    //=========================================================================
    // get_size
    //=========================================================================  
    INT  get_size(){
        return size;
    }

    //=========================================================================
    // get_max_size
    //=========================================================================    
    INT  get_max_size(){
        return max_size;
    }

    //=========================================================================
    // print
    //=========================================================================    
    void print(){
        INT  p             = 0;
        if(Printing()) {
            std::cout      <<  size   << " ";
        }

        for( ; p < size; p++){
            std::cout      << (UINT64) (locate(p)->kid.voidData);
            //if(p != size - 1)  
            std::cout      << " ";
        }
        std::cout          <<  "\n";
    }

    //=========================================================================
    // multi_insert
    //=========================================================================    
    INT multi_insert(INT position, INT num, T* data){
        if(position < 0 || position > size){
            std::cout      <<    "error\n";
            return -1;
        }
        INT           i    =     0;
        for(i = 0; i < num ; i++){
            insert(position + i, data[i]);
        }
        return  0;
    }

    INT multi_del(INT position, INT num){
        if(position < 0 || position > size){
            std::cout << "error\n";
            return -1;
        }
        if(size - position + 1 < num){
            std::cout << "error\n";
            return -1;
        }
        INT           i    =     0;
        for(i = 0; i < num ; i++){
            remove(position);
        }
        return  0;
    }

    INT rotate(INT direction, INT length){

#if 0
        if(direction == 0 ){ 
            direction = -1; 
        }else if(direction == 1){ 
            direction = 1; 
        }else{ 
            return -1; 
        } 
           
        INT       *nlist   =   new T[max_size]; 
        INT        i       =   0; 
        INT        new_pos =   0; 
        memcpy(nlist, list, sizeof(T) * size); 
        for(i = 0; i < get_size(); i++){ 
            new_pos        = calc_new_pos(i, length, direction); 
            nlist[new_pos] = list[i];    
        }        
        //delete     list; 
        list       =   nlist;
#endif
        return     0;
    }

    INT calc_new_pos(INT orig, INT length, INT direction){

        INT new_pos = orig;
        INT len     = direction * length;

        new_pos     = (orig + len);
        while(new_pos < 0){
            new_pos += size;
        }
        new_pos = new_pos % size;

        Is_Print(Printing(), ("[calc_new_pos] (size:%d) orig:%d,  length:%d,  direction:%d, output: %d\n",
                size, orig, length, direction, new_pos));
        return new_pos;
    }
};

//============================================================================= 
// Main Entry 
// @param INT argc 
//============================================================================= 
int main(INT argc, CHPPTR argv) {

    INT             n        = 0;
    INT             p        = 0;
    INT             num      = 0;
    LinkList<LNODE> myseq;
    INT             direct   = 0;
    INT             length   = 0;


    Is_Print(Printing(), ("sizeof(LNODE)  == %d \n", sizeof(LNODE)));

#if 0
    myseq.insert(0, 111); 
    myseq.insert(1, 222);
    myseq.insert(2, 333);
    myseq.insert(3, 444);
    myseq.printInternal();
    Is_Print(Printing(), ("list:%lx, [0]:%u, max_size:%d\n",  
                           myseq.locate(0), myseq.at(0), myseq.get_max_size()));
#endif

    std::cin        >>       n ;
    p               =        n ;

    while( p-- ){
        Is_Print(Printing(),
                 ("[main] while again, p:%d\n", p));
        std::cin    >> num;
        myseq.insert(myseq.get_size(), num);
    }
    myseq.print();

    Is_Print(Printing(),
             ("[main] inserting \n"));

    Df_do_dseq(myseq, n, num, insert);
    Df_do_dseq(myseq, n, num, insert);

    Is_Print(Printing(),
             ("[main] removing \n"));

    Df_do_seq(myseq, n, remove);
    Df_do_seq(myseq, n, remove);


    Is_Print(Printing(),
             ("[main] at \n"));

    std::cin    >> num;
    if(myseq.locate(num - 1) != NULLPTR){
        std::cout   <<  myseq.locate(num - 1)->kid.uintData << "\n";
    }else{
        std::cout  << "error\n";
    }

    std::cin    >> num;
    if(myseq.locate(num - 1) != NULLPTR){
        std::cout   <<  myseq.locate(num - 1)->kid.uintData << "\n";
    }else{
        std::cout  << "error\n";
    }


    Is_Print(Printing(),
             ("[main] rotating \n"));

    //Df_do_fseq(myseq, direct, length, rotate); 
    //Df_do_fseq(myseq, direct, length, rotate); 

    getchar();
    getchar();
    return 0;
}


/**
 
6 11 22 33 44 55 66
3 777
1 888
1
11
0
5
 
样例输出
11 22 33 44 55 66 
11 22 777 33 44 55 66 
888 11 22 777 33 44 55 66 
11 22 777 33 44 55 66 
error
error
44
 
 
*/