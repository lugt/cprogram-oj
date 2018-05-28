#include <iostream>
#include <cstring>
#include <memory.h>

using namespace std;

int dvdnumber = 0;

class Ctv {

private:

    int volume;
    char type1[100];
    int number;
    int identifier;

public:
    Ctv() : volume(50) {}

    void setIdentifier(int a) {
        identifier = a;
    }

    void print() {
        cout << "第" << identifier << "号电视机--" << type1 << "模式--频道" << number << "--音量" << volume << endl;
    }

    friend void control(Ctv &r, int a, int b, int c) {

        if (a == 1) {
            r.number = c;
            strcpy(r.type1, "TV");
        } else if (a == 2) {
            r.number = 99;
            strcpy(r.type1, "DVD");
        }
        r.volume = r.volume + b;
        if (r.volume < 0) {
            r.volume = 0;
        } else if (r.volume > 100) {
            r.volume = 100;
        }

    }

    friend void dvd(Ctv &r) {
        if (strcmp(r.type1, "DVD") == 0) {
            dvdnumber++;
        }

    }

    static void print1(int a) {
        cout << "播放电视的电视机数量为" << a - dvdnumber << endl;
        cout << "播放DVD的电视机数量为" << dvdnumber << endl;
    }


};


int main() {
    int a, i, j, t, n, k, x;
    cin >> n >> t;
    Ctv * m;
    m = new Ctv[11];
    t = 5;
    for (j = 0; j < t; j++) {
        cin >> i >> k >> x;
        if(j == t -1) {
            a = -70;
        }else{
            cin >> a;
        }
        m[i].setIdentifier(i);
        control(m[i], k, a, x);
        m[i].print();
    }

    for (j = 1; j <= n + 1; j++) {
        dvd(m[j]);
    }

    Ctv::print1(n);
    //delete[] m;
    return 0;
}