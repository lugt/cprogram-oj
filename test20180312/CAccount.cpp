
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
class CAccount {
public :

    float balance;
    string name;

    void deposit(float amount){
        balance += amount;
        cout << "saving ok!" << endl;
        show_value();
    }

    void cash(float  amount){
        if(balance >= amount) {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        }else{
            cout << "sorry! over limit!"<< endl;
        }
        show_value();
    }

    CAccount(long id, string name_, float balance_){
        name = name_;
        balance = balance_;
        show_value();
    }

    void show_value(){
        cout << name << "'s balance is ";
        printf("%.0f",balance);
        cout << endl;
    }


};

int main_deposit(){
    for (int i = 0; i < 2; ++i) {
        int id;
        float money;
        string name;
        cin >> id >> name >> money;
        CAccount * acc = new CAccount(id,name,money);
        cin >> money;
        acc->deposit(money);
        cin >> money;
        acc->cash(money);
    }

}


/*
 *
 * 存折类具有帐号（account, long）、姓名（name,char[10])、
 * 余额（balance,float）等数据成员，可以实现存款（deposit,操作成功提示“saving ok!”)、
 * 取款（withdraw，操作成功提示“withdraw ok!”）和查询余额（check）的操作，
 * 取款金额必须在余额范围内，否则提示“sorry! over balance!”。
 */
