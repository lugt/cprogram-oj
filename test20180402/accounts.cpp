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

private:
    int id, cell, dp, bal;

public:
    int getId() const;

    void setId(int id);

    int getCell() const;

    void setCell(int cell);

    int getDp() const;

    void setDp(int dp);

    int getBal() const;

    void setBal(int bal);

};

int sysAccount::getId() const {
    return id;
}

void sysAccount::setId(int id) {
    sysAccount::id = id;
}

int sysAccount::getCell() const {
    return cell;
}

void sysAccount::setCell(int cell) {
    sysAccount::cell = cell;
}

int sysAccount::getDp() const {
    return dp;
}

void sysAccount::setDp(int dp) {
    sysAccount::dp = dp;
}

int sysAccount::getBal() const {
    return bal;
}

void sysAccount::setBal(int bal) {
    sysAccount::bal = bal;
}

void result(sysAccount *sb, sysAccount *ass, int n, int i, int k, int j, int flag);

sysAccount *find_account_by_cell(sysAccount *account, int i, int i1);


int main() {
    sysAccount * sb;
    int _id, _cell, _dp, _bal, n, k, i;

    cin >> n;

    sb = new sysAccount[n]();
    for (i = 0; i < n; i++) {
        cin >> _id >> _cell >> _dp >> _bal;
        sb[i].setId(_id);
        sb[i].setCell(_cell);
        sb[i].setDp(_dp);
        sb[i].setBal(_bal);
    }


    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> _cell >> _dp >> _bal;
        sysAccount *ptr = find_account_by_cell(sb, n, _cell);
        if(ptr == NULL){
            cout << "手机号不存在" << endl;
            continue;
        }
        if (ptr->getDp() == _dp) {
            if (ptr->getBal() >= _bal) {
                cout << "卡号" << ptr->getId() << "--余额" << ptr->getBal() - _bal << endl;
            } else {
                cout << "卡号" << ptr->getId() << "--余额不足" << endl;
            }
        } else {
            cout << "密码错误" << endl;
        }
    }
    return 0;
}

sysAccount *find_account_by_cell(sysAccount *account, int total, int cell) {
    for(int i = 0; i < total; i++){
        if(account[i].getCell() == cell){
            return &account[i];
        };
    }
    return NULL;
}
