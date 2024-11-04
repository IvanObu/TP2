#ifndef LIST_H
#define LIST_H

#include "Note.h"

class NoteList {
private:
    NOTE* notes;
    size_t size; 
    size_t capacity;
    void resize();
    void sort();

public:
    NoteList();
    ~NoteList();

    void addNote(const NOTE& note); 
    void findAndPrintBySurname(const string& surname) const;
    void printAll() const;
};

#endif 