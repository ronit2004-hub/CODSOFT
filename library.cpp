#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string ISBN;
    bool isAvailable = true;
    time_t checkoutDate;
};

vector<Book> library;

void addBook() {
    Book book;
    cout << "Enter book ID: ";
    cin >> book.id;
    cin.ignore();
    cout << "Enter title: ";
    getline(cin, book.title);
    cout << "Enter author: ";
    getline(cin, book.author);
    cout << "Enter ISBN: ";
    getline(cin, book.ISBN);
    book.isAvailable = true;
    library.push_back(book);
    cout << "Book added successfully.\n";
}

void searchBook() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    for (const auto& book : library) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            cout << "Found Book: " << book.title << " by " << book.author;
            cout << (book.isAvailable ? " [Available]\n" : " [Checked Out]\n");
        }
    }
}

void checkoutBook() {
    int id;
    cout << "Enter book ID to checkout: ";
    cin >> id;

    for (auto& book : library) {
        if (book.id == id && book.isAvailable) {
            book.isAvailable = false;
            book.checkoutDate = time(0);
            cout << "Book checked out successfully.\n";
            return;
        }
    }
    cout << "Book not available or not found.\n";
}

void returnBook() {
    int id;
    cout << "Enter book ID to return: ";
    cin >> id;

    for (auto& book : library) {
        if (book.id == id && !book.isAvailable) {
            book.isAvailable = true;
            time_t now = time(0);
            int days = (now - book.checkoutDate) / (60 * 60 * 24);
            if (days > 14) {
                int fine = (days - 14) * 2;
                cout << "Book returned. Fine for late return: Rs. " << fine << "\n";
            } else {
                cout << "Book returned on time.\n";
            }
            return;
        }
    }
    cout << "Invalid return or book already available.\n";
}

void menu() {
    int choice;
    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Search Book\n3. Checkout Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: checkoutBook(); break;
            case 4: returnBook(); break;
            case 5: cout << "Exiting..."; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}