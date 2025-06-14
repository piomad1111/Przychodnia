// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include "Osoba.h"
#include "Lekarz.h"
#include "BazaDanych.h"
#include "Pacjent.h"










int main()
{
    Pacjent chuj("michal", "wol", 138);
    char dni[7][15] = { "wtorek", "sorda" };  // tylko dwie wartości, reszta pustych
    char godziny[7][12] = { "13:45-19:00", "12:00-14:00" };
    BazaDanych baza;
    baza.wczytajLekarzy("E:/Lekarze.txt");
    std::cout<<baza.lekarze[2].getSpecjalizacja()<<std::endl;
    Lekarz koks("1234568975", "asddsasd", "d", "deee", dni, godziny);
    std::cout << koks.getImie();
    
}