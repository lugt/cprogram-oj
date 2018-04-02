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
    sysAccount sb[20], ass[20];
    int _id, _cell, _dp, _bal;
    int n;
    cin >> n;
    int i;
    for (i = 0; i < n; i++) {
        cin >> _id >> _cell >> _dp >> _bal;
        sb[i].setid(_id);
        sb[i].setcell(_cell);
        sb[i].setdp(_dp);
        sb[i].setbal(_bal);
    }
    int k;
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> _id >> _cell >> _dp >> _bal;
        ass[i].setid(_id);
        ass[i].setcell(_cell);
        ass[i].setdp(_dp);
        ass[i].setbal(_bal);
    }

    int j;
    int flag;
    result(sb, ass, n, i, k, j, flag);
    return 0;
}

void result(sysAccount *sb, sysAccount *ass, int n, int i, int k, int j, int flag) {
    for (j = 0; j < k; j++) {
        for (i = 0; i < n; i++) {
            if (ass[j].getid() == sb[i].getid()) {
                flag = i;
            }
        }

        if (ass[j].getcell() == sb[flag].getcell()) {
            if (ass[j].getdp() == sb[flag].getdp()) {
                if (ass[j].getbal() <= sb[flag].getbal()) {
                    cout << sb[flag].getid() << "--余额" << sb[flag].getbal() - ass[j].getbal() << endl;
                } else {
                    cout << sb[flag].getid() << "--余额不足" << endl;
                }
            } else {
                cout << "密码错误\n";
            }
        } else {
            cout << "手机号码不存在" << endl;
        }
    }
}