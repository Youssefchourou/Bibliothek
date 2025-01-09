#include "cds.h"

CDs::CDs(string Titel,string Autor,float Spieldauer):Medien(Titel,Autor),Spieldauer(Spieldauer)
{

}

void CDs::display()
{
    cout<<"Cd vom: "<<getAutor()<<"Titel: "<<getTitel()<<" Spieldauer: "<<getSpieldauer()<<endl;

}

float CDs::getSpieldauer() const
{
    return Spieldauer;
}

CDs::operator string() const
{
      return "Titel:"+getTitel()+";Autor:"+getAutor()+";SeitenAnzahl: "+to_string(Spieldauer);

}
ostream& operator<<(ostream& os,const CDs& b){
      os<<"Titel: "<<b.getTitel()<<"Autor: "<<b.getAutor()<<"Spieldauer: "<<b.Spieldauer<<endl;
      return os;

}

