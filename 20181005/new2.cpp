//
// Created by lugt on 2018/10/5.
//

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
#include<bits/stdc++.h>
using namespace std;
int n,sum,have_find;//sum用于计算输出的个数，用于换行；have_find用于标记走出迷宫
int a[100][100]= {-1};//迷宫数组，用来储存迷宫
int dir[4][2]= {-1,0,0,1,1,0,0,-1};//方向数组，方便记录四个方向
bool is_in_board(int x,int y)//用来判断（x，y）是否在边界里面
{
    if(x>=0&&x<n&&y>=0&&y<n)
        return true;
    return false;
}
bool isValid(int x,int y)//用来判断(x,y)是否可以走
{
    if(is_in_board(x,y)&&a[x][y]==0)
        return true;
    return false;
}
void seekpath(int current_x,int current_y,int current_dir)
{
    int next_x,next_y,t=-1,next_dir;//t==-1表示从左手开始
    for(t=-1;t<=2;t++)
    {
        next_dir=(current_dir+t+4)%4;//加4是为了防止<0的情况，%4是为了防止next_dir>=4的情况
        next_x=current_x+dir[next_dir][0];
        next_y=current_y+dir[next_dir][1];
        if(isValid(next_x,next_y))
        {
            if(next_x==n-1&&next_y==n-1)//如果下一个（x，y）表示走出迷宫，则说明找到出口
            {
                have_find=1;
                cout<<"["<<next_x<<","<<next_y<<"]"<<endl;
                return ;
            }

            cout<<"["<<next_x<<","<<next_y<<"]"<<"--";
            sum++;
            if(sum%5==0)
                cout<<endl;

            seekpath(next_x,next_y,next_dir);

            if(have_find)
                return ;
        }
    }
}

INT main()
{
    INT t;
    cin>>t;
    while(t--)
    {
        have_find=0;
        sum=1;
        cin>>n;//输入迷宫大小
        INT i,j;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                cin>>a[i][j];
        cout<<"[0,0]--";
        seekpath(0,0,2);
    }
    return 0;
}