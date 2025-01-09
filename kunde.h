#ifndef KUNDE_H
#define KUNDE_H
#include<iostream>
using namespace std;

class Kunde
{
public:
    Kunde(string Nachname);
    int getId() const;

    string getNachname() const;

private:
    string Nachname;
    int Id;
    static int counter;
};

#endif // KUNDE_H
