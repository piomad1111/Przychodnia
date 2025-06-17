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
#include "Rejestracja.h"


int main(int argc, char* argv[])
{
	const char* plikPacjentow = "E:/bazaPacjenci.dat";
	const char* plikLekarzy = "E:/Lekarze.txt";
	const char* plikBazaIN = "E:/baza.dat";
	const char* plikBazaOUT = "E:/baza.dat";


	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-inP") == 0) {
			if (i + 1 < argc && argv[i + 1][0] != '-') { 
				plikPacjentow = argv[++i];
			}
		}
		else if (strcmp(argv[i], "-inL") == 0) {
			if (i + 1 < argc && argv[i + 1][0] != '-') {
				plikLekarzy = argv[++i];
			}
		}
		else if (strcmp(argv[i], "-inB") == 0) {
			if (i + 1 < argc && argv[i + 1][0] != '-') {
				plikBazaIN = argv[++i];
			}
		}
		else if (strcmp(argv[i], "-outB") == 0) {
			if (i + 1 < argc && argv[i + 1][0] != '-') {
				plikBazaOUT = argv[++i];
			}
		}
		else {
			std::cout << "Nieznany parametr: " << argv[i] << std::endl;

		}
	}


	BazaDanych baza;
	baza.wczytajLekarzy(plikLekarzy);
	baza.wczytajBaze(plikBazaIN);
	std::cout << "Czy masz juz id Pacjenta?\n";
	int konto;
	std::cout << "1. Tak \n";
	std::cout << "2. Nie \n";
	std::cin>> konto;
	char idPacjenta[17];
	Pacjent nowyPacjent;
	if (konto == 1) {
		std::cout << "Podaj id pacjenta: ";
		std::cin >> idPacjenta;
	}
	else if (konto == 2) {
		char imie[30], nazwisko[40], dataUrodzenia[11];
		std::cout << "Podaj imie: ";
		std::cin >> imie;
		std::cout << "Podaj nazwisko: ";
		std::cin >> nazwisko;
		std::cout << "Podaj date urodzenia: ";
		std::cin >> dataUrodzenia;
		Pacjent nowyPacjent(imie, nazwisko, dataUrodzenia);
		strcpy_s(idPacjenta,17, nowyPacjent.getID());
	}
	int z = 0;
	do {
		if (strlen(baza.pacjenci[z].getID()) == 0) {
			baza.pacjenci[z] = nowyPacjent;
			break;
		}
		z++;
	} while (strlen(baza.wizyty[z - 1].getIdWizyty()) > 0);
	baza.zapiszBazePacjenci(plikPacjentow);
	system("cls");

	std::cout << "Twoje id to "<< idPacjenta <<std::endl;
	 int akcja;
	std::cout << "Wybierz akcje" << std::endl;
	std::cout << "1. Rejestracja na wizyte" << std::endl;
	std::cout << "2. Anulowanie wizyty" << std::endl;
	std::cout << "3. Wyjscie z programu" << std::endl;
	std::cin >> akcja;
	system("cls");
	Rejestracja ra(baza);
	if (akcja == 1) {
		std::vector<int> dniTyg = ra.wyborLekarza();
		std::vector<char*> daty = ra.wyborDatyLekarz(dniTyg);

		int akcja3;
		std::cin >> akcja3;
		system("cls");

		int akcja2 = dniTyg.back();
		dniTyg.pop_back();
		Lekarz wybrany = baza.lekarze[akcja2];
		std::vector<char*> godzinyDostepnosci = ra.pokazDostepneGodziny(wybrany, daty[akcja3]);
		int akcja4;
		std::cin >> akcja4;
		system("cls");

		ra.dodajWizyte(wybrany.getPesel(), daty[akcja3], godzinyDostepnosci[akcja4], plikBazaOUT, idPacjenta);
	}
	else if (akcja == 2) {
		std::cout << "Podaj id wizyty ktora chcesz anulowac: ";
		char idAnulowanie[30];
		std::cin >> idAnulowanie;
		ra.anulujWizyte(idAnulowanie, plikBazaIN);

	}
	else if (akcja == 3) {
		return 0;
	}
	
	//system("cls");

 }