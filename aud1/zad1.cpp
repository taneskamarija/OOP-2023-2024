#include <iostream>
#include <cmath>

using namespace std;

struct Date {
    int day, month, year;

    void read() {
        cin >> day >> month >> year;
    }

    void print() {
        cout << day << "." << month << "." << year;
    }
};


int compare(Date d1, Date d2) {
    if (d1.year > d2.year) {
        return 1;
    } else if (d1.year < d2.year) {
        return -1;
    } else {
        if (d1.month > d2.month) {
            return 1;
        } else if (d1.month < d2.month) {
            return -1;
        } else {
            if (d1.day > d2.day) {
                return 1;
            } else if (d1.day < d2.day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int daysDiff(Date d1, Date d2) {
    int diff = d1.day - d2.day;
    diff += (d1.month - d2.month) * 30;
    diff += (d1.year - d2.year) * 365;
    return diff;
}


int main() {
    Date d1, d2;
    d1.read();
    d2.read();


//    int diff = daysDiff(d1, d2);
//    if (diff == 0) {
//        cout << "Dates are equal" << endl;
//    } else if (diff > 1) {
//        cout << "The difference in days between the first and second date is " << diff;
//    } else {
//        cout << "The difference in days between the second and first date is " << abs(diff);
//    }

    int comp = compare(d1, d2);

    if (comp == 0) {
        cout << "Dates are equal" << endl;
    } else if (comp > 0) {
        cout << "The difference in days between the first and second date is " << daysDiff(d1, d2);
    } else {
        cout << "The difference in days between the second and first date is " << daysDiff(d2, d1);
    }

    return 0;
}