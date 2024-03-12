#include <iostream>

using namespace std;

struct City {
    char name[100];
    int population;

    void read() {
        cin >> name >> population;
    }
};

struct President {
    char firstName[100], lastName[100], party[100];

    void read() {
        cin >> firstName >> lastName >> party;
    }
};

struct Country {
    char name[100];
    City capital;
    President president;

    void read() {
        cin >> name;
        capital.read();
        president.read();
    }
};

Country maxCapitalPopulation(Country *c, int n) {
    Country max = c[0];
    for (int i = 0; i < n; i++) {
        if (max.capital.population < c[i].capital.population) {
            max = c[i];
        }
    }
    return max;
}


int main() {
    int n;
    cin >> n;
    Country c[n];

    for (int i = 0; i < n; i++) {
        c[i].read();
    }

    Country max = maxCapitalPopulation(c, n);
    cout << max.president.firstName << " " << max.president.lastName << endl;

    return 0;
}