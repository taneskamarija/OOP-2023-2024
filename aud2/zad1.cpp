#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    int a, b, c;

public:
    Triangle(int aa, int bb, int cc) {
        a = aa;
        b = bb;
        c = cc;
    }

    ~Triangle() {}

    int permeter() {
        return a + b + c;
    }

    float area() {
        float s = permeter() / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    Triangle t(a, b, c);

    cout << "Area: " << t.area() << endl;
    cout << "Permeter: " << t.permeter() << endl;

    return 0;
}