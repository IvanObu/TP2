#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <string>
#include <array>

using namespace std;

class NOTE {
private:
    string surname;
    string name;
    string phoneNumber;
    array<int, 3> birthDate; // {day, month, year}

public:

    NOTE();
    NOTE(string surname, string name, string phoneNumber, array<int, 3> birthDate);

    string getSurname() const;
    string getName() const;
    string getPhoneNumber() const;
    array<int, 3> getBirthDate() const;

    string getPhonePrefix() const { return phoneNumber.substr(0, 3); }

    friend ostream& operator<<(ostream& os, const NOTE& note);
    friend istream& operator>>(istream& is, NOTE& note);
};

#endif 