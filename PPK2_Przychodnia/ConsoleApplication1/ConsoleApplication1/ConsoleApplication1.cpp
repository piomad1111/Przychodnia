// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

class Osoba {

    public:
        char *imie,
         *nazwisko;
        Osoba() {
            imie = new char[1];
            imie[0] = '\0';

            nazwisko = new char[1];
            nazwisko[0] = '\0';
        }
        Osoba(const char* _Imie, const char* _Nazwisko) {
            imie = new char[strlen(_Imie) + 1];
            strcpy_s(imie, strlen(_Imie) + 1, _Imie);

            nazwisko = new char[strlen(_Nazwisko) + 1];
            strcpy_s(nazwisko, strlen(_Nazwisko) + 1, _Nazwisko);

        }
        Osoba(const Osoba &inna) {
            imie = new char[strlen(inna.imie) + 1]; //kopiuje dane nie wskaznik
            strcpy_s(imie, strlen(inna.imie) + 1, inna.imie);

            nazwisko = new char[strlen(inna.nazwisko) + 1];
            strcpy_s(nazwisko, strlen(inna.nazwisko) + 1, inna.nazwisko);

        }
        Osoba& operator = (const Osoba& inna){
            if (this != &inna) {
                delete[] imie;
                delete[] nazwisko;

                imie = new char[strlen(inna.imie) + 1]; 
                strcpy_s(imie, strlen(inna.imie) + 1, inna.imie);

                nazwisko = new char[strlen(inna.nazwisko) + 1];
                strcpy_s(nazwisko, strlen(inna.nazwisko) + 1, inna.nazwisko);

            }
            return *this;

        }
        char* getImie() {
            return imie;
        }
        char* getNazwisko() {
            return nazwisko;
        }
        ~Osoba() { //destruktor
            delete[] imie;
            delete[] nazwisko; //zwolnienie pamięci
        }
};
class Pacjent :public Osoba {
    int idPacjenta;

    public:
        Pacjent(const char* _Imie, const char* _Nazwisko, int _idPacjenta):Osoba(_Imie, _Nazwisko) {
            idPacjenta = _idPacjenta;
        }
        int getID() {
            return idPacjenta;
        }
};
class Lekarz : public Osoba {
public:
    char *pesel;
    char* specjalizacja;
    char dniPrzyjec[7][15];
    char godzinyPrzyjec[7][12];
    
    public:
        Lekarz() :Osoba() {
            pesel = new char[1];
            pesel[0] = '\0';
            specjalizacja = new char[1];
            specjalizacja[0] = '\0';
            for (int i = 0; i < 7;i++) {
                dniPrzyjec[i][0] = '\0';
                godzinyPrzyjec[i][0] = '\0';
            }

        }
        Lekarz(const char* _Pesel, const char* _Imie, const char* _Nazwisko,const char* _Specjalizacja, char _dniPrzyjec[7][15], char _godzinyPrzyjec[7][12]) :Osoba(_Imie, _Nazwisko) {
            pesel = new char[strlen(_Pesel) + 1];
            strcpy_s(pesel, strlen(_Pesel) + 1, _Pesel);
            specjalizacja = new char[strlen(_Specjalizacja) + 1];
            strcpy_s(specjalizacja, strlen(_Specjalizacja) + 1, _Specjalizacja);
           for (int i = 0; i < 7; i++) {
                dniPrzyjec[i][0] = '\0';
                godzinyPrzyjec[i][0] = '\0';
            }
            for (int i = 0; i < 7; i++) {
                strcpy_s(dniPrzyjec[i],strlen(_dniPrzyjec[i]) + 1, _dniPrzyjec[i]);
                strcpy_s(godzinyPrzyjec[i],strlen(_godzinyPrzyjec[i])+1, _godzinyPrzyjec[i]);
            }
        }

        Lekarz(const Lekarz& inny):Osoba(inny){
            pesel = new char[strlen(inny.pesel) + 1];
            strcpy_s(pesel, strlen(inny.pesel) + 1, inny.pesel);
            
            specjalizacja = new char[strlen(inny.specjalizacja) + 1];
            strcpy_s(specjalizacja, strlen(inny.specjalizacja) + 1, inny.specjalizacja);
            for (int i = 0; i < 7; i++) {
                strcpy_s(dniPrzyjec[i], strlen(inny.dniPrzyjec[i]) + 1, inny.dniPrzyjec[i]);
                strcpy_s(godzinyPrzyjec[i], strlen(inny.godzinyPrzyjec[i]) + 1, inny.godzinyPrzyjec[i]);
            }
        }
        Lekarz& operator = (const Lekarz& inny) {
            if (this != &inny) {
                Osoba::operator=(inny);
                delete[] specjalizacja;
                delete[] pesel;

                pesel = new char[strlen(inny.pesel) + 1];
                strcpy_s(pesel, strlen(inny.pesel) + 1, inny.pesel);
                specjalizacja = new char[strlen(inny.specjalizacja) + 1];
                strcpy_s(specjalizacja, strlen(inny.specjalizacja) + 1, inny.specjalizacja);

                for (int i = 0; i < 7; i++) {
                    strcpy_s(dniPrzyjec[i], strlen(inny.dniPrzyjec[i]) + 1, inny.dniPrzyjec[i]);
                    strcpy_s(godzinyPrzyjec[i], strlen(inny.godzinyPrzyjec[i]) + 1, inny.godzinyPrzyjec[i]);
                }

            }
            return *this;

        }
        const char (*getDni() const)[15] {
            return dniPrzyjec;
        }
        ~Lekarz() {
            delete[] specjalizacja;
            delete[] pesel;

        }
};
class wizyta {
    int idWizyty, idPacjenta, idLekarza;
    char* data;
    char* godzina;



};
class BazaDanych {
public:
    Lekarz lekarze[50];
    wizyta wizyty[500];
    BazaDanych() {
    
    }
    void wczytajLekarzy(const char* nazwaPliku) {
        std::ifstream stream(nazwaPliku);
        if (!stream.is_open()) {
            //nie wczytano pliku
            return;
        }

        int i = 0;
        while (!stream.eof()){
            char* bufor = new char[901];
            stream.getline(bufor, 900);
            if (bufor[0] == '\0') {
                delete[] bufor;
                continue;
            }
            char* context = nullptr; //pozycja dla kolejnych wywolan(zapamiętanie)
            char* pesel = strtok_s(bufor, "; ", &context); //dzieli tekst na fragmenty
            char* imie = strtok_s(NULL, "; ", &context); 
            char* nazwisko = strtok_s(NULL, "; ", &context);
            char* specjalizacja = strtok_s(NULL, "; ", &context);
            char* dni = strtok_s(NULL, "; ", &context);
            char* godziny = strtok_s(NULL, "; ", &context);
            if (!pesel || !imie || !nazwisko || !specjalizacja || !dni || !godziny) {
                delete[] bufor;
                continue;
            }

            char dniTab[7][15] = { " " };
            char* dniBufor = new char[strlen(dni) + 1];
            strcpy_s(dniBufor, strlen(dni) + 1, dni);
            char* contextDni = nullptr;
            char* dzien = strtok_s(dniBufor, ", ", &contextDni);
            int j=0;
            while (dzien != nullptr) {
                strcpy_s(dniTab[j], strlen(dzien) + 1, dzien);
                j++;
                dzien = strtok_s(NULL, ", ", &contextDni);
            }

            char godzinyTab[7][12] = { "" };
            char* godzinyBufor = new char[strlen(godziny) + 1];
            strcpy_s(godzinyBufor, strlen(godziny) + 1, godziny);
            char* contextGodziny = nullptr;
            char* godzina = strtok_s(godzinyBufor, ", ", &contextGodziny);
            j = 0;
            while (godzina != nullptr) {
                strcpy_s(godzinyTab[j], strlen(godzina) + 1, godzina);
                j++;
                godzina = strtok_s(NULL, ", ", &contextGodziny);
            }

            lekarze[i]= Lekarz(pesel, imie, nazwisko, specjalizacja, dniTab, godzinyTab);
                i++;

            

        }
        
    }
};


int main()
{
    Pacjent chuj("michal", "wol", 138);
    char dni[7][15] = { "wtorek", "sorda" };  // tylko dwie wartości, reszta pustych
    char godziny[7][12] = { "13:45-19:00", "12:00-14:00" };
    BazaDanych baza;
    baza.wczytajLekarzy("E:/Lekarze.txt");
    std::cout<<baza.lekarze[2].specjalizacja<<std::endl;
    Lekarz koks("1234568975", "asddsasd", "d", "deee", dni, godziny);
    std::cout << koks.getImie();
    
}