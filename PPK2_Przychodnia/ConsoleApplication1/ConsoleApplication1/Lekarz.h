#pragma once
#include "Osoba.h"
class Lekarz : public Osoba {
    char* pesel;
    char* specjalizacja;

public:
    char dniPrzyjec[7][15];
    char godzinyPrzyjec[7][12];
    Lekarz();
    Lekarz(const char* _Pesel, const char* _Imie, const char* _Nazwisko, const char* _Specjalizacja, char _dniPrzyjec[7][15], char _godzinyPrzyjec[7][12]);
    Lekarz(const Lekarz& inny);
    Lekarz& operator = (const Lekarz& inny);
    //const char (*getDni() const)[15];
    char* getPesel();
    char* getSpecjalizacja();
    ~Lekarz();
};