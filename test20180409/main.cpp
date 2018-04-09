#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

class Complex{
public:

    Complex(Complex *pComplex) {
        x = pComplex->x;
    }

    std::complex<int> x;

    Complex () { x = 0; };

    Complex(const Complex & from){
        x = from.x;
    }

    Complex(int real, int imagine){
        x.imag(imagine);
        x.real(real);
    }

    Complex operator+(Complex y){
        complex<int> cmp = x + y.x;
        Complex *u = new Complex(cmp.real(), cmp.imag());
        return u;
    }

    Complex operator-(Complex y){
        complex<int> cmp = x - y.x;
        Complex *v = new Complex(cmp.real(), cmp.imag());
        return v;
    }

    void print(){
        //cout << x;
        if(x.real() == 0){
            if(x.imag() > 0){
                if(x.imag() == 1){
                    std::cout << "i";
                }else{
                    std::cout << x.imag() << "i";
                }

            }else if(x.imag() == 0) {
                std::cout << "0";
            }else{
                std::cout << x.imag() << "i";
            }
        }else{

            std::cout << x.real();

            if(x.imag() > 0){
                if(x.imag() == 1){
                    std::cout << "+" << "i";
                }else{
                    std::cout << "+" << x.imag() << "i";
                }
            }else if(x.imag() == 0) {
            }else{
                std::cout << x.imag() << "i";
            }
        }

    }

    void set(int d, int d1) {
        x.real(d);
        x.imag(d1);
    }
};


int main() {
    int t, r = 0, i = 0, a;
    Complex c1, c2;
    cin >> t;
    for (int a = 0; a < t; ++a) {
        cin >> r >> i;
        c1.set(r,i);
        cin >> r >> i;
        c2.set(r,i);

        Complex total = c1 + c2;
        Complex remain = c1 - c2;

        cout << "sum:";
        total.print();
        cout << endl;

        cout << "remainder:";
        remain.print();
        cout << endl;
    }
    return 0;
}