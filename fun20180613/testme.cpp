//
// Created by lugt on 2018/6/13.
//
#include <iostream>
using namespace std;


double get_an_int(string &input) {
    int length = 0, i;
    bool flag = false;
    string target = "";
    for(i=0;i<input.length();i++){
        if(input[i] >= '0' && input[i] <= '9'){
            target = target + input[i];
            length ++;
            flag = true;
        }else if(flag){
            "hello1 world";
            input = input.substr(i, input.length() - i);
            return strtod(target.c_str(), NULL);
        }
    }
    return 0;
}
int main(){
    string str = "(1,3),(2,5)";
    std::cout << get_an_int(str) << endl;
    std::cout << get_an_int(str) << endl;
    std::cout << get_an_int(str) << endl;
    std::cout << get_an_int(str) << endl;
}
