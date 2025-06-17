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


int main()
{

	BazaDanych baza;
	baza.wczytajLekarzy("E:/Lekarze.txt");
	baza.wczytajBaze("E:/baza.dat");
	baza.zapiszBaze("E:/baza.dat");
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
		std::vector<char*> daty = ra. wyborDatyLekarz(dniTyg);
		
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

		ra.dodajWizyte(wybrany.getPesel(), daty[akcja3], godzinyDostepnosci[akcja4], "E:/baza.dat");
	}
	else if (akcja == 2) {
		std::cout << "Podaj id wizyty ktora chcesz anulowac: ";
		char idAnulowanie[30];
		std::cin >> idAnulowanie;
		ra.anulujWizyte(idAnulowanie, "E:/baza.dat");

	}
	else if (akcja == 3) {

	}
	
	//system("cls");

 }