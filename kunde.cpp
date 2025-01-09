#include "kunde.h"

int Kunde::counter=1;
Kunde::Kunde(string Nachname):Nachname(Nachname)
{
    Id=counter;
    counter++;

}

int Kunde::getId() const
{
    return Id;
}

string Kunde::getNachname() const
{
    return Nachname;
}
