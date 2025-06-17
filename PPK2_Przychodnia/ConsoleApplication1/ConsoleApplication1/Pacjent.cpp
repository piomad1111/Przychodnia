#include "Pacjent.h"
#include <cstring>

void Pacjent::generujID(const char* imie, const char* nazwisko, const char* data) {

    int lenImie = 0;
    while (imie[lenImie] != '\0' && lenImie < 3) lenImie++;


    int lenNazwisko = 0;
    while (nazwisko[lenNazwisko] != '\0' && lenNazwisko < 3) lenNazwisko++;

    int pos = 0;
    for (int i = 0; i < lenImie; ++i)
        idPacjenta[pos++] = imie[i];

    for (int i = 0; i < lenNazwisko; ++i)
        idPacjenta[pos++] = nazwisko[i];


    for (int i = 0; i < 10; ++i) {
        if (data[i] != '-') {
            idPacjenta[pos++] = data[i];
        }
    }
    idPacjenta[pos] = '\0';
}
Pacjent::Pacjent() : Osoba("", "") {

    idPacjenta[0] = '\0';
    dataUrodzenia[0] = '\0';
}
Pacjent::Pacjent(const char* _Imie, const char* _Nazwisko, const char* _dataUrodzenia)
    : Osoba(_Imie, _Nazwisko)
{
    for (int i = 0; i < 10; ++i)
        dataUrodzenia[i] = _dataUrodzenia[i];
    dataUrodzenia[10] = '\0';

    generujID(_Imie, _Nazwisko, _dataUrodzenia);
}
Pacjent& Pacjent::operator=(const Pacjent& other) {
    if (this != &other) {

        Osoba::operator=(other);

        for (int i = 0; i < 11; ++i)
            dataUrodzenia[i] = other.dataUrodzenia[i];


        for (int i = 0; i < 17; ++i)
            idPacjenta[i] = other.idPacjenta[i];
    }
    return *this;
}

const char* Pacjent::getID() const {
    return idPacjenta;
}

const char* Pacjent::getDataUrodzenia() const {
    return dataUrodzenia;
}
