#include<iostream>
#include<cstring>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date() {}

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date(const Date &d) {
        this->day = d.day;
        this->month = d.month;
        this->year = d.year;
    }

    void print() {
        cout << day << "." << month << "." << year;
    }

    int getDay() {
        return day;
    };

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }
};

int compareDates(Date d1, Date d2) {
    if (d1.getYear() > d2.getYear()) {
        return 1;
    } else if (d1.getYear() < d2.getYear()) {
        return -1;
    } else {
        if (d1.getMonth() > d2.getMonth()) {
            return 1;
        } else if (d1.getMonth() < d2.getMonth()) {
            return -1;
        } else {
            if (d1.getDay() > d2.getDay()) {
                return 1;
            } else if (d1.getDay() < d2.getDay()) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

class Employee {
private:
    char name[20];
    int salary;
    Date birthdate;
public:

    Employee(char *name = "", int salary = 0, Date birthdate = Date()) {
        strcpy(this->name, name);
        this->salary = salary;
        this->birthdate = birthdate;
    }

    ~Employee() {}

    char *getName() {
        return name;
    }

    Date getBirthdate() {
        return birthdate;
    }

    int getSalary() {
        return salary;
    }
};

Employee getHighestPaid(Employee e[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (e[max].getSalary() < e[i].getSalary()) {
            max = i;
        }
    }
    return e[max];
}

Employee getYoungest(Employee e[], int n) {
    Employee youngest = e[0];

    for (int i = 1; i < n; i++) {
        if (compareDates(youngest.getBirthdate(), e[i].getBirthdate()) == 1) {
            youngest = e[i];
        }
    }

    return youngest;
}

bool checkName(char *name) {
    return (strlen(name) <= 20);
}


Employee getEmployee() {
    char name[20];
    int salary;
    int day, month, year;

    cin >> name;
    if (checkName(name)) {
        cin >> salary;
        cin >> day >> month >> year;
        return Employee(name, salary, Date(day, month, year));
    } else {
        return Employee();
    }
}


int main() {
    int n;
    cin >> n;
    Employee e[n];

    for (int i = 0; i < n; i++) {
        e[i] = getEmployee();
        if (strcmp(e[i].getName(), "") == 0) {
            cout << "invalid input";
            return -1;
        }
    }

    cout << "Highest paid employee is " << getHighestPaid(e, n).getName() << endl;
    cout << "Youngest employee is " << getYoungest(e, n).getName() << endl;

    return 0;
}





