#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Count {
protected:
    int val;
public:
    Count(int va) : val(va) {}
    int increment() {
        val++;
        if (val == 60)
            val = 0;
        return val;
    }
};

class Calc : public Count {
private:
    int __min;
    int __max;
public:
    Calc(int v, int min, int max) : Count(v), __min(min), __max(max) {}

    int increment() {
        val++;
        if (val == __max)
            val = 0;
        return val;
    }

    int getVal() { return val; }
};

class Clock {
public:
    Calc h_, m_, s_;
    Clock(int _h, int _m, int _s) : h_(_h, 0, 24), m_(_m, 0, 60), s_(_s, 0, 60) {}
    void time(int n) {
        int hour, minute, second, t;
        hour = h_.getVal();
        minute = m_.getVal();
        second = s_.getVal();
        for (t = 0; t < n; t++) {
            second = s_.increment();
            if (second == 0) {
                minute = m_.increment();
                if (minute == 0) {
                    hour = h_.increment();
                }
            }
        }
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    int h, m, s, k, t;
    cin >> t;
    while (t--) {
        cin >> h >> m >> s >> k;
        Clock sb(h, m, s);
        sb.time(k);
    }
}
