#include <iostream>
#include <string.h>

using namespace std;

enum Position {
    EMPLOYEE,
    MANAGER,
    OWNER
};

class Person {
private:
    char name[100];
    int salary;
    Position position;
public:
    Person() {}

    Person(char *_name, int _salary, Position _position) {
        strcpy(name, _name);
        salary = _salary;
        position = _position;
    }

    ~Person() {};

    int getSalary() {
        return salary;
    }

    void print() {
        cout << name << " " << salary << " ";
        switch (position) {
            case 0:
                cout << "employee";
                break;
            case 1:
                cout << "manager";
                break;
            default:
                cout << "owner";
                break;
        };
        cout << endl;
    }
};


void sort(Person p[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (p[j].getSalary() < p[j + 1].getSalary()) {
                Person tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    Person p[n];

    char name[100];
    int salary, position;
    for (int i = 0; i < n; i++) {
        cin >> name >> salary >> position;
        p[i] = Person(name, salary, (Position) position);
    }

    sort(p, n);

    for (int i = 0; i < n; i++) {
        p[i].print();
    }

    return 0;
}