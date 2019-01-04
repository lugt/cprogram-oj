//
// Created by lugt on 2018/4/23.
//
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Account {

public:
    Account(string accno, string name, float banlance) {
        _accno = accno;
        _accname = name;
        _banlance = banlance;
    }

private:

    static int count;
    static float m_rate;
    string _accno, _accname;
    float _banlance;

public:

    ~Account() {
    }

    void depositMoney(float amount) {
        _banlance += amount;
    }

    void retreatMoney(float amount) {
        _banlance -= amount;
    }

    float GetBanlance() {
        return _banlance;
    }

    static int GetCount(int num) {
        Account::count = num;
    }

    static int GetInterestRate(float rate_value) {
        Account::m_rate = rate_value;
    }

    friend void Update(Account &a) {
        a._banlance *= (m_rate + 1);
    }

    void print_first() {
        cout << _accno << " " << _accname;
    }

    void print_second() {
        cout << " " << _banlance;
    }
};

int Account::count = 0;
float Account::m_rate = 0;

int main() {
    int customNums;
    float iRate, Despo, Outo, Balance, ttemp_, sum_of_balance = 0;
    string customerId, cusName_;
    cin >> iRate >> customNums;
    Account::GetCount(customNums);
    Account::GetInterestRate(iRate);
    while (customNums--) {
        cin >> customerId >> cusName_ >> Balance >> Despo >> Outo;
        Account Person(customerId, cusName_, Balance);
        Person.print_first();
        Person.depositMoney(Despo);
        Person.print_second();
        Update(Person);
        Person.print_second();
        Person.retreatMoney(Outo);
        Person.print_second();
        ttemp_ = Person.GetBanlance();
        sum_of_balance += ttemp_;
        cout << endl;
    }
    cout << sum_of_balance << endl;
    return 0;
}
