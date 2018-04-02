//
// Created by lugt on 2018/4/2.
//

#ifndef TEST20180402_CLS_PTR_H
#define TEST20180402_CLS_PTR_H
#include<iostream>

using namespace std;
class Student
{
private:
    string name;
    string sex;
    long number;
    string collage;
    long tel;
public:
    void NAME(string name_1)
    { name = name_1; }
    void SEX(string sex_1)
    { sex = sex_1; }
    long NUMBER(long number_1)
    { return number_1; }
    void COLLAGE(string collage_1)
    { collage = collage_1; }
    long TEL(long tel_1)
    { return tel_1; }
};
void Sort(Student ptr[], int n)
{
    int i, j;
    Student temp.NAME;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++)
        {
            if(ptr[i].NAME < ptr[i + 1].NAME);
            {
                temp.NAME =ptr[i].NAME;
                ptr[i].NAME = ptr[i+1].NAME;
                ptr[i+1].NAME = temp.NAME ;
            }
        }
}



int main(void)
{
    int t;
    cin>>t;
    Student *sb;
    string name_2;
    string sex_2;
    long number_2;
    string collage_2;
    long tel_2;
    sb = new Student[t];
    for(int i = 0 ; i<t; i++)
    {
        cin>>sb[i].NAME(name_2)
           >>sb[i].SEX(sex_2)
           >>sb[i].NUMBER(number_2)
           >>sb[i].COLLAGE(collage_2)
           >>sb[i].TEL(tel_2);
    }
    Sort(sb , t);
    for(int i = 0; i<t; i++)
        cout<<sb[i].NAME<<endl;
    return 0;
}


#endif //TEST20180402_CLS_PTR_H
