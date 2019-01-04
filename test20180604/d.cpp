#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>
#include <memory.h>

using namespace std;

class CStudent {
private:
    int y;
    int m;
    int d;

    time_t timing;
    string name;

public:
    CStudent() : y(0), m(0), d(0) {};

    void set_t(int a, int b, int c) {
        y = a, m = b, d = c;
        struct tm temp;
        memset(&temp, 0, sizeof(tm));
        temp.tm_mon = b - 1;
        temp.tm_year = a - 1900;
        temp.tm_mday = c;
        timing = mktime(& temp);
    }

    int operator-(const CStudent &other) {
        return static_cast<int>(timing - other.timing) / 24 / 3600;
    }

    time_t getTime(){
        return timing;
    }

    void set_n(string basic_string) {
        name = basic_string;#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>
#include <memory.h>

        using namespace std;

        class CStudent {
        private:
            int y;
            int m;
            int d;

            time_t timing;
            string name;

        public:
            CStudent() : y(0), m(0), d(0) {};

            void set_t(int a, int b, int c) {
                y = a, m = b, d = c;
                struct tm temp;
                memset(&temp, 0, sizeof(tm));
                temp.tm_mon = b - 1;
                temp.tm_year = a - 1900;
                temp.tm_mday = c;
                timing = mktime(& temp);
            }

            int operator-(const CStudent &other) {
                return static_cast<int>(timing - other.timing) / 24 / 3600;
            }

            time_t getTime(){
                return timing;
            }

            void set_n(string basic_string) {
                name = basic_string;
            }

            string & getname(){
                return name;
            }
        };

        int sortme(const void *a, const void *b) {
            return **(CStudent **) a - **(CStudent **) b;
        }

        int main() {
            int t = 0, i = 0, y, m, d;
            string name;
            cin >> t;
            CStudent * Sa = new CStudent[t];
            for (i = 0; i < t; i++) {
                cin >> name >> y >> m >> d;
                Sa[i].set_t(y, m, d);
                Sa[i].set_n(name);
            }

            CStudent ** yy = (CStudent **) malloc(sizeof(CStudent **) * t);

            for(i = 0; i < t; i++){
                yy[i] = &(Sa[i]);
            }

            qsort(yy, t, sizeof(CStudent **), sortme);

            int num = *(yy[t-1]) - *(yy[0]);
            std::cout << yy[0]->getname() << "和" << yy[t - 1]->getname() << "年龄相差最大，为" << num << "天。" << endl;
            return 0;
        }
    }

    string & getname(){
        return name;
    }
};

int sortme(const void *a, const void *b) {
    return **(CStudent **) a - **(CStudent **) b;
}

int main() {
    int t = 0, i = 0, y, m, d;
    string name;
    cin >> t;
    CStudent * Sa = new CStudent[t];
    for (i = 0; i < t; i++) {
        cin >> name >> y >> m >> d;
        Sa[i].set_t(y, m, d);
        Sa[i].set_n(name);
    }

    CStudent ** yy = (CStudent **) malloc(sizeof(CStudent **) * t);

    for(i = 0; i < t; i++){
        yy[i] = &(Sa[i]);
    }

    qsort(yy, t, sizeof(CStudent **), sortme);

    int num = *(yy[t-1]) - *(yy[0]);
    std::cout << yy[0]->getname() << "和" << yy[t - 1]->getname() << "年龄相差最大，为" << num << "天。" << endl;
    return 0;
}