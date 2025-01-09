#include "bibliothek.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<random>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<ctime>
#include<memory>
#include"buch.h"
#include"medien.h"
#include"buecher.h"
#include"cds.h"
#include"hoerbuch.h"



using namespace std;
Bibliothek::Bibliothek()
{

}

Bibliothek::~Bibliothek()
{


}
bool Bibliothek::Namevergleich(const unique_ptr<Medien>& a, const unique_ptr<Medien>&b)
{
    return a->getAutor()< b->getAutor();

}
void Bibliothek::benutzerDialog()
{
    while(true){

        cout<<"Wählen Sie bitte ein Nummer aus"<<endl;
        cout<<"1: Medium anlegen"<<endl;
        cout<<"2: Medium löschen"<<endl;
        cout<<"3: Bestand anzeigen"<<endl;
        cout<<"4: Medium nach Autor"<<endl;
        cout<<"5: Medium empfehlen "<<endl;
        cout<<"6: Bibliothek speichern"<<endl;
        cout<<"7: Bibliothek laden "<<endl;
        cout<<"8: Medium ausleihen"<<endl;
        cout<<"9: Medium zurückgeben"<<endl;
        cout<<"0: Programm beenden"<<endl;
        char choice;
        cin>>choice;
        switch(choice){


        case('1'):{


            Buchanlegen();

            break;
        }
        case('2'):{
            cout<<"Buch löschen"<<endl;
            Buchlöschen();



            break;

        }
        case('3'):{
            cout<<"bestand Anzeigen"<<endl;
            bestandanzeigen();

            break;
        }
        case('4'):{
            buch_Autor();
            break;





        }
        case('5'):{
            char choice;
            cout<<"Wollen Sie einen Autor wählen(j/n) "<<endl;
            cin>>choice;
            switch(choice){
                case('j'):{
                Buchempfehlen();
                break;
                }
                case('n'):{
                BuchempfehlenOA();
                break;

                }
            }
                break;

        }
        case('6'):{
            Bibliothekspeichern();

            break;
        }
        case('7'):{
            Bibliothekladen();

            break;

        }
        case('8'):{
            Buchausleihen();
            break;
        }
        case('9'): {
            Buchzurückgeben();
            break;
        }

        case('0'):{
            cout<<"Sie wollen das Programm  verlassen"<<endl;
            return;
        }


        }
    }



}

void Bibliothek::Buchanlegen()
{
    cout<<"Medium anlegen"<<endl;
    cout<<"1: Buch 2:Cd 3:Hörbuch  "<<endl;
    char choice;
    cin>>choice;
    switch(choice){
        case('1'):{
            cout<<"Sie haben ein Buch ausgewählt"<<endl;
            cout<<"Geben Sie bitte den Titel ein"<<endl;
            string Titel,nameautor;
            cin>>Titel;
            cout<<"Geben Sie bitte die Name des Autors"<<endl;
            cin>>nameautor;
            cout<<"Geben Sie bitte die Zeilen"<<endl;
            int Zeilen;
            cin>>Zeilen;
            //Medien*buecher=new Buecher(Titel,nameautor,Zeilen);
            mliste.push_back(make_unique<Buecher>(Titel,nameautor,Zeilen));

            cout<<"Buch wurde angelegt :"<<mliste.back()->getId()<<endl;
            break;

        }
        case('2'):{
            cout<<"Sie haben ein Cd ausgewählt"<<endl;
            cout<<"Geben Sie bitte den Titel ein"<<endl;
            string Titel,Autor;
            float Spieldauer;
            cin>>Titel;
            cout<<"Geben Sie bitte die Name des Autors "<<endl;
            cin>>Autor;
            cout<<"Geben Sie bitte das Spieldauer"<<endl;
            cin>>Spieldauer;

            mliste.push_back(make_unique<CDs>(Titel,Autor,Spieldauer));
            cout<<"Cd wurde angelgt :"<<mliste.back()->getId()<<endl;

            break;
        }
        case('3'):{
            string Titel,Autor;
            cout<<"geben Sie den Titel ein"<<endl;
            cin>>Titel;
            cout<<"Geben Sie die Name des Autors "<<endl;
            cin>>Autor;
            float Spieldauer;
            int seiten;
            cout<<"Geben Sie bitte das Spieldauer"<<endl;
            cin>>Spieldauer;
            cout<<"Geben Sie bitte die Seitenanzahl"<<endl;
            cin>>seiten;
            mliste.push_back(make_unique<Hoerbuch>(Titel,Autor,Spieldauer,seiten));
            cout<<"Hörbuch wurde angelgt :"<<mliste.back()->getId()<<endl;

            break;
        }
    }

}

void Bibliothek::bestandanzeigen()
{
    for(const auto&medie:mliste){
            if(auto*hoerbuch=dynamic_cast<Hoerbuch*>(medie.get())){
            if(hoerbuch->getAktiv()){
                cout<<setw(10)<<right<<"Nummer: "<<hoerbuch->getId()<<"|";
                cout<<setw(20)<<right<<"Name: "<<hoerbuch->getAutor()<<"|";
                cout<<setw(20)<<right<<"Titel: "<<hoerbuch->getTitel()<<"|";

                if(hoerbuch->getAusgeliehen()==false){
                    cout<<setw(20)<<right<<"Hoerbuchzustand: verüfgbar "<<endl;
                }
                else{
                    cout<<setw(20)<<right<<"Hoerbuchzustand: asugeliehen "<<endl;


                }



            }
            }
            if(auto* buch=dynamic_cast<Buecher*>(medie.get())){//sternchen muss immer stehen
            if(buch->getAktiv()){
                cout<<setw(10)<<right<<"Nummer: "<<buch->getId()<<"|";
                cout<<setw(20)<<right<<"Name: "<<buch->getAutor()<<"|";
                cout<<setw(20)<<right<<"Titel: "<<buch->getTitel()<<"|";

                if(buch->getAusgeliehen()==false){
                    cout<<setw(20)<<right<<"Buchzustand: verüfgbar "<<endl;
                }
                else{
                    cout<<setw(20)<<right<<"Buchzustand: asugeliehen "<<endl;


                }


            }
            }
            if(auto* cd=dynamic_cast<CDs*>(medie.get())){
            if(cd->getAktiv()){
                cout<<setw(10)<<right<<"Nummer: "<<cd->getId()<<"|";
                cout<<setw(20)<<right<<"Name: "<<cd->getAutor()<<"|";
                cout<<setw(20)<<right<<"Titel: "<<cd->getTitel()<<"|";

                if(cd->getAusgeliehen()==false){
                    cout<<setw(20)<<right<<"CDzustand: verüfgbar "<<endl;
                }
                else{
                    cout<<setw(20)<<right<<"CDzustand: asugeliehen "<<endl;


                }

            }
            }

    }
    }











void Bibliothek::buch_Autor()
{
    cout<<"1:Buch 2:Cd   3:Hörbuch"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case('1'):{
            for(const auto& medie:mliste){
            if(auto* buch=dynamic_cast<Buecher*>(medie.get())){
                sort(mliste.begin(),mliste.end(),Namevergleich);
                cout<<"Sortiert nach Name"<<endl;

                if(buch->getAktiv()==true){
                    cout<<setw(10)<<right<<"Name des Autors: "<<buch->getAutor()<<"|";
                    cout<<setw(10)<<left<<" Titel des Buchs: "<<buch->getTitel()<<"|";
                    cout<<setw(10)<<left <<" Nummer: "<<buch->getId()<<endl;

                }

            }
            break;
    }
    }





    case('2'):{

    for(const auto& medie:mliste){
            if(auto cd=dynamic_cast<CDs*>(medie.get())){
                sort(mliste.begin(),mliste.end(),Namevergleich);
                cout<<"Sortiert nach Name"<<endl;

                if(cd->getAktiv()==true){
                    cout<<setw(10)<<right<<"Name des Autors: "<<cd->getAutor()<<"|";
                    cout<<setw(10)<<left<<" Titel des Buchs: "<<cd->getTitel()<<"|";
                    cout<<setw(10)<<left <<" Nummer: "<<cd->getId()<<endl;

                }

            }
            break;
    }

    }
    case('3'):{
            for(const auto& medie:mliste){
            if(auto hor=dynamic_cast<Hoerbuch*>(medie.get())){
                sort(mliste.begin(),mliste.end(),Namevergleich);
                cout<<"Sortiert nach Name"<<endl;

                if(hor->getAktiv()==true){
                    cout<<setw(10)<<right<<"Name des Autors: "<<hor->getAutor()<<"|";
                    cout<<setw(10)<<left<<" Titel des Buchs: "<<hor->getTitel()<<"|";
                    cout<<setw(10)<<left <<" Nummer: "<<hor->getId()<<endl;

                }

            }
            break;
    }



    }
    }
}





void Bibliothek::Buchlöschen()
{
    bool found =false;
    int number;
    cout<<"Geben Sie bitte die genaue Nummer des Mediens"<<endl;
    cin>>number;



    for(auto& it:mliste){
            if(it->getId()==number){
            found=true;
            if(it->getAusgeliehen()==false){
                cout<<"Sie können denn ein Medien löschen"<<endl;
                    if(it->getAktiv()==true){
                    cout<<"Das Medien ist Aktiv. Sie Können es gerade löschen"<<endl;
                    it->setAktiv(false);
                    cout<<"Das Medein wurde erfolgreich gelöscht"<<endl;

                }
                else if(it->getAktiv()==false) {
                    cout<<"Das Buch ist schon gelöscht"<<endl;
                }
            }
            else if(it->getAusgeliehen()==true){
                cout<<"Medien ausgeliehen "<<endl;
                break;
            }
            }



    }


    if(!found){
            cout<<"Wir können diese Nummer nicht finden"<<endl;
    }











}

void Bibliothek::Bibliothekspeichern()
{



        ofstream datei("Bibliothek.txt");
        if(!datei){
        cerr<<"Fehler beim öffnen der Datei"<<endl;
            return;
        }
        for(auto& it: mliste){
            datei<<it->getId()<<",";
            datei<<it->getAutor()<<",";
            datei<<it->getTitel()<<endl;

        }
            datei.close();
            cout<<"Datei wurde erfolgreich gespeichert "<<endl;







}

void Bibliothek::Bibliothekladen()
{



    ifstream datei("Bibliothek.txt");
    if(!datei){
            cerr<<"Fehler beim öffnen der Datei"<<endl;
                return;
    }
    mliste.clear();
    string line;
    while(getline(datei,line)){
            stringstream ss(line);
            string nummerstr,name,Titel;
            getline(ss,nummerstr,',');
            getline(ss,name,',');
            getline(ss,Titel);
            int number=stoi(nummerstr);

            mliste.push_back(make_unique<Buecher>(name,Titel,0));



    }
    datei.close();
    cout<<"Bibliothek wurde erfolgreich geladen "<<endl;


}





void Bibliothek::Buchausleihen()
{
    cout<<"1:Buch 2:Cd 3:Hörbuch"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case('1'):{
            cout<<"Sie wollen ein Buch ausleihen"<<endl;
            cout<<"Geben Sie bitte die Name des Buchs"<<endl;
            string name,nachname;
            cin>>name;
            cout<<"Geben Sie bitte ihre Nachname"<<endl;
            cin>>nachname;
            Liste.push_back(make_unique<Kunde>(nachname));
            cout<<"Kunde mit Id:"<<Liste.back()->getId()<<endl;


                for(const auto& medie:mliste){
                    if(medie->getTitel()==name){
                        medie->setAusgeliehen(true);
                        cout<<"Buch wurde ausgeliehen"<<endl;
                    }
                }


        break;

    }
    case('2'):{
        cout<<"Sie wollen ein cd ausleihen"<<endl;
        cout<<"Geben Sie bitte die Name des cds"<<endl;
        string name,nachname;
        cin>>name;
        cout<<"Geben Sie bitte ihre Name"<<endl;
        cin>>nachname;
        Liste.push_back(make_unique<Kunde>(nachname));
        cout<<"Kunde mit Id:"<<Liste.back()->getId()<<endl;
        for(const auto& medie:mliste){

                for(auto& it:mliste){
                    if(it->getTitel()==name){
                        it->setAusgeliehen(true);
                        cout<<"cd wurde ausgeliehen"<<endl;
                    }
                }

        }
        break;

    }
    case('3'):{
        cout<<"Sie wollen ein Hörbuch ausleihen"<<endl;
        cout<<"Geben Sie bitte die Name des Hörbuchs"<<endl;
        string name,nachname;
        cin>>name;
        cout<<"Geben Sie bitte ihre Name"<<endl;
        cin>>nachname;
        for(const auto& medie:mliste){
                Liste.push_back(make_unique<Kunde>(nachname));
                cout<<"Kunde mit Id:"<<Liste.back()->getId()<<endl;
                for(auto& it:mliste){
                    if(it->getTitel()==name){
                        it->setAusgeliehen(true);
                        cout<<"Hörbuch wurde ausgeliehen"<<endl;
                    }
                }
            }

        break;

    }
    }








}

void Bibliothek::Buchzurückgeben()
{
    cout<<"1:Buch 2:Cd 3:Hörbuch"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case('1'):{
        cout<<"Geben Sie bitte Ihre Nachname ein"<<endl;
        string name;
        cin>>name;
        bool found=false;

                for(const auto& namee:Liste){
                if (namee->getNachname()==name){
                        found=true;

                    }
                    if(!found){
                        cout<<"Name nicht gefunden "<<endl;
                    }
                    else if(found){
                        cout<<"Name gefunden Sie können das Buch zurückgeben "<<endl;

                            for(auto& it:mliste){
                            it->setAusgeliehen(false);
                            cout<<"Buch wurde zurückgegeben "<<endl;

                        }


                    }
                }


        break;


        }
        case('2'):{
        cout<<"Geben Sie bitte Ihre Nachname ein"<<endl;
        string name;
        cin>>name;
        bool found=false;
        for(const auto& namee:Liste){
                    if (namee->getNachname()==name){
                        found=true;

                    }
                    if(!found){
                        cout<<"Name nicht gefunden "<<endl;
                    }
                    else if(found){
                        cout<<"Name gefunden Sie können das CD zurückgeben "<<endl;

                            for(auto& it:mliste){
                            it->setAusgeliehen(false);
                            cout<<"Cd wurde zurückgegeben "<<endl;

                        }


                    }






        }
        break;

        }
        case('3'):{
        cout<<"Geben Sie bitte Ihre Nachname ein"<<endl;
        string name;
        cin>>name;
        bool found=false;
        for(const auto& namee:Liste){
        if (namee->getNachname()==name){
                        found=true;

        }
        if(!found){
                        cout<<"Name nicht gefunden "<<endl;
        }
        else if(found){
                        cout<<"Name gefunden Sie können das Buch zurückgeben "<<endl;

                            for(auto& it:mliste){
                            it->setAusgeliehen(false);
                            cout<<"Buch wurde zurückgegeben "<<endl;

                        }


        }

        }
        break;
    }


}
}

void Bibliothek::medienanzeigen()
{

}





void Bibliothek::Buchempfehlen()
{
    cout<<"1:Buch 2:Cd 3:Hörbuch"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case('1'):{
        string name;
        cout<<"Geben Sie bitte die Name des Autors "<<endl;
        cin>>name;
        bool found=false;
        vector<string>Titels;// nicht vergessen
        for(const auto&medie:mliste){
            if(auto buch=dynamic_cast<Buecher*>(medie.get())){

                    if(buch->getAutor()==name && buch->getAusgeliehen()==false){

                        Titels.push_back(buch->getTitel());

                        found=true;

                    }


                if(!Titels.empty()){
                    int randomindex=getRandom(0,Titels.size() -1);
                    cout<<"Buch empfohlen des Autors :    "<<name <<"   Titel:    "<<Titels[randomindex]<<endl;


                }

                if(!found){
                    cout<<"Es gibt keinen Autor mit dieser Name "<<name<<endl;

                }
            }
        }
        break;


    }
    case('2'):{
        string name;
        cout<<"Geben Sie bitte die Name des Autors "<<endl;
        cin>>name;
        bool found=false;
        vector<string>Titels1;// nicht vergessen


        for(const auto&medie:mliste){
            if(auto cd=dynamic_cast<CDs*>(medie.get())){

                    if(cd->getAutor()==name && cd->getAusgeliehen()==false){

                        Titels1.push_back(cd->getTitel());

                        found=true;

                    }


                if(!Titels1.empty()){
                    int randomindex=getRandom(0,Titels1.size() -1);
                    cout<<"Cd empfohlen des Autors :    "<<name <<"   Titel:    "<<Titels1[randomindex]<<endl;


                }

                if(!found){
                    cout<<"Es gibt keinen Autor mit dieser Name "<<name<<endl;

                }
                break;
            }
        break;


    }
    }
    case('3'):{
    string name;
    cout<<"Geben Sie bitte die Name des Autors "<<endl;
    cin>>name;
    bool found=false;
    vector<string>Titels1;// nicht vergessen


    for(const auto&medie:mliste){
        if(auto hor=dynamic_cast<Hoerbuch*>(medie.get())){

                if(hor->getAutor()==name && hor->getAusgeliehen()==false){

                    Titels1.push_back(hor->getTitel());

                    found=true;

                }


                if(!Titels1.empty()){
                    int randomindex=getRandom(0,Titels1.size() -1);
                    cout<<"Hörbuch empfohlen des Autors :    "<<name <<"   Titel:    "<<Titels1[randomindex]<<endl;


                }

                if(!found){
                    cout<<"Es gibt keinen Autor mit dieser Name "<<name<<endl;

                }
                break;
        }
        break;


    }
    }



}
}

void Bibliothek::BuchempfehlenOA()
{
    cout<<"1: Buch 2:Cd 3:Hörbuch"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case('1'):{
        vector<string>Titel;
        for(const auto&medie:mliste){
        if(dynamic_cast<Buecher*>(medie.get())){


                        if(medie->getAusgeliehen()==false)
                            Titel.push_back(medie->getTitel());


                    }
                break;

        }
        int zufallindex=getRandom(0,Titel.size()-1);
        cout<<"Buch empfohlen:   "<<Titel[zufallindex]<<endl;
        break;

    }
    case('2'):{
        vector<string>Titel1;
        for(const auto&medie:mliste){

                if(dynamic_cast<CDs*>(medie.get())){

                        if(medie->getAusgeliehen()==false)
                            Titel1.push_back(medie->getTitel());


                    }

        }
        int zufallindex=getRandom(0,Titel1.size()-1);
        cout<<"Cd empfohlen:   "<<Titel1[zufallindex];
        break;

    }
    case('3'):{
        vector<string>Titel1;
        for(const auto&medie:mliste){

                    if(dynamic_cast<Hoerbuch*>(medie.get())){

                        if(medie->getAusgeliehen()==false)
                            Titel1.push_back(medie->getTitel());


                    }

        }
        int zufallindex=getRandom(0,Titel1.size()-1);
        cout<<"Hörbuch empfohlen:   "<<Titel1[zufallindex];
        break;
    }



}
}

