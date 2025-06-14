#pragma once
#include <cstring>

class Osoba {
	char* imie,
		* nazwisko;
	public:
		Osoba();
		Osoba(const char* _Imie, const char* _Nazwisko);
		Osoba(const Osoba& inna);
		Osoba& operator = (const Osoba& inna);
		virtual ~Osoba();
        char* getImie();
		char* getNazwisko();
};