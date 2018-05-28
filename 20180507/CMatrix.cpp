//
// Created by lugt on 2018/5/28.
//

#include <iostream>
#include <memory.h>
using  namespace std;
class CMatrix{
public:
    CMatrix(int a=0,int b=0){
        int i,j;
        height=a;
        width=b;
        nums=new int *[height];
        for(i=0;i<height;i++)
            nums[i]=new int [width];
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                cin>>nums[i][j];
            }
        }
    }

    CMatrix(CMatrix *from){
        height = from->height;
        width = from->width;
        int i, j;
        nums=new int *[height];
        for(i=0;i<height;i++)
            nums[i]=new int [width];
    }

    void copy(CMatrix * from){
        int i, j;
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                nums[i][j] = from->nums[i][j];
            }
        }
    }

    CMatrix operator+(CMatrix&r){
        CMatrix n(this);
        int i,j;
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                n.nums[i][j]=nums[i][j]+r.nums[i][j];
            }
        }
        return n;
    }

    void show(){
        int i,j;
        for(i=0;i<height;i++){
            for(j=0;j<width;j++){
                if(j!=width-1)
                    cout<<nums[i][j]<<' ';
                else
                    cout<<nums[i][j]<<endl;
            }
        }
    }
private:
    int height,width;
    int **nums;
};
int main(){

    int i,t,m,n;

    cin>>t;

    for(i=0;i<t;i++){
        cin>>m>>n;
        CMatrix x(m,n);
        CMatrix y(m,n);
        x = x+y;
        x.show();
    }
    return 0;
}