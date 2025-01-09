#include "buecher.h"

Buecher::Buecher( string Titel, string Autor, int Seitenzahl):Medien(Titel,Autor),Seitenzahl(Seitenzahl)
{

}

void Buecher::display()
{
    cout<<"Buch vom: "<<getAutor()<<"Titel: "<<getTitel()<<"Seiten: "<<getSeitenzahl();

}

int Buecher::getSeitenzahl() const
{
    return Seitenzahl;
}

Buecher::operator string() const
{
    return "Titel:"+getTitel()+";Autor:"+getAutor()+";SeitenAnzahl: "+to_string(Seitenzahl);

}
ostream& operator<<(ostream& os,const Buecher& b){
    os<<"Titel: "<<b.getTitel()<<"Autor: "<<b.getAutor()<<"Seitenanzahl: "<<b.Seitenzahl<<endl;
    return os;

}


