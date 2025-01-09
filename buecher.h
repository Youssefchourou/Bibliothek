#ifndef BUECHER_H
#define BUECHER_H
#include<medien.h>
#include<string>

class Buecher:public virtual Medien
{
public:
    Buecher(string Titel, string Autor, int Seitenzahl);
    void display()override;
    int getSeitenzahl() const;
    friend ostream& operator<<(ostream& os,const Buecher& b);
    operator string()const;

private:
    int Seitenzahl;

};

#endif // BUECHER_H
