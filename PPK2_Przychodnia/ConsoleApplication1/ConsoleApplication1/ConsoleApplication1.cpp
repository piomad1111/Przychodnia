// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "Osoba.h"
#include "Lekarz.h"
#include "BazaDanych.h"
#include "Pacjent.h"
#include "Wizyta.h"

void wypiszOdcinkiCzasu(const char* przedzial) {
	char bufor[32];
	strcpy_s(bufor, sizeof(bufor), przedzial);

	// Rozdziel przedział na początek i koniec (np. "13:00" i "14:30")
	char* context = nullptr;
	char* poczatek = strtok_s(bufor, "-", &context);
	char* koniec = strtok_s(nullptr, "-", &context);

	if (!poczatek || !koniec) {
		std::cerr << "Niepoprawny format przedziału!" << std::endl;
		return;
	}

	// Rozdziel godziny i minuty dla początku
	char czasStart[6];
	strcpy_s(czasStart, sizeof(czasStart), poczatek);

	char* ctx1 = nullptr;
	char* h1 = strtok_s(czasStart, ":", &ctx1);
	char* m1 = strtok_s(nullptr, ":", &ctx1);

	// Rozdziel godziny i minuty dla końca
	char czasStop[6];
	strcpy_s(czasStop, sizeof(czasStop), koniec);

	char* ctx2 = nullptr;
	char* h2 = strtok_s(czasStop, ":", &ctx2);
	char* m2 = strtok_s(nullptr, ":", &ctx2);

	if (!h1 || !m1 || !h2 || !m2) {
		std::cerr << "Niepoprawny format czasu!" << std::endl;
		return;
	}

	int godz1 = atoi(h1);
	int min1 = atoi(m1);
	int godz2 = atoi(h2);
	int min2 = atoi(m2);

	int start = godz1 * 60 + min1;
	int stop = godz2 * 60 + min2;

	// Wypisz przedziały co 15 minut
	for (int minuty = start; minuty < stop; minuty += 15) {
		int godz = minuty / 60;
		int min = minuty % 60;

		char czas[6];
		sprintf_s(czas, sizeof(czas), "%02d:%02d", godz, min);

		std::cout << czas << std::endl;
	}
}

int main()
{

	BazaDanych baza;
	baza.wczytajLekarzy("E:/Lekarze.txt");
	baza.wczytajBaze("E:/baza.dat");
	Wizyta aha("156321", "9879", "2138", "18-06-2025", "13:15");
	baza.wizyty[0] = aha;
	baza.zapiszBaze("E:/baza.dat");
	 int akcja=1;
	std::cout << "Wybierz akcje" << std::endl;
	std::cout << "1. Rejestracja na wizyte" << std::endl;
	std::cout << "2. Anulowanie wizyty" << std::endl;
	std::cout << "3. Wyjscie z programu" << std::endl;
	//std::cin >> akcja;

	if (akcja == 1) {
		system("cls");
		int i = 0;
		while (strlen(baza.lekarze[i].getPesel()) > 0 && i < 50) {
			std::cout << i << "." << baza.lekarze[i].getImie() << " " << baza.lekarze[i].getNazwisko() << std::endl;
			i++;
		}
		int akcja2;
		std::cin >> akcja2;
		system("cls");

		Lekarz wybranyLekarz = baza.lekarze[akcja2];
		int j = 0;
		std::vector<int> dniTyg;
		while (strlen(wybranyLekarz.dniPrzyjec[j]) > 0) {
			if (strcmp(wybranyLekarz.dniPrzyjec[j], "Niedziela") == 0)
				dniTyg.push_back(0);
			else if (strcmp(wybranyLekarz.dniPrzyjec[j], "Poniedzialek") == 0)
				dniTyg.push_back(1);
			else if (strcmp(wybranyLekarz.dniPrzyjec[j], "Wtorek") == 0)
				dniTyg.push_back(2);
			else if (strcmp(wybranyLekarz.dniPrzyjec[j], "Sroda") == 0)
				dniTyg.push_back(3);
			else if (strcmp(wybranyLekarz.dniPrzyjec[j], "Czwartek") == 0)
				dniTyg.push_back(4);
			else if (strcmp(wybranyLekarz.dniPrzyjec[j], "Piatek") == 0)
				dniTyg.push_back(5);
			else if (strcmp(wybranyLekarz.dniPrzyjec[j], "Sobota") == 0)
				dniTyg.push_back(6);
			j++;
		}

		char daty[31][11];
		time_t teraz = time(nullptr);
		std::tm data = {};
		localtime_s(&data, &teraz);
		int licznikDat = 0;
		for (int i = 0; i <= 30; ++i) {
			std::tm aktualnaData = data;
			aktualnaData.tm_mday += i;
			mktime(&aktualnaData);
			int dzienTyg = aktualnaData.tm_wday;

			for (int j = 0; j < dniTyg.size(); ++j) {
				if (dzienTyg == dniTyg[j]) {
					strftime(daty[licznikDat], sizeof(daty[licznikDat]), "%d-%m-%Y", &aktualnaData);
					licznikDat++;
					break;
				}
			}
		}

		// Wypisz tylko te, które zostały zapisane
		for (int i = 0; i < licznikDat; ++i) {
			std::cout<<i<<". " << daty[i] << std::endl;
		}
		int akcja3;
		std::cin >> akcja3;
		int k=0;
		char *powtorkaDaty[96];
		int liczDaty = 0;
		while (strlen(baza.wizyty[k].getIdWizyty()) > 0) {
			if (strcmp(baza.wizyty[k].getData(), daty[akcja3]) == 0) {
				powtorkaDaty[liczDaty] = baza.wizyty[k].getGodzina();
				liczDaty++;
			}
			k++;
		}

	}
	//system("cls");

 }