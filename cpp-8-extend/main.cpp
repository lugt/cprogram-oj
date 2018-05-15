#include <iostream>
#include <cstdio>
using namespace std;
class CAccount {
public :

    CAccount() {

    }

    float balance;
    string name;

    void deposit(float amount){
        balance += amount;
        cout << "saving ok!" << endl;
        show_value();
    }

    virtual void cash(float  amount){
        if(balance >= amount) {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        }else{
            cout << "sorry! over balance!"<< endl;
        }
        show_value();
    }

    CAccount(long id, string name_, float balance_){
        name = name_;
        balance = balance_;
        show_value();
    }

    void show_value(){
        cout << "balance is "; //name << "'s
        printf("%.0f",balance);
        cout << endl;
    }


};

class CCreditCard : public CAccount{
public :
    float limit;
    void cash(float  amount) {
        if (balance + limit >= amount) {
            balance -= amount;
            cout << "withdraw ok!" << endl;
        } else {
            cout << "sorry! over limit!" << endl;
        }
        show_value();
    }
    CCreditCard();
};

CCreditCard::CCreditCard(){};

/*
 *
1000 Tom 1000
500
1000
2000 John 500 500
500
1501
 *
 */

int main(){
    //for (int i = 0; i < 2; ++i) {
    int id;
    float money;
    string name;
    cin >> id >> name >> money;
    CAccount * acc = new CAccount(id,name,money);
    cin >> money;
    acc->deposit(money);
    cin >> money;
    acc->cash(money);
    acc->show_value();
    float limit;
    cin >> id >> name >> money >> limit;
    CCreditCard * ac;
    ac = new CCreditCard();
    //ac->id = id;
    ac->name = name;
    ac->balance = money;
    ac->limit = limit;
    cin >> money;
    ac->deposit(money);
    cin >> money;
    ac->cash(money);
    //}

}


/*
 *
 * 存折类具有帐号（account, long）、姓名（name,char[10])、
 * 余额（balance,float）等数据成员，可以实现存款（deposit,操作成功提示“saving ok!”)、
 * 取款（withdraw，操作成功提示“withdraw ok!”）和查询余额（check）的操作，
 * 取款金额必须在余额范围内，否则提示“sorry! over balance!”。
 */