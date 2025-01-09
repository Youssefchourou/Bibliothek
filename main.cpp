#include <iostream>
#include"bibliothek.h"
#include"random.h"
#include <sys/resource.h>
#include"buecher.h"
#include"hoerbuch.h"
#include"cds.h"
using namespace std;

int main()
{

    Bibliothek*ruf=new Bibliothek();
    Buecher buch("asas","asas",1200);
    CDs cd("AHmed","basna",2.3);
    Hoerbuch hoerbuch("Yasei","bahs",2001,12.3);


    cout<<buch<<endl;
    cout<<hoerbuch<<endl;
    cout<<cd<<endl;
    cout << "Buch: " << static_cast<string>(buch) << endl;
    cout << "CD: " << static_cast<string>(cd) << endl;
    cout << "Hoerbuch: " << static_cast<string>(hoerbuch) << endl;


    ruf->benutzerDialog();

    delete ruf;
//    struct rusage usage;
//    getrusage(RUSAGE_SELF, &usage);
//    std::cout << "CPU-Zeit im User-Mode: " << usage.ru_utime.tv_sec << " Sekunden" << std::endl;
//    std::cout << "CPU-Zeit im Kernel-Mode: " << usage.ru_stime.tv_sec << " Sekunden" << std::endl;
//    return 0;


    return 0;
}

