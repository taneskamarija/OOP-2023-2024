#include <iostream>
#include <string.h>

using namespace std;

enum Gender {
    MALE,
    FEMALE
};

class Mate {
private:
    char firstName[100], lastName[100];
    int age;
    Gender gender;

public:
    Mate() {}

    Mate(char *firstName, char *lastName, int age, Gender gender) {
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
        this->age = age;
        this->gender = gender;
    }

    Mate(const Mate &m) {
        strcpy(firstName, m.firstName);
        strcpy(lastName, m.lastName);
        age = m.age;
        gender = m.gender;
    }

    ~Mate() {}

    int getAge() {
        return age;
    }

    void print() {
        if (gender == 0) {
            cout << "Momche: ";
        } else {
            cout << "Devojche: ";
        }
        cout << firstName << " " << lastName << " " << age << " ";
    }
};

class Date {
private:
    Mate m1, m2;

public:
    Date(Mate &m1, Mate &m2) {
        this->m1 = m1;
        this->m2 = m2;
    }

    ~Date() {}

    void print() {
        cout << "Sredba: ";
        m1.print();
        m2.print();
        cout << endl;
    }

    void match() {
        if (abs(m1.getAge() - m2.getAge()) < 5) {
            cout << "Si odgovaraat" << endl;
        } else {
            cout << "Ne si odgovaraat" << endl;
        }
    }
};


int main() {
    char firstName[100], lastName[100];
    int age, gender;

    cout << "Vnesete informacii za momche:" << endl;
    cin >> firstName >> lastName >> age >> gender;
//    Mate boy(firstName, lastName, age, Gender::MALE);
    Mate m1(firstName, lastName, age, (Gender) gender);

    cout << "Vnesete informacii za devojche" << endl;
    cin >> firstName >> lastName >> age >> gender;
//    Mate girl(firstName, lastName, age, Gender::FEMALE);
    Mate m2(firstName, lastName, age, (Gender) gender);
    Date date(m1, m2);
    date.print();
    date.match();

    return 0;
}