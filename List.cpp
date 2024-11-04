#include "List.h"
#include <iostream>

NoteList::NoteList() : notes(nullptr), size(0), capacity(2) {
    notes = new NOTE[capacity]; 
}

NoteList::~NoteList() {
    delete[] notes; 
}

void NoteList::resize() {
    capacity *= 2;
    NOTE* newNotes = new NOTE[capacity];
    for (size_t i = 0; i < size; ++i) {
        newNotes[i] = notes[i];
    }
    delete[] notes;
    notes = newNotes;
}

void NoteList::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (notes[j].getPhonePrefix() > notes[j + 1].getPhonePrefix()) {
                NOTE temp = notes[j];
                notes[j] = notes[j + 1];
                notes[j + 1] = temp;
            }
        }
    }
}

void NoteList::addNote(const NOTE& note) {
    if (size == capacity) {
        resize(); 
    }
    notes[size++] = note;
    sort();
}

void NoteList::findAndPrintBySurname(const string& surname) const {
    bool found = false;
    for (size_t i = 0; i < size; ++i) {
        if (notes[i].getSurname() == surname) {
            cout << notes[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No entry found with surname: " << surname << endl;
    }
}

void NoteList::printAll() const {
    for (size_t i = 0; i < size; ++i) {
        cout << notes[i] << endl;
    }
}