#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

#define PI 3.1415926
#define inf 0.001
using namespace std;


class CAccount {
    int bianhao;
    int shouji;
    int dp;
    int yuee;
public:
    void setid(int _id);

    void setcell(int _cell);

    void setdp(int _dp);

    void setbal(int _bal);

    int getid();

    int getcell();

    int getdp();

    int getbal();


};

void result(CAccount *sb, CAccount *apm, int n, int i, int k, int j, int q);

CAccount *chazhao(CAccount *zhanghushuzu, int i, int shoujill);

int CAccount::getid() { return bianhao; }

int CAccount::getcell() { return shouji; }

int CAccount::getdp() { return dp; }

int CAccount::getbal() { return yuee; }

void CAccount::setid(int _id) {
    bianhao = _id;

}

void CAccount::setcell(int _cell) {
    shouji = _cell;

}

void CAccount::setdp(int _dp) {
    dp = _dp;

}

void CAccount::setbal(int _bal) {
    yuee = _bal;

}

int main() {
    CAccount * sb;
    int _id, _cell, _dp, _bal, n, k, i;

    cin >> n;

    sb = new CAccount[n]();
    for (i = 0; i < n; i++) {
        cin >> _id >> _cell >> _dp >> _bal;
        sb[i].setid(_id);
        sb[i].setcell(_cell);
        sb[i].setdp(_dp);
        sb[i].setbal(_bal);
    }


    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> _cell >> _dp >> _bal;
        CAccount *ptr = chazhao(sb, n, _cell);
        if(ptr == NULL){
            cout << "手机号不存在" << endl;
            continue;
        }
        if (ptr->getdp() == _dp) {
            if (ptr->getbal() >= _bal) {
                cout << "卡号" << ptr->getid() << "--余额" << ptr->getbal() - _bal << endl;
            } else {
                cout << "卡号" << ptr->getid() << "--余额不足" << endl;
            }
        } else {
            cout << "密码错误" << endl;
        }
    }
    return 0;
}

CAccount *chazhao(CAccount *account, int total, int cell) {
    for(int i = 0; i < total; i++){
        if(account[i].getcell() == cell){
            return &account[i];
        };
    }
    return NULL;
}
