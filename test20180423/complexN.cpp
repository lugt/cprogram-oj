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

    friend Complex add_complecies(Complex x, Complex y){
        complex<int> cmp = x.x + y.x;
        Complex *u = new Complex(cmp.real(), cmp.imag());
        return u;
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
    int t, r_, i_;
    Complex c1, input;
    string sign;

    cin >> r_ >> i_ >> t;
    c1.set(r_,i_);
    for (int a = 0; a < t; ++a) {
        cin >>  sign >> r_ >> i_;
        input.set(r_,i_);
        if(sign == "-"){
            input.set(-1 * input.x.real(),-1 * input.x.imag());
        }
        c1 = add_complecies(c1, input);
        cout << "(" << c1.x.real() <<","<< c1.x.imag()<< ")" << endl;
    }
    return 0;
}