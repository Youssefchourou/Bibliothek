#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H
#include"buch.h"
#include"medien.h"
#include"random.h"
#include<memory>
#include"kunde.h"
class Bibliothek
{



public:
    Bibliothek();
    ~Bibliothek();
    void benutzerDialog();
    void Buchanlegen();
    void bestandanzeigen();
    void buch_Autor();
    void Buchempfehlen();
    void BuchempfehlenOA();
    void Buchlöschen();
    void Bibliothekspeichern();
    void Bibliothekladen();
    void Buchausleihen();
    void Buchzurückgeben();
        void medienanzeigen();

    static bool Namevergleich(const unique_ptr<Medien> &a, const unique_ptr<Medien> &b );

private:
    vector<unique_ptr<Medien>>mliste;

    vector<string>Ausleiherbname;
    vector<string>Ausleihercname;
    vector<unique_ptr<Kunde>>Liste;

};

#endif // BIBLIOTHEK_H
