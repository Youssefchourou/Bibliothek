#include "medien.h"
#include<sstream>
#include<fstream>
int Medien::counter=1;
Medien::Medien(string Titel, string Autor):Titel(Titel),Autor(Autor)
{
    Id=counter;
    counter++;

}

int Medien::getId() const
{
    return Id;
}

string Medien::getTitel() const
{
    return Titel;
}

string Medien::getAutor() const
{
    return Autor;
}
bool Medien::getAusgeliehen() const
{
    return Ausgeliehen;
}

void Medien::setAusgeliehen(bool newAusgeliehen)
{
    Ausgeliehen = newAusgeliehen;
}

bool Medien::getAktiv() const
{
    return aktiv;
}


void Medien::setAktiv(bool newAktiv)
{
    aktiv = newAktiv;
}

