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


class sysAccount {
    int id;
    int cell;
    int dp;
    int bal;
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

void result(sysAccount *sb, sysAccount *ass, int n, int i, int k, int j, int flag);

sysAccount *find_account_by_cell(sysAccount *account, int i, int i1);

int sysAccount::getid() { return id; }

int sysAccount::getcell() { return cell; }

int sysAccount::getdp() { return dp; }

int sysAccount::getbal() { return bal; }

void sysAccount::setid(int _id) {
    id = _id;

}

void sysAccount::setcell(int _cell) {
    cell = _cell;

}

void sysAccount::setdp(int _dp) {
    dp = _dp;

}

void sysAccount::setbal(int _bal) {
    bal = _bal;

}

int main() {
    sysAccount * sb;
    int _id, _cell, _dp, _bal, n, k, i;

    cin >> n;

    sb = new sysAccount[n]();
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
        sysAccount *ptr = find_account_by_cell(sb, n, _cell);
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

sysAccount *find_account_by_cell(sysAccount *account, int total, int cell) {
    for(int i = 0; i < total; i++){
        if(account[i].getcell() == cell){
            return &account[i];
        };
    }
    return NULL;
}
