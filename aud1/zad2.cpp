#include<iostream>

using namespace std;


struct Vector {
    float x, y, z;

    void read() {
        cin >> x >> y >> z;
    }

    void print() {
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }
};

float scalarProduct(Vector v1, Vector v2) {
    float scalar = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return scalar;
}

Vector vectorProduct(Vector v1, Vector v2) {
    return {
            v1.y * v2.z - v1.z * v2.y,
            v1.z * v2.x - v1.x * v2.z,
            v1.x * v2.y - v1.y * v2.x
    };
}


int main() {
    Vector v1, v2;
    v1.read();
    v2.read();

    cout << "Scalar product: " << scalarProduct(v1, v2) << endl;
    cout << "Vector product: ";
    vectorProduct(v1, v2).print();

    return 0;
}