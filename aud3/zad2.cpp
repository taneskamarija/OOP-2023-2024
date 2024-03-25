#include <iostream>
#include <cstring>

using namespace std;

class Team {
private:
    char name[100], city[100];
    int year;

public:
    Team(const char *name = "", const char *city = "", const int year = 0) {
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->city, city);
    };

    Team(const Team &t) {
        strcpy(this->name, t.name);
        this->year = t.year;
        strcpy(this->city, t.city);
    }

    ~Team() {}

    char *getName() {
        return name;
    }
};

class Game {
private:
    Team host, guest;
    int hostGoals, guestGoals;

public:
    Game(const Team host = Team(), const Team guest = Team(),
         const int hostGoals = 0, const int guestGoals = 0) {
        this->host = host;
        this->guest = guest;
        this->hostGoals = hostGoals;
        this->guestGoals = guestGoals;
    }

    ~Game() {}

    Team getHost() {
        return host;
    }

    Team getGuest() {
        return guest;
    }

    int getHostGoals() {
        return hostGoals;
    }

    int getGuestGoals() {
        return guestGoals;
    }
};


bool rematch(Game g1, Game g2) {
    return (strcmp(g1.getHost().getName(), g2.getGuest().getName()) == 0
            && strcmp(g1.getGuest().getName(), g2.getHost().getName()) == 0);
};

Team duel(Game g1, Game g2) {
    if (rematch(g1, g2)) {
        int goalsHost = g1.getHostGoals() + g2.getGuestGoals();
        int goalsGuest = g1.getGuestGoals() + g2.getHostGoals();

        if (goalsHost > goalsGuest) {
            return g1.getHost();
        } else if (goalsHost < goalsGuest) {
            return g1.getGuest();
        } else if (g1.getHostGoals() > g2.getHostGoals()) {
            return g1.getHost();
        } else if (g1.getHostGoals() < g2.getHostGoals()) {
            return g2.getHost();
        }
    } else {
        cout << "Ne se sovpagaat" << endl;
    }
    return Team();
}


Game readGame() {
    char name[100], city[100];
    int year, hostGoals, guestGoals;

    cout << "Vnesete informacii za domakinskiot tim:" << endl;
    cin >> name >> city >> year;
    Team host(name, city, year);
    cout << "Vnesete informacii za gostinskiot tim:" << endl;
    cin >> name >> city >> year;
    Team guest(name, city, year);
    cout << "Vnesete informacii za golovite:" << endl;
    cin >> hostGoals >> guestGoals;

    return Game(host, guest, hostGoals, guestGoals);
}

int main() {
    cout << "Vnesete informacii za prviot natprevar" << endl;
    Game g1 = readGame();
    cout << "Vnesete informacii za vtoriot natprevar" << endl;
    Game g2 = readGame();

    Team winner = duel(g1, g2);

    if (strcmp(winner.getName(), "") == 0) {
        cout << "Nema pobednik";
    } else {
        cout << "Pobednik e timot " << winner.getName();
    }

    return 0;
}
