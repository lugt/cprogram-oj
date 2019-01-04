//
// Created by lugt on 2018/6/11.
//

#include<iostream>

using namespace std;

template<class T>
class _number_ {
private:
    T num[100];
    int length;
public:
    _number_(int n, T *a);

    void insert_at(int n, T a);

    void deletenum(int n);

    void print();
};

template<class T>
_number_<T>::_number_(int n, T *a) {
    length = n;
    for (int i = 0; i < length; i++)
        num[i] = a[i];
}

template<class T>
void _number_<T>::insert_at(int n, T a) {
    for (int i = length; i > n; i--) {
        num[i] = num[i - 1];
    }
    num[n] = a;
    length++;
}

template<class T>
void _number_<T>::deletenum(int n) {
    for (int i = n; i < length - 1; i++)
        num[i] = num[i + 1];
    num[length - 1] = '\0';
    length--;
}

template<class T>
void _number_<T>::print() {
    for (int i = 0; i < length; i++) {
        cout << num[i];
        if (i != length - 1)
            cout << " ";
    }
    cout << endl;
}

int main() {

    int position, deletenum, num, number;
    int *a;
    float *b, number2;

    cin >> num;
    a = new int[num];

    for (int i = 0; i < num; i++)
        cin >> a[i];
    _number_<int> p1(num, a);

    cin >> position >> number;
    p1.insert_at(position, number);

    cin >> deletenum;
    p1.deletenum(deletenum);
    p1.print();

    cin >> num;

    b = new float[num];

    for (int i = 0; i < num; i++) {
        cin >> b[i];
    }

    _number_<float> p2(num, b);

    cin >> position >> number2;
    p2.insert_at(position, number2);
    cin >> deletenum;
    p2.deletenum(deletenum);
    p2.print();

    delete[]a;
    delete[]b;
}