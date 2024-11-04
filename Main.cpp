#include "Note.h"
#include "List.h"
#include <iostream>

using namespace std;

int main() {
    NoteList noteList;
    int choice;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Note\n";
        cout << "2. Find Note by Surname\n";
        cout << "3. Print All Notes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                NOTE note;
                cin >> note;
                noteList.addNote(note);
                break;
            }
            case 2: {
                string surname;
                cout << "Enter surname to search: ";
                cin >> surname;
                noteList.findAndPrintBySurname(surname);
                break;
            }
            case 3:
                noteList.printAll();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}