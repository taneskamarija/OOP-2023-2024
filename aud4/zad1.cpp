x#include <iostream>
#include <cstring>

using namespace std;

class Library;

class LibraryMember;

class Book {
private:
    char title[50], author[50];
    bool isAvailable;

    friend Library;

    friend void checkOutBook(LibraryMember lm, Library &l, int idx);

    void print() {
        cout << title << " " << author << " is  " << (isAvailable ? "" : "not ") << "available" << endl;
    }

public:
    Book() {}

    Book(char *title, char *author, bool avail) {
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->isAvailable = avail;
    }

    Book(Book &b) {
        strcpy(this->title, b.title);
        strcpy(this->author, b.author);
        this->isAvailable = b.isAvailable;
    }

    ~Book() {
    }
//
//    void setIsAvailable (bool avail) {
//        this -> isAvailable = avail;
//    }
//    bool getIsAvailable () {
//        return isAvailable;
//    }
};

class Library {
private:
    char name[50];
    Book books[30];
    int numBooks;

    friend void checkOutBook(LibraryMember lm, Library &l, int idx);

public:
    Library() {
        strcpy(name, "Braka Miladinovci");
        numBooks = 0;
    }

    ~Library() {}

    void addBook(const Book &b) {
        if (numBooks < 30) { books[numBooks++] = b; }
        else { cout << "Library is full" << endl; }
    }

//    Book * getBooks () {
//        return books;
//    }

    void print() {
        cout << name << endl << "Books: " << endl;
        for (int i = 0; i < numBooks; i++) {
            books[i].print();
        }
    }

};


class LibraryMember {
private:
    char name[50];
    int id;

    friend void checkOutBook(LibraryMember lm, Library &l, int idx);

public:
    LibraryMember(char *name = "", int id = 0) {
        strcpy(this->name, name);
        this->id = id;
    }

    ~LibraryMember() {}
};

void checkOutBook(LibraryMember lm, Library &l, int idx) {
//    if (l.getBooks()[idx].getIsAvailable()) {
//        l.getBooks()[idx].setIsAvailable(false);
//    } else {
//        cout << "Book is not is not available" << endl;
//    }

    if (l.books[idx].isAvailable) {
        l.books[idx].isAvailable = false;
        cout << lm.name << " with ID " << lm.id << " checks out " << l.books[idx].title;
    } else {
        cout << l.books[idx].title << " is not is not available" << endl;
    }
}


int main() {
    Library library;
    int n;
    cin >> n;

    char title[50], author[50];
    for (int i = 0; i < n; i++) {
        cin >> title >> author;
        library.addBook(Book(title, author, true));
    }

    LibraryMember libraryMember("Alice", 11111);
    library.print();
    int idx;
    cin >> idx;
    checkOutBook(libraryMember, library, idx);
}