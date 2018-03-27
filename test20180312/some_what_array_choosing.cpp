//
// Created by lugt on 2018/3/19.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>

using std::cin;
using std::cerr;
using std::cout;
using std::string;
using std::endl;

int isNumber(const char* str, size_t len)
{
    size_t pos=0;
    for(pos; pos<len; pos++)
    {
        if(!(str[pos] >= '0' && str[pos] <= '9') && !(pos == 0 && str[pos] == '-'))
            return 0;
    }
    return 1;
}

int main3() {
    int t, mon;
    string str;
    //vector<string> months_names({"","","",""});
    cin >> t;
    while (t--) {
        cin >> str;
        if(isNumber(str.c_str(), str.size())){
            long long thisInt = atol(str.c_str());
            cout << thisInt << endl;
        }else{
            cout << "-1" << endl;
        }
    }

    return 0;
}

