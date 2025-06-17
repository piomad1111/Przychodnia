#include "BazaDanych.h"
BazaDanych::BazaDanych() {

 }

BazaDanych::BazaDanych(Lekarz _lekarze[50], Wizyta _wizyty[500]) {
    for (size_t i = 0; i < 50; i++)
    {
        lekarze[i] = _lekarze[i];
    }
    for (size_t i = 0; i < 500; i++)
    {
        wizyty[i] = _wizyty[i];
    }
}
BazaDanych& BazaDanych::operator = (const BazaDanych& inna) {
    if (this != &inna) {
        for (size_t i = 0; i < 50; i++)
        {
            lekarze[i] = inna.lekarze[i];
        }
        for (size_t i = 0; i < 500; i++)
        {
            wizyty[i] = inna.wizyty[i];
        }


    }
    return *this;

}
void BazaDanych::wczytajLekarzy(const char* nazwaPliku) {
        std::ifstream stream(nazwaPliku);
        if (!stream.is_open()) {
            std::cout << "Blad pliku \n";
            return;
        }

        int i = 0;
        while (!stream.eof()) {
            char* bufor = new char[512];
            stream.getline(bufor, 511);
            if (bufor[0] == '\0') {
                delete[] bufor;
                continue;
            }
            char* context = nullptr; //pozycja dla kolejnych wywolan(zapamiêtanie)
            char* pesel = strtok_s(bufor, "; ", &context); //dzieli tekst na fragmenty
            char* imie = strtok_s(NULL, "; ", &context);
            char* nazwisko = strtok_s(NULL, "; ", &context);
            char* specjalizacja = strtok_s(NULL, "; ", &context);
            char* dni = strtok_s(NULL, ";", &context);
            char* godziny = strtok_s(NULL, ";", &context);
            if (!pesel || !imie || !nazwisko || !specjalizacja || !dni || !godziny) {
                delete[] bufor;
                continue;
            }

            char dniTab[7][15] = { "" };
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
            delete[] bufor;
        }

    }
struct rekord {
    char idWizyty[20], idPacjenta[17], idLekarza[12];
    char data[11];
    char godzina[6];
};

    
void BazaDanych::zapiszBaze(const char* nazwaPliku) {
    std::fstream stream(nazwaPliku, std::ios::out | std::ios::binary);
    rekord rec;
    int i = 0;
    while(strlen(wizyty[i].getIdWizyty()) > 0) {
        strcpy_s(rec.idWizyty, wizyty[i].getIdWizyty());
        strcpy_s(rec.idPacjenta, wizyty[i].getIdPacjenta());
        strcpy_s(rec.idLekarza, wizyty[i].getIdLekarza());
        strcpy_s(rec.data, wizyty[i].getData());
        strcpy_s(rec.godzina, wizyty[i].getGodzina());
        stream.write(reinterpret_cast<char*>(&rec), sizeof(rekord));

        i++;
    }
    stream.close();
}
void BazaDanych::wczytajBaze(const char* nazwaPliku) {

    std::fstream stream(nazwaPliku, std::ios::in | std::ios::binary);
    if (!stream) {
        std::cout << "B³¹d bazy" << std::endl;

    }
    rekord rec2;
    int i = 0;
    while (stream.read(reinterpret_cast<char*>(&rec2), sizeof(rekord))) {
        wizyty[i] = Wizyta(rec2.idWizyty, rec2.idPacjenta, rec2.idLekarza, rec2.data, rec2.godzina);
        i++;
    }
    stream.close();
}
void BazaDanych::wyswietlBaze(const char* nazwaPliku) {

    std::fstream stream(nazwaPliku, std::ios::in | std::ios::binary);
    if (!stream) {
        std::cout<<"B³¹d bazy"<<std::endl;
    }
    rekord rec2;
    int i = 0;
    while (stream.read(reinterpret_cast<char*>(&rec2), sizeof(rekord))) {
       std::cout<<rec2.idWizyty<<" "<< rec2.idPacjenta << " " << rec2.idLekarza << " " << rec2.data << " " << rec2.godzina << "\n";
        i++;
    }
    stream.close();
}
struct BazaDanych::rekordPacjent {
    char imie[30], nazwisko[40], idPacjenta[21], dataUrodzenia[11];
};

void BazaDanych::zapiszBazePacjenci(const char* nazwaPliku) {
    std::fstream stream(nazwaPliku, std::ios::out | std::ios::binary);
    rekordPacjent rek;
    int i = 0;
    while (strlen(pacjenci[i].getID()) > 0) {
        strcpy_s(rek.imie, pacjenci[i].getImie());
        strcpy_s(rek.nazwisko, pacjenci[i].getNazwisko());
        strcpy_s(rek.dataUrodzenia, pacjenci[i].getDataUrodzenia());
        strcpy_s(rek.idPacjenta, pacjenci[i].getID());
        stream.write(reinterpret_cast<char*>(&rek), sizeof(rekordPacjent));

        i++;
    }
    stream.close();
}
void BazaDanych::wczytajBazePacjenci(const char* nazwaPliku) {

    std::fstream stream(nazwaPliku, std::ios::in | std::ios::binary);
    if (!stream) {
        std::cout << "B³¹d bazy" << std::endl;

    }
    rekordPacjent rek2;
    int i = 0;
    while (stream.read(reinterpret_cast<char*>(&rek2), sizeof(rekordPacjent))) {
        pacjenci[i] = Pacjent(rek2.imie, rek2.nazwisko,rek2.dataUrodzenia);
        i++;
    }
    stream.close();
}