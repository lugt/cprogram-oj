//
// Created by lugt on 2018/6/11.
//

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

using namespace std;

template<class Arr_Typ, class Targ>
void Sorting(Arr_Typ *a, Targ b) {
    int i, j;
    Arr_Typ x;
    for (i = 0; i < b; i++) {
        for (j = i + 1; j < b; j++) {
            if (a[i] > a[j]) {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }

}

void Sorting(char *a, int b, void * s_ptr) {
    int i, j;
    char c[100] = {};
    memset(c,0,100);
    for (i = 0; i < b; i++) {
        for (j = i + 1; j < b; j++) {
            if (strcmp((a+i*100), (a+100*j)) > 0) {
                strcpy(c, (a+100*i));
                strcpy((a+100*i), (a+100*j));
                strcpy((a+100*j), c);
            }
        }
    }
}


int main() {

    int b, c[100] = {}, i, j, t;
    double d[100] = {};
    char e[100];
    char *f, key;

    cin >> t;

    f = (char *) calloc(1000, 50);
    for (i = 0; i < t; i++) {
        cin >> key;
        memset(f,0,50*1000);
        memset(c,0,100 * sizeof(int));
        memset(d,0,100 * sizeof(double));
        memset(e,0,100 * sizeof(char));
        if (key == 'I') {
            cin >> b;
            for (j = 0; j < b; j++) {
                cin >> c[j];
            }

            Sorting(c, b);
            for (j = 0; j < b; j++) {
                if (j != b - 1)
                    cout << c[j] << ' ';
                else
                    cout << c[j] << endl;

            }
        } else if (key == 'D') {
            cin >> b;
            for (j = 0; j < b; j++) {
                cin >> d[j];
            }

            Sorting(d, b);
            for (j = 0; j < b; j++) {
                if (j != b - 1)
                    cout << d[j] << ' ';
                else
                    cout << d[j] << endl;

            }
        } else if (key == 'C') {
            cin >> b;
            for (j = 0; j < b; j++) {
                cin >> e[j];
            }

            Sorting(e, b);
            for (j = 0; j < b; j++) {
                if (j != b - 1)
                    cout << e[j] << ' ';
                else
                    cout << e[j] << endl;

            }
        } else if (key == 'S') {
            cin >> b;
            string s;
            for (j = 0; j < b; j++) {
                cin >> s;
                strncpy((f + 100 * j), s.c_str(), s.size() + 1);
            }
            Sorting(f, b, NULL);
            for (j = 0; j < b; j++) {
                if (j != b - 1)
                    cout << (f+j*100) << ' ';
                else
                    cout << (f+j*100) << endl;

            }

        }

    }
    getchar();
    return 0;
}
