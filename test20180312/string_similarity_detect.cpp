//
// Created by lugt on 2018/3/26.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>
#include <ctime>
//#include "list.h"

using std::cin;
using std::cerr;
using std::cout;
using std::string;
using std::endl;


class Test {
public:
    string t1, t2, t3;
};

int maixxxsn() {
    int t;
    cin >> t;
    string t1, t2, t3;
    std::vector<Test> tests;
    while (t--) {
        Test tt;
        cin >> t1 >> t2 >> t3;
        tt.t1 = t1;
        tt.t2 = t2;
        tt.t3 = t3;
        tests.push_back(tt);
    }

    for (std::vector<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->t1;
    }

}


#include<iostream>
#include<cstring>

using namespace std;

int xiao(int a, int b);

struct paper {
    int no;
    char a[100];
    char b[100];
    char c[100];
};

int compare(paper *p, paper *q);

int main_exams() {
    paper *a;
    int n, i, j, k;
    cin >> n;
    a = new paper[n];
    for (i = 0; i < n; i++) {
        cin >> a[i].no;
        cin >> a[i].a;
        cin >> a[i].b;
        cin >> a[i].c;
    }
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {
            k = compare(&a[i], &a[j]);
            if (k != 0)
                cout << a[i].no << " " << a[j].no << " " << k << endl;
        }
}

int compare(paper *p, paper *q) {
    int i, l, m, x = 0;
    l = strlen(p->a);
    m = strlen(q->a);
    l = xiao(l, m);
    for (i = 0; i < l; i++) if (p->a[i] == q->a[i]) x++;
    if (x >= l * 9 / 10) return 1;
    x = 0;
    l = strlen(p->b);
    m = strlen(q->b);
    l = xiao(l, m);
    for (i = 0; i < l; i++) if (p->b[i] == q->b[i]) x++;
    if (x >= l * 9 / 10) return 2;
    x = 0;
    l = strlen(p->c);
    m = strlen(q->c);
    l = xiao(l, m);
    for (i = 0; i < l; i++) if (p->c[i] == q->c[i]) x++;
    if (x >= l * 9 / 10) return 3;
    return 0;
}

int xiao(int a, int b) { if (a < b) return a; else return b; }

