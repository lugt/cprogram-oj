#include<iostream>
using namespace std;
class Animal
{
protected:
    string name,type;
    int old;
public:
    virtual void speak() {}
};
class Tiger : public Animal
{
protected:
    string name,type;
    int old;
public:
    Tiger(string t,string n,int o) : type(t),name(n),old(o){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",AOOO."<<endl;
    }
};

class Dog : public Animal
{
protected:
    string name,type;
    int old;
public:
    Dog(string t,string n,int o) : type(t),name(n),old(o){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",WangWang."<<endl;
    }
};

class Ducl : public Animal
{
protected:
    string name,type;
    int old;
public:
    Ducl(string & t,string & n,int o) : type(t),name(n),old(o){}
public:
    void speak()
    {
        cout<<"Hello,I am "<<name<<",GAGA."<<endl;
    }
};

class Pig : public Animal
{
protected:
    string name,type;
    int old;
public:
    Pig(string & t,string & n,int o) : type(t),name(n),old(o){}
    void speak()
    {
        cout<<"Hello,I am "<<name<<",HENGHENG."<<endl;
    }
};
int main()
{
    int t, old;
    string type,name;

    Animal * p_animal;
    cin>>t;
    while(t--)
    {
        cin >> type >> name >> old;
        if(type == "Tiger")
        {
            p_animal = new Tiger(type,name,old);
        }
        else if(type == "Dog")
        {
            p_animal = new Dog(type,name,old);
        }
        else if(type == "Duck")
        {
            p_animal = new Ducl(type,name,old);
        }
        else if(type == "Pig")
        {
            p_animal = new Pig(type,name,old);
        }
        else {
            cout << "There is no " << type << " in our Zoo." << endl;
            continue;
        }
        p_animal->speak();
    }
    return 0;
}
