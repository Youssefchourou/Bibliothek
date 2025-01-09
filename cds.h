#ifndef CDS_H
#define CDS_H
#include<medien.h>



class CDs:public virtual Medien
{
public:
    CDs(string Titel, string Autor, float Spieldauer);
    void display()override;
    float getSpieldauer() const;
    friend ostream& operator<<(ostream& os,const CDs& b);

    operator string()const;


private:
    float Spieldauer;
};

#endif // CDS_H
