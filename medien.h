#ifndef MEDIEN_H
#define MEDIEN_H
#include<iostream>
using namespace std;


class Medien
{
public:
    Medien(string Titel,string Autor);
    virtual~Medien ()=default;
    virtual void display()=0;

    int getId() const;

    string getTitel() const;

    string getAutor() const;
    bool getAusgeliehen() const;

    void setAusgeliehen(bool newAusgeliehen);

    bool getAktiv() const;
    void setAktiv(bool newAktiv);


private:
    int Id;
    string Titel;
    string Autor;
    static int counter;
    bool Ausgeliehen=false;
    bool aktiv=true;

};

#endif // MEDIEN_H
