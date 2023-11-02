#include <iostream>
#include <string>

int main() {
    using namespace std;
    const int finePerDay = 1;
    string books[100];
    int dueDates[100];
    int bookCount = 0;

    while (true) {
        int choice;
        cout << "Library System Menu:" << endl;
        cout << "1. Issue a book" << endl;
        cout << "2. Return a book" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string title;
            cout << "Enter the title of the book: ";
            getline(cin, title);

            if (bookCount < 100) {
                books[bookCount] = title;
                dueDates[bookCount] = bookCount + 1;
                cout << "Book '" << title << "' issued successfully." << endl;
                cout << "Due date: " << dueDates[bookCount] << " days from today." << endl;
                bookCount++;
            }
            else {
                cout << "The library is full. Cannot issue more books." << endl;
            }
        }
        else if (choice == 2) {
            cin.ignore();
            string title;
            cout << "Enter the title of the book to return: ";
            getline(cin, title);

            bool bookFound = false;
            int returnDate = 0;
            for (int i = 0; i < bookCount; i++) {
                if (books[i] == title) {
                    bookFound = true;
                    cout << "Enter the return date (days from due date): ";
                    cin >> returnDate;

                    if (returnDate <= dueDates[i]) {
                        cout << "Book '" << title << "' returned on time. No fines incurred." << endl;
                    }
                    else {
                        int daysLate = returnDate - dueDates[i];
                        int fine = daysLate * finePerDay;
                        cout << "Fine for returning " << daysLate << " days late: $" << fine << endl;
                    }
                    for (int j = i; j < bookCount - 1; j++) {
                        books[j] = books[j + 1];
                        dueDates[j] = dueDates[j + 1];
                    }

                    bookCount--;
                    break;
                }
            }

            if (!bookFound) {
                cout << "The book is not found or has not been issued." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Exiting the Library System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}