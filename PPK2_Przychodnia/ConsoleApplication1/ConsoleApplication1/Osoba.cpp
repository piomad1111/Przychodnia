#include "Osoba.h"
    Osoba::Osoba() {
        imie = new char[1];
        imie[0] = '\0';

        nazwisko = new char[1];
        nazwisko[0] = '\0';
    }
    Osoba::Osoba(const char* _Imie, const char* _Nazwisko) {
        imie = new char[strlen(_Imie) + 1];
        strcpy_s(imie, strlen(_Imie) + 1, _Imie);

        nazwisko = new char[strlen(_Nazwisko) + 1];
        strcpy_s(nazwisko, strlen(_Nazwisko) + 1, _Nazwisko);

    }
    Osoba::Osoba(const Osoba& inna) {
        imie = new char[strlen(inna.imie) + 1]; //kopiuje dane nie wskaznik
        strcpy_s(imie, strlen(inna.imie) + 1, inna.imie);

        nazwisko = new char[strlen(inna.nazwisko) + 1];
        strcpy_s(nazwisko, strlen(inna.nazwisko) + 1, inna.nazwisko);

    }
    Osoba& Osoba::operator = (const Osoba& inna) {
        if (this != &inna) {
            delete[] imie;
            delete[] nazwisko;

            imie = new char[strlen(inna.imie) + 1];
            strcpy_s(imie, strlen(inna.imie) + 1, inna.imie);

            nazwisko = new char[strlen(inna.nazwisko) + 1];
            strcpy_s(nazwisko, strlen(inna.nazwisko) + 1, inna.nazwisko);

        }
        return *this;

    }
    char* Osoba::getImie() {
        return imie;
    }
    char* Osoba::getNazwisko() {
        return nazwisko;
    }
    Osoba::~Osoba() { //destruktor
        delete[] imie;
        delete[] nazwisko; //zwolnienie pamiêci
    }