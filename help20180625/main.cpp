#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <sstream>

using namespace std;

static stringstream ss;

class CBook
{
private:
    string id;
    string name;
    int total_number;
    int number;
public:

    CBook() {
        name = "";
        number = 0;
        total_number = 0;
        id = "";
    }


    void setBatch(string id_1, string name_1, int total_number_1, int number_1){
        id = id_1;
        name = name_1;
        total_number = total_number_1;
        number = number_1;
    }

    string setid() { return id; }
    string getname() { return name; }
    int gettotal() { return total_number; }
    int setnumber() { return number; }
    string borrow(string name_1)
    {
        if (number >= 1)
        {
            number--;
            return id;
            //return id;
            //ss << endl;
        }
        else return "";
    }
    void print()
    {
        ss << id << " " << name << " " << total_number << " " << number<< endl;
    }
    void show()
    {
        int number_borrow = 0, number_leave = 0;

    }
};


int main()
{

    int n;
    cin >> n;
    CBook *p = new CBook[n];
    string id, name;
    int total_number,number,i;
    int number_borrow = 0, number_leave;
    for (i = 0; i < n; i++)
    {
        cin >> id >> name >> total_number >> number;
        if (total_number >= 0)
        {
            p[i].setBatch(id, name, total_number, number);
            number_borrow += p[i].gettotal();
        }
    }
    int total = number_borrow;
    int m;
    cin >> m;
    string name_;
    //int last;
    while(m--)
    {
        cin >> name_;
        for (i = 0; i < n; i++)
        {
            if (name_ == p[i].getname())
            {
                string a = p[i].borrow(name_);
                if(a == ""){
                    ss << p[i].getname() << " 该书已全部借出";
                } else{
                    ss << p[i].getname() << " 索取号: "<< a;
                }

                number_borrow--;
                //ss << id;
            }
            else
                continue;
        }
        ss << endl;
    }
    ss << endl;
    number_leave = total - number_borrow;
    for (i = 0; i < n; i++)
    {
        p[i].print();
    }
    ss << "借出图书: " << number_borrow << "本  剩余馆藏图书: " << number_leave << "本" << endl;

    string sma = ss.str();
    cout << ss.str();

    getchar();
    getchar();
    //system("pause");
    return 0;
}

/**
4
TP312JA-43/L99  Java语言程序设计教程  3 0
TP312PH/Q68b PHP7内核剖析 3 2
TP311.561-43/L93 Python大学教程 3 1
TP311.5-43/M18a1(2) 软件工程基础 3 3
4
Java语言程序设计教程
软件工程基础
Python大学教程
Python大学教程

 * */