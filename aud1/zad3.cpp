#include<iostream>

using namespace std;

struct ComplexNumber {
    float real;
    float imag;

    void read() {
        cin >> real >> imag;
    }

    void print() {
        cout << real;

        if (imag >= 0) {
            cout << "+";
        }

        cout << imag << "i" << endl;
    }

};

ComplexNumber add(ComplexNumber c1, ComplexNumber c2) {
    return {
            c1.real + c2.real,
            c1.imag + c2.imag
    };
}

ComplexNumber sub(ComplexNumber c1, ComplexNumber c2) {
    return {
            c1.real - c2.real,
            c1.imag - c2.imag
    };
}

ComplexNumber multiply(ComplexNumber c1, ComplexNumber c2) {
    return {
            c1.real * c2.real - c1.imag * c2.imag,
            c1.real * c2.imag + c1.imag * c2.real
    };
}


int main() {
    ComplexNumber c1, c2, c3;

    c1.read();
    c2.read();

    c3 = add(c1, c2);
    c3.print();

    c3 = sub(c1, c2);
    c3.print();

    c3 = multiply(c1, c2);
    c3.print();
}




