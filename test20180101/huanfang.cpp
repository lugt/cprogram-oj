#include<stdio.h>
#include <string.h>
#include <stdlib.h>
//
// Created by lugt on 2018/1/1.
//

int last_x = 0, last_y = 0;

int exec_first_loop_for(int m, int n ,int (*a)[100]){

    int i = last_x,j = last_y;
    // K
    // Here
    /*
    if(m > -1 && m  < 35){
        printf("Last turn, m was %d , at i,j = (%d,%d)\n",m+1,i,j);
    }*/

    if(0 == last_x && last_y == n-1){
        m++;
        last_x = 1;
        last_y = n-1;
        a[1][n-1]=m+1;
        return m;
    }


    if(last_x == 0 && last_y != n-1){
        m++;
        a[n-1][j+1]=m+1;
        last_x = n-1;
        last_y = j+1;
        return m;
    }

    if(last_x != 0 && last_y == n-1){
        m++;
        a[i-1][0]=m+1;
        last_x = i-1;
        last_y = 0;
        return m;
    }


    if(last_x != 0 && last_y != n-1){
        m++;
        if(a[i-1][j+1]==0)
        {
            a[i-1][j+1]=m+1;
            last_x = i-1;
            last_y = j+1;
            return m;
        }
        else
        {
            // target_line >= n / target_line -= n
            int target_line = (i+1) % n ;
            a[target_line][j] = m+1;
            last_x = target_line;
            last_y = j;
            return m;
        }
    }else{
        exit(-502);
        return 0;
    }
}

int printCubicBox(int n)
{
    int a[100][100],d,i,j;
    //for(i=0;i<100;i++)for(j=0;j<100;j++) a[i][j] = 0;
    memset(a, 0, 10000 * sizeof(int));
    int len = n * n;
    /*for(t=0;t<n*n;t++)
    {
        printf("%d ",b[t]);
    }
    printf("\n");*/
    int m=0;
    a[0][(n-1)/2]=1;
    last_x = 0;
    last_y = ((n-1)/2);
    for(d = 0; d < len - 1; d++)
    {
        m = exec_first_loop_for(m, n ,a);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
            if(j==n-1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}


