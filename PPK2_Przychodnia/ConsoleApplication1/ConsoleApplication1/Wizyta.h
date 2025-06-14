#pragma once
#include <cstring>
#include <ctime>
class Wizyta {
    char* idWizyty, *idPacjenta, *idLekarza;
    char* data;
    char* godzina;
public:
    Wizyta();
    Wizyta(const char* _idWizyty, const char* _idPacjenta, const char* _idLekarza, const char* _data, const char* _godzina);
    Wizyta(const Wizyta& inna);
    ~Wizyta();
};

