#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char name[100];
    int id;
    float GPA;

    static int numStudents;
    static float totalGPA;

public:
    Student() {}

    Student(char *name, int id, float GPA) {
        strcpy(this -> name, name);
        this -> id = id;
        this -> GPA = GPA;

        numStudents++;
         totalGPA+=GPA;
    }

    ~Student(){}

    char * getName() {return name;}
    int getID() {return  id;}

    static int getNumStudents() {return numStudents;}
    static float getTotalGPA() {return totalGPA;}

};

int Student::numStudents = 0;
float Student::totalGPA = 0.0;


int main() {
    int n;
    cin >> n;
    Student students[n];
    char name[100];
    int id;
    float GPA;
    for (int i=0; i<n; i++) {
        cin >> name >> id >> GPA;
        students[i] = Student(name, id, GPA);
    }

    for (int i=0; i<n; i++) {
        cout << students[i].getName() << " " << students[i].getID() << endl;
    }

    cout << "Total students: " << Student::getNumStudents() << endl;
    cout << "Total GPA: " << Student::getTotalGPA() << endl;

}