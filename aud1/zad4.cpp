#include <iostream>

using namespace std;

void normalize(char *name, bool allUpperCase = false);

struct Student {
    char firstName[50];
    char lastName[50];
    int id;
    int totalPoints;

    void read() {
        cin >> firstName;
        cin >> lastName;
        cin >> id;

        int p1, p2, p3, p4;
        cin >> p1 >> p2 >> p3 >> p4;

        normalize(firstName);
        normalize(lastName);
        totalPoints = p1 + p2 + p3 + p4;
    }

    void print() {
        cout << lastName << " " << firstName << " " << id << " " << totalPoints << endl;
    }

};


void sort(Student s[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (s[j].totalPoints < s[j + 1].totalPoints) {
                Student tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    if (n > 100) {
        return -1;
    }

    Student s[n];
    for (int i = 0; i < n; i++) {
        s[i].read();
    }

    sort(s, n);

    for (int i = 0; i < n; i++) {
        s[i].print();
    }
}

void normalize(char *name, bool allUpperCase) {
    if (allUpperCase) {
        while (*name) {
            *name = toupper(*name);
            name++;
        }
    } else {
        *name = toupper(*name);
        name++;
        while (*name) {
            *name = tolower(*name);
            name++;
        }
    }
}