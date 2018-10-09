//
// Created by lugt on 2018/10/9.
//

#include <iostream>
#include <intrin.h>
#include <time.h>

#define dataLen  1000000000

void testfun()
{
    float *buf1 = new float[dataLen];
    float *buf2 = new float[dataLen];
    float *buf3 = new float[dataLen];

    for(int i=0; i<dataLen; i++)
    {
        buf1[i] = i;
        buf2[i] = 1;
        buf3[i] = 0;
    }

    //==================SIMD代码==================================


    int t = clock();
    __m128 data1,data2,data3=_mm_setzero_ps();

    float *p1= buf1;
    float *p2= buf2;
    float *p3= buf3;


    for(int theta=0; theta<dataLen/4; theta++)
    {
        data1 = _mm_load_ps(p1);
        data2 = _mm_load_ps(p2);
        data3 = _mm_mul_ps(data1, data2);

        _mm_store_ps(p3, data3);

        p1 = p1+4;
        p2 = p2+4;
        p3 = p3+4;

    }

    int timePassed = clock() - t;
    std::cout<<"total time used: "<<timePassed<<"ms"<<std::endl;

    //==================普通代码=============================================

    for(int i=0; i<dataLen; i++)
    {
        buf1[i] = i;
        buf2[i] = 1;
        buf3[i] = 0;
    }

    t = clock();
    float *pp1 = buf1;
    float *pp2 = buf2;
    float *pp3 = buf3;


    for(int i=0; i<dataLen; i++)
    {
        *pp3 =  (*pp1) * (*pp2);
        pp1++;
        pp2++;
        pp3++;
    }
    timePassed = clock() - t;
    std::cout<<"total time used: "<<timePassed<<"ms"<<std::endl;

}

int main(int, char**){
    testfun();
}