#include "hoerbuch.h"

Hoerbuch::Hoerbuch(string Titel, string Autor, float Spieldauer, int Seitenanzahl)
    : Medien(Titel, Autor), CDs(Titel, Autor, Spieldauer), Buecher(Titel, Autor, Seitenanzahl),booklet(Spieldauer,Seitenanzahl)
{
}

void Hoerbuch::display()
{
    cout<<"Hörbuch klasse "<<endl;
    cout<<"Übergenommenes Buch"<<getTitel()<<"Name:"<<getAutor()<<"Seitenanzahl:"<<getSeitenzahl()<<endl;


}

Hoerbuch::operator string() const
{

    return "Titel:"+getTitel()+";Autor:"+getAutor()+";SeitenAnzahl: "+to_string(getSeitenzahl())+"Spieldauer"+to_string(getSpieldauer());
}
ostream& operator<<(ostream& os,const Hoerbuch& b){
    os<<"Titel: "<<b.getTitel()<<"Autor: "<<b.getAutor()<<"Seitenanzahl: "<<b.getSeitenzahl()<<"Spieldauer:"<<b.getSpieldauer()<<endl;
    return os;

}


