#pragma once
#include "Lekarz.h"
#include "Wizyta.h"
#include "Pacjent.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>

class BazaDanych {
public:
    Lekarz lekarze[50];
    Wizyta wizyty[500];
    Pacjent pacjenci[500];
    BazaDanych();
    BazaDanych(Lekarz _lekarze[50], Wizyta _wizyty[500]);
    BazaDanych& operator = (const BazaDanych& inna);
    void wczytajLekarzy(const char* nazwaPliku);
    void zapiszBaze(const char* nazwaPliku);
    void wczytajBaze(const char* nazwaPliku);
    void wyswietlBaze(const char* nazwaPliku);
    void zapiszBazePacjenci(const char* nazwaPliku);
    void wczytajBazePacjenci(const char* nazwaPliku);
    struct record;
    struct rekordPacjent;

};