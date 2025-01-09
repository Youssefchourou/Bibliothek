#ifndef HOERBUCH_H
#define HOERBUCH_H
#include<iostream>
#include"cds.h"
#include"buecher.h"
#include"medien.h"
using namespace std;

class Hoerbuch:public CDs,public Buecher
{
public:
    Hoerbuch(string Titel,string Autor,float Spieldauer,int Seitenanzahl);
    void display()override;
    friend ostream& operator<<(ostream& os,const Hoerbuch& b);

    operator string()const;


private:
    struct Booklet{
        float dauer;
        int seiten;
        Booklet(float spieldauer,int seitenanzahl):dauer(spieldauer),seiten(seitenanzahl){}

        void Display(){
            cout<<"Spieldauer: "<<dauer<<"Seiten: "<<seiten<<endl;
        }
    };
    Booklet booklet;
};

#endif // HOERBUCH_H
