//
// Created by lugt on 2018/5/28.
//

#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

class CJinzhiNum{
private:
    int actual;
    static const int factor = 4;
public:
    int getCharVal(char val){
        if(factor <= 16) {
            if (val >= '0' && val <= '9') {
                return val - '0';
            }else{
                val -= (val >= 'a')?('a' - 'A'):0;
                return val - 'A';
            }
        }else{
            if (val >= '0' && val <= '9') {
                return 52 + val-'0';
            }else if(val >= 'A' && val <= 'Z'){
                return val - 'A';
            }else if(val >= 'a' && val <= 'z'){
                return val - 'a';
            }else if(val == '+'){
                return 62;
            } else if(val == '/'){
                return 63;
            }
            return 0;
        }
    };
    int getTendigit() const {
        return actual;
    }
    string toDecimal(){
        stringstream ss;
        ss << actual;
        return ss.str();
    }

    explicit CJinzhiNum(string str){
        int i,output = 0;
        for(i=0;i<str.size();i++){
            char ch = str[i];
            output *= factor;
            output += getCharVal(ch);
        }
        actual = output;
    }

    CJinzhiNum(){
        actual = 0;
    }

    CJinzhiNum(int t){
        actual = t;
    }
    void operator+=(CJinzhiNum n){
        this->actual += n.actual;
    }
    CJinzhiNum operator+(CJinzhiNum n){
        return CJinzhiNum(n.actual + actual);
    }

    char getDigit(int v) {

        if(v >= 64 || v < 0){
            return '?';
        }

        if(factor <= 16) {
            if (v <= 9) {
                return '0' + v;
            } else if (v <= 16) {
                return 'A' + (v - 10);
            }
        }

        if (factor == 64) {
            if(v <= 25){
                return 'A' + (v);
            } else if (v <= 51) {
                return 'a' + (v - 26);
            } else if (v <= 61) {
                return '0' + (v-52);
            } else if (v == 62) {
                return '+';
            } else{
                return '/';
            }
        }
    }

    void print(){
        int remain = actual;
        std::list<char> lls;
        while(remain > 0){
            lls.push_front(getDigit(remain % factor));
            remain /= factor;
        }
        for(list<char>::iterator it = lls.begin();
            it != lls.end();
            it++){
            cout << *it;
        }
        cout << endl;
    }
};

int main(){
    int t, il = 0;
    CJinzhiNum sum(0);
    cin >> t;

    while(t--){

        cin >> il;
        stringstream ii;
        ii << il;

        if(ii.str().empty()) {
            t++;
        }else{
            CJinzhiNum nn(ii.str());
            sum += nn;
        }
    }
    sum.print();
}