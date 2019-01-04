//
// Created by Someone on 2018/5/14.
//

#include<iostream>
#include<string>

using namespace std;

class BaseAccount
{
public:
    BaseAccount(string n,string a,int b) :name(n),account(a),balance(b) {}
    void depoist(int money)
    {
        balance += money;
    }
    void withdraw(int money_1)
    {
        if(money_1 > balance)
            cout<<"insufficient"<<endl;
        else
            balance -= money_1;
    }
    void display()
    {
        cout << name << " " <<
             account << " Balance:" << balance << endl;
    }

protected:
    string name, account;
    int balance;
};

class BasePlus : public BaseAccount
{
public:
    BasePlus(string name_1,string account_1,int balance_1) : BaseAccount(name_1,account_1,balance_1),limit(5000) {}
    void withdraw_1(int money)
    {
        if(money>balance+limit)
        {
            balance = balance;
            limit = 5000;
            cout<<"insufficient"<<endl;
        }
        else if(money>balance&&money<=balance+limit)
        {

            limit  -= (money - balance) ;
            balance = 0;
        }
        else if(money <=balance)
            balance -= money;
        else
            cout<<"insufficient"<<endl;
    }

protected:
    int limit,limit_sum;

public:
    void display()
    {
        cout << name << " " << account
            <<" Balance:"<<balance
            <<" limit:"<<limit<<endl;
    }
};

int main()
{
    int t;
    cin>>t;
    string n,a;
    int b,dep1,wid1,dep2,wid2;
    while(t--)
    {
        cin >> n >> a>>b >> dep1>>wid1 >>dep2>>wid2;
        if(a[1] == 'A')
        {
            BaseAccount * account = new BaseAccount(n,a,b);
            account->depoist(dep1);
            account->withdraw(wid1);
            account->depoist(dep2);
            account->withdraw(wid2);
            account->display();
        }
        else if(a[1] == 'P')
        {
            BasePlus plus(n,a,b);
            plus.depoist(dep1);
            plus.withdraw_1(wid1);
            plus.depoist(dep2);
            plus.withdraw_1(wid2);
            plus.display();
        }else{
        }
    }
    return 0;
}

