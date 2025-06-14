#include "Lekarz.h"
    Lekarz::Lekarz() :Osoba() {
        pesel = new char[1];
        pesel[0] = '\0';
        specjalizacja = new char[1];
        specjalizacja[0] = '\0';
        for (int i = 0; i < 7;i++) {
            dniPrzyjec[i][0] = '\0';
            godzinyPrzyjec[i][0] = '\0';
        }

    }
    Lekarz::Lekarz(const char* _Pesel, const char* _Imie, const char* _Nazwisko, const char* _Specjalizacja, char _dniPrzyjec[7][15], char _godzinyPrzyjec[7][12]) :Osoba(_Imie, _Nazwisko) {
        pesel = new char[strlen(_Pesel) + 1];
        strcpy_s(pesel, strlen(_Pesel) + 1, _Pesel);
        specjalizacja = new char[strlen(_Specjalizacja) + 1];
        strcpy_s(specjalizacja, strlen(_Specjalizacja) + 1, _Specjalizacja);
        for (int i = 0; i < 7; i++) {
            dniPrzyjec[i][0] = '\0';
            godzinyPrzyjec[i][0] = '\0';
        }
        for (int i = 0; i < 7; i++) {
            strcpy_s(dniPrzyjec[i], strlen(_dniPrzyjec[i]) + 1, _dniPrzyjec[i]);
            strcpy_s(godzinyPrzyjec[i], strlen(_godzinyPrzyjec[i]) + 1, _godzinyPrzyjec[i]);
        }
    }

    Lekarz::Lekarz(const Lekarz& inny) :Osoba(inny) {
        pesel = new char[strlen(inny.pesel) + 1];
        strcpy_s(pesel, strlen(inny.pesel) + 1, inny.pesel);

        specjalizacja = new char[strlen(inny.specjalizacja) + 1];
        strcpy_s(specjalizacja, strlen(inny.specjalizacja) + 1, inny.specjalizacja);
        for (int i = 0; i < 7; i++) {
            strcpy_s(dniPrzyjec[i], strlen(inny.dniPrzyjec[i]) + 1, inny.dniPrzyjec[i]);
            strcpy_s(godzinyPrzyjec[i], strlen(inny.godzinyPrzyjec[i]) + 1, inny.godzinyPrzyjec[i]);
        }
    }
    Lekarz& Lekarz::operator = (const Lekarz& inny) {
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
    const char (*Lekarz::getDni() const)[15] {
        return dniPrzyjec;
    }
    char* Lekarz::getPesel() {
        return pesel;
    }
    char* Lekarz::getSpecjalizacja() {
        return specjalizacja;

    }
    Lekarz::~Lekarz() {
        delete[] specjalizacja;
        delete[] pesel;

    }