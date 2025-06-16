#pragma once
#include "Lekarz.h"
#include "Wizyta.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>

class BazaDanych {
public:
    Lekarz lekarze[50];
    Wizyta wizyty[500];
    BazaDanych();
    void wczytajLekarzy(const char* nazwaPliku);
    void zapiszBaze(const char* nazwaPliku);
    void wczytajBaze(const char* nazwaPliku);
    struct record;
};