#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class CClock {

private:
    int hour;
    int min;
    int sec;

public:

    CClock(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
    }

    CClock operator++() {
        sec++;
        if (sec >= 60) {
            min++;
            sec = sec % 60;
            if (min >= 60) {
                hour++;
                min = min % 60;
                if (hour > 11)
                    hour = 0;
            }
        }
        return *this;
    }


    CClock operator--(int) {
        CClock x(*this);
        sec--;
        if (sec < 0) {

            min--;
            sec = 59;

            if (min < 0) {

                min = 59;
                hour--;

                if (hour < 0) {
                    hour = 11;
                }
            }


        }
    }

    void show() {
        cout << hour << ':' << min << ':' << sec << endl;
    }
};

int main() {

    int u, v, z, d, it_a, it_b, while_it;
    cin >> u >> v >> z;
    cin >> while_it;
    CClock x(u, v, z);
    for (it_a = 0; it_a < while_it; it_a++) {
        cin >> d;
        if (d >= 0) {
            for (it_b = 0; it_b < d; it_b++) {
                ++x;
            }
        } else {
            d = -d;
            for (it_b = 0; it_b < d; it_b++) {
                x--;
            }

        }
        x.show();

    }
    return 0;
}