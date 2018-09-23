#include <iostream>

using namespace std;

template<class T>
class Matricies {
public:

    void read() {
        int i, j;
        for (i = 0; i < hei; i++) {
            for (j = 0; j < wid; j++) {
                cin >> data_ptr[i][j];
            }
        }
    }

    Matricies(int _m, int _n) {
        hei = _m;
        wid = _n;
        data_ptr = new T *[hei];
        int i, j;
        for (i = 0; i < hei; i++) {
            data_ptr[i] = new T[wid];
        }
    }

private:

    T **data_ptr;
    unsigned int hei, wid;

public:


    void echo() {
        int i, j;
        for (i = 0; i < hei; i++) {
            for (j = 0; j < wid; j++) {
                if (j == wid - 1)
                    cout << data_ptr[i][j] << endl;
                else cout << data_ptr[i][j] << ' ';
            }
        }
    }

    Matricies transform() {
        int i, j;
        Matricies t(wid, hei);
        for (i = 0; i < wid; i++) {
            for (j = 0; j < hei; j++) {
                t.data_ptr[i][j] = data_ptr[j][i];
            }
        }
        return t;
    }

    ~Matricies() {
        int i;
        for (i = 0; i < hei; i++)
            delete[] data_ptr[i];
        delete[] data_ptr;
    }

};


int main() {
    char o;
    int height, width, t;
    cin >> t;
    while (t--) {
        cin >> o;
        if (o == 'I') {
            cin >> height >> width;
            Matricies<int> mat(height, width);
            mat.read();
            mat.transform().echo();
        }
        if (o == 'D') {
            cin >> height >> width;
            Matricies<double> mat(height, width);
            mat.read();
            mat.transform().echo();
        }
        if (o == 'C') {
            cin >> height >> width;
            Matricies<char> mat(height, width);
            mat.read();
            mat.transform().echo();
        }
    }


    return 0;

}