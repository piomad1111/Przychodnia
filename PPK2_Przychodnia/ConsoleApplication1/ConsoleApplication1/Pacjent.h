#pragma once
#include "Osoba.h"
class Pacjent : public Osoba {
    int idPacjenta;

public:
    Pacjent(const char* _Imie, const char* _Nazwisko, int _idPacjenta);
    int getID() const;
};