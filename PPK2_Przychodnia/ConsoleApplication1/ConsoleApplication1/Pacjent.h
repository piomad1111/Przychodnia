#pragma once
#include "Osoba.h"

class Pacjent : public Osoba {
    char idPacjenta[17];       // 3 + 3 + 10 = 16 znaków + '\0'
    char dataUrodzenia[11];    // dd-mm-rrrr + '\0'

    void generujID(const char* imie, const char* nazwisko, const char* data);

public:
    Pacjent(const char* _Imie, const char* _Nazwisko, const char* _dataUrodzenia);
    Pacjent();
    Pacjent& operator = (const Pacjent& inny);
    const char* getID() const;
    const char* getDataUrodzenia() const;
};
