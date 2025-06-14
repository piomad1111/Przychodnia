#pragma once
#include "Lekarz.h"
#include "Wizyta.h"
#include <cstring>
#include <sstream>
#include <fstream>
class BazaDanych {
public:
    Lekarz lekarze[50];
    Wizyta wizyty[500];
    BazaDanych();
    void wczytajLekarzy(const char* nazwaPliku);
};