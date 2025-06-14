#include "BazaDanych.h"
    BazaDanych::BazaDanych() {

    }
    void BazaDanych::wczytajLekarzy(const char* nazwaPliku) {
        std::ifstream stream(nazwaPliku);
        if (!stream.is_open()) {
            //nie wczytano pliku
            return;
        }

        int i = 0;
        while (!stream.eof()) {
            char* bufor = new char[901];
            stream.getline(bufor, 900);
            if (bufor[0] == '\0') {
                delete[] bufor;
                continue;
            }
            char* context = nullptr; //pozycja dla kolejnych wywolan(zapamiêtanie)
            char* pesel = strtok_s(bufor, "; ", &context); //dzieli tekst na fragmenty
            char* imie = strtok_s(NULL, "; ", &context);
            char* nazwisko = strtok_s(NULL, "; ", &context);
            char* specjalizacja = strtok_s(NULL, "; ", &context);
            char* dni = strtok_s(NULL, "; ", &context);
            char* godziny = strtok_s(NULL, "; ", &context);
            if (!pesel || !imie || !nazwisko || !specjalizacja || !dni || !godziny) {
                delete[] bufor;
                continue;
            }

            char dniTab[7][15] = { " " };
            char* dniBufor = new char[strlen(dni) + 1];
            strcpy_s(dniBufor, strlen(dni) + 1, dni);
            char* contextDni = nullptr;
            char* dzien = strtok_s(dniBufor, ", ", &contextDni);
            int j = 0;
            while (dzien != nullptr) {
                strcpy_s(dniTab[j], strlen(dzien) + 1, dzien);
                j++;
                dzien = strtok_s(NULL, ", ", &contextDni);
            }

            char godzinyTab[7][12] = { "" };
            char* godzinyBufor = new char[strlen(godziny) + 1];
            strcpy_s(godzinyBufor, strlen(godziny) + 1, godziny);
            char* contextGodziny = nullptr;
            char* godzina = strtok_s(godzinyBufor, ", ", &contextGodziny);
            j = 0;
            while (godzina != nullptr) {
                strcpy_s(godzinyTab[j], strlen(godzina) + 1, godzina);
                j++;
                godzina = strtok_s(NULL, ", ", &contextGodziny);
            }

            lekarze[i] = Lekarz(pesel, imie, nazwisko, specjalizacja, dniTab, godzinyTab);
            i++;



        }

    }
