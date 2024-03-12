#include <iostream>
#include <cstring>

using namespace std;
enum Len {
    ADDRLEN = 100,
    SUBLEN = 200,
    BODYLEN = 1000
};

class Email {
private:
    char to[Len::ADDRLEN];
    char from[Len::ADDRLEN];
    char subject[Len::SUBLEN];
    char body[Len::BODYLEN];

public:
    Email(char *t, char *f, char *s, char *b) {
        strcpy(to, t);
        strcpy(from, f);
        strcpy(subject, s);
        strcpy(body, b);
    }

    ~Email() {}

    void print() {
        cout << "To: " << to << endl;
        cout << "From: " << from << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }
};

bool validAddress(char *n);

int main() {
    char to[Len::ADDRLEN], from[Len::ADDRLEN], subject[Len::SUBLEN], body[Len::BODYLEN];
    cin >> to;
    if (validAddress(to)) {
        cin >> from;
        if (validAddress(from)) {
            cin >> subject;
            cin >> body;
            Email e(to, from, subject, body);
            e.print();
        } else {
            cout << "Invalid 'from' email address";
            return -1;
        }
    } else {
        cout << "Invalid 'to' email address";
        return -1;
    }

    return 0;
}

bool validAddress(char *n) {
    int c = 0;

    while (*n) {
        if (*n == '@') {
            c++;
        }
        *n++;
    }

    return (c == 1);
};