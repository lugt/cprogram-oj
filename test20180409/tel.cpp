//
// Created by lugt on 2018/4/9.
//

#include <string>
#include <iostream>

using namespace std;

class CTelNumber{
public:

    const char *cstr;

    CTelNumber(){
        cstr = "";
    };

    CTelNumber(const string & s){
        set(s);
    }

    void set(const string & str){
        string * mtel = new string(str);
        int i = 0;

        if(mtel->size() != 7){
            cstr = "Illegal phone number";
            return ;
        }

        for(i=0;i<mtel->size();i++){
            if(mtel->at(i) > '9' || mtel->at(i) < '0'){
                cstr = "Illegal phone number";
                return ;
            }
        }
        if(!mtel->empty() &&
                (mtel->c_str()[0] == '2'
                 || mtel->c_str()[0] == '3'
                 || mtel->c_str()[0] == '4')){
            mtel = new string( "8" + *mtel);
        }else if(!mtel->empty() &&
                 (mtel->c_str()[0] == '5'
                  || mtel->c_str()[0] == '6'
                  || mtel->c_str()[0] == '7'
                  || mtel->c_str()[0] == '8')){
            mtel = new string( "2" + *mtel);
        }else{
            mtel = new string("Illegal phone number");
        }
        cstr = mtel->c_str();
    };

    ~CTelNumber(){};

};

int main(){
    int t;
    cin >> t;
    string str;
    CTelNumber tel("");
    while(t--) {
        cin >> str;
        tel.set(str);
        cout << tel.cstr << endl;
    }
}