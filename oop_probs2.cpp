#include <iostream>
#include <iomanip> // librarie necesara pentru setw (setarea latimii minime la 2 caractere) / setfill ('char') (umplerea spatiilor libere cu 'char' daca valoarea are o singura cifra).+
#include <ctime>

using namespace std;


// Sa se implementeze o clasa constructor default care sa afiseze data curenta (ziua si ora) in momentul instantierii si sa se calculeze cate ore mai sunt pana la finalul zilei.

// Fara  ajutorul librariei <ctime>.
/*
class perioadaTimp{

    public: 
    int ora, minut, secunda; // definirea obiectelor din clasa
    string data;
    string luna;

    perioadaTimp(int h, int m, int s, string zi, string l){ // definirea functiei constructor.

        ora = h;
        minut = m;
        secunda = s;
        data = zi;
        luna = l;


    cout << "Ora introdusa: " << ora << ":" << minut << ":" << secunda << endl;
    cout << "Data curenta: " << data << " " << luna << endl;
    oreRamase(); // functie care va calcula orele pana la finalul zilei.
    }
    

    void oreRamase(){
        int oreRamase = 23 - ora;
        cout << "Ore ramase pana la finalul zilei: " << oreRamase << ":" << minut << ":" << secunda << endl;
    }
};
*/

// Cu ajutorul librariei <ctime>.

class perioadaTimp{

    public:
    perioadaTimp(){ // constructor default - nu are nevoie de definirea parametrilor
        time_t timp_curent = time(0); /* "time_t" - functie din libraria <ctime> care defineste un moment pornind de la (data 01 ianuarie, anul 1900, iar ora 00:00:00 UTC). 
                                        "time(0)" - defineste momentul curent. */
        tm *localTime = localtime(&timp_curent); /* "tm" - tip de data, definita in <ctime>, care afiseaza timpul intr-un format detaliat (AN/LUNA/ZI/ORA/MIN/SEC).
                                            "localtime" - converteste timpul in structura tm, oferind informatii despre data si ora.
                                            tipul de data "tm" - poate primi parametru doar un pointer.*/
        
        cout << "Data si ora curenta: " << 1900 + localTime->tm_year << "/" << 1 + localTime->tm_mon << "/" << localTime->tm_mday << " " << setw(2) << setfill('0') <<  localTime->tm_hour << ":" << setw(2) << setfill('0') << localTime->tm_min << ":" << setw(2) << setfill('0') << localTime->tm_sec << endl;
                                        /* trebuie adaugat 1900 deoarece localTime->tm_year returneaza diferenta dintre anul curent si anul 1900.*/

        int oreRamase = 23 - localTime->tm_hour;
        cout << "Ore ramase pana la finalul zilei: " << setw(2) << setfill('0') << oreRamase <<":"<< setw(2) << setfill('0') << localTime->tm_min << ":" << setw(2) << setfill('0') << localTime->tm_sec << endl;
    }
};

int main(){

    /*
    int h, m, s;
    string zi, l;
    cout << "Introdu ora curenta(HH MM SS), apoi ziua curenta(DD MM): ";
    cin>> h >> m >> s;
    cin >> zi >> l;

    perioadaTimp cnt(h, m, s, zi, l);
    */
    perioadaTimp timp;

    return 0;

}