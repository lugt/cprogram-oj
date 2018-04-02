//
// Created by lugt on 2018/4/2.
//

#ifndef TEST20180402_CLS_PTR_H
#define TEST20180402_CLS_PTR_H

#include<iostream>

using namespace std;

class Student {
private:
    string sex;
    long number;
    string collage;
    long tel;
public:
    void NAME(string name_1) { name = name_1; }

    void SEX(string sex_1) { sex = sex_1; }

    long NUMBER(long number_1) { return number_1; }

    void COLLEGE(string collage_1) { collage = collage_1; }

    long TEL(long tel_1) { return tel_1; }

    string name;
};

void Sort(Student ptr[], int n) {
    int i, j;
    string name_temp;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++) {
            if (ptr[i].name.compare(ptr[i + 1].name));
            {
                name_temp = ptr[i].name;
                ptr[i].name = ptr[i + 1].name;
                ptr[i + 1].name = name_temp;
            }
        }
}


int main(void) {
    int t;
    cin >> t;
    Student *sb;
    string name_2;
    string sex_2;
    long number_2;
    string collage_2;
    long tel_2;
    sb = new Student[t];

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        sb[i].NAME(str);

        cin >> str;
        sb[i].SEX(str);

        cin >> tel_2;
        sb[i].NUMBER(tel_2);

        cin >> str;
        sb[i].COLLEGE(str);

        cin >> tel_2;
        sb[i].TEL(tel_2);
    }

    Sort(sb, t);

    for (int i = 0; i < t; i++)
        cout << sb[i].name << endl;
    return 0;
}


#endif //TEST20180402_CLS_PTR_H
