#pragma once
#include "BazaDanych.h"
#include <vector>
#include <cstring>
#include <sstream>
#include <ctime>


class Rejestracja
{
	public:
	BazaDanych baza;

	//BazaDanych baza;
	Rejestracja();
	Rejestracja(BazaDanych	_baza);
	Rejestracja& operator = (const Rejestracja& inna);
	std::vector<char*> wyborDatyLekarz(std::vector<int> dniTyg);
	std::vector<int> wyborLekarza();
	std::vector<char*> pokazDostepneGodziny(Lekarz& lekarz, const char* data);
	void dodajWizyte(char* pesel, char* data, char* godzina, const char* plikBaza);
	void anulujWizyte(const char* idWizytyDoUsuniecia, const char* plikBaza);

};

