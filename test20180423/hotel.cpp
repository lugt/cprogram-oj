//
// Created by lugt on 2018/4/23.
//

#include<iostream>
#include<string>
#include <list>

using namespace std;

class Customer{


private:
    static int customCount, rent, year;
    int customId;
    string cusName;

public:

    Customer(){}

    ~Customer(){};

    static void changeYear(int y){
        year = y;
    }

    void display_info(){
        std::cout << cusName << " " << Customer::customId << " " << Customer::customCount << " " << Customer::rent << endl;
    }


public:
    static int getCustomCount() {
        return customCount;
    }

    static void setCustomCount(int customCount) {
        Customer::customCount = customCount;
    }

    static int getRent() {
        return rent;
    }

    static void setRent(int rent) {
        Customer::rent = rent;
    }

    static int getYear() {
        return year;
    }

    static void setYear(int year) {
        Customer::year = year;
    }

    int getCustomId() const {
        return customId;
    }

    void setCustomId(int customId) {
        Customer::customId = customId;
    }

    const string &getCusName() const {
        return cusName;
    }

    void setCusName(const string & cusName) {
        Customer::cusName = cusName;
    }
};

int Customer::rent, Customer::year, Customer::customCount;

int main(int argc, char **argv){

    int t, y, count;
    string name_;
    Customer cus;
    Customer::setRent(0);
    Customer::setCustomCount(0);
    Customer::setYear(2000);

    list<Customer> customers;

    cin >> t;
    while(t--){
        cin >> y;
        Customer::changeYear(y);
        while(name_ != "0"){
            cin >> name_;
            if(name_ != "0"){
                Customer::setCustomCount(static_cast<int>(customers.size() + 1));
                Customer::setRent(Customer::getRent() + 150);
                cus.setCustomId(Customer::getCustomCount() + Customer::getYear() * 10000);
                cus.setCusName(name_);
                cus.display_info();
                customers.push_back(cus);
            }
        }
        name_ = "";
    }
}