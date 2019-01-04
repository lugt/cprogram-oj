//
// Created by lugt on 2018/5/28.
//

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

    Complex operator*(Complex y){
        complex<int> cmp = x * y.x;
        Complex *v = new Complex(cmp.real(), cmp.imag());
        return v;
    }

    void print(){
        //cout << x;
        /*
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
        }*/
        std::cout << "Real=" << x.real() <<" Image="<<x.imag()<<endl;
    }

    void set(int d, int d1) {
        x.real(d);
        x.imag(d1);
    }
};


int main() {
    int r_, i_;
    Complex c1, c2;
    string sign;

    cin >> r_ >> i_;
    c1.set(r_,i_);

    cin >> r_ >> i_;
    c2.set(r_,i_);

    (c1 + c2).print();
    (c1 - c2).print();
    (c1 * c2).print();
    return 0;
}
