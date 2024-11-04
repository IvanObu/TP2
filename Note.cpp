#include "Note.h"


NOTE::NOTE() : surname(""), name(""), phoneNumber(""), birthDate{{0, 0, 0}} {}


NOTE::NOTE(string surname, string name, string phoneNumber, array<int, 3> birthDate)
    : surname(surname), name(name), phoneNumber(phoneNumber), birthDate(birthDate) {}


string NOTE::getSurname() const { return surname; }
string NOTE::getName() const { return name; }
string NOTE::getPhoneNumber() const { return phoneNumber; }
array<int, 3> NOTE::getBirthDate() const { return birthDate; }


ostream& operator<<(ostream& os, const NOTE& note) {
    os << "Surname: " << note.surname << ", Name: " << note.name
       << ", Phone Number: " << note.phoneNumber
       << ", Birth Date: " << note.birthDate[0] << "/"
       << note.birthDate[1] << "/" << note.birthDate[2];
    return os;
}

istream& operator>>(istream& is, NOTE& note) {
    cout << "Enter surname: ";
    is >> note.surname;
    cout << "Enter name: ";
    is >> note.name;
    cout << "Enter phone number: ";
    is >> note.phoneNumber;
    cout << "Enter birth date (day month year): ";
    is >> note.birthDate[0] >> note.birthDate[1] >> note.birthDate[2];
    return is;
}