//
// Created by lugt on 2018/5/28.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class CFourNum{
private:
    int tendigit;
    const int factor = 4;
public:
    int getCharVal(char val){
        if(val >= '0' && val <= '9') {
            return val - '0';
        }else if(val >= 'A' <= 'F' || && factor <= 16){
        }else{
            return 0;
        }
    };
    int getTendigit() const {
        return tendigit;
    }
    string toDecimal(){
        stringstream ss;
        ss << tendigit;
        return ss.str();
    }
    CFourNum(string str){
        int i,output = 0;
        for(i=0;i<str.size();i++){
            char ch = str[i];
            output *= factor;
            output = getCharVal(ch);
        }
    }
};
