#include <iostream>
#include <math.h>

using namespace std;

class RMB{

private:
    int mY;
    int mJ;
    int mF;

public:

    RMB(double amount){
        mY = (int)(amount);
        mJ = (amount-mY)*10;
        mF =amount*100 - mY*100 - mJ*10+0.05;
    }

    void show(){
        cout<<"yuan="<<mY<<" jiao="<<mJ<<" fen="<<mF<<endl;
    }
};



int main(){
    int i,j,t;
    cin>>t;
    double a;
    for(i=0;i<t;i++){
        cin>>a;
        RMB X(a);
        X.show();
    }
    return 0;
}