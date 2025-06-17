#include "Rejestracja.h"
Rejestracja::Rejestracja() {
	
}
Rejestracja::Rejestracja(BazaDanych	_baza) {
	baza = _baza;
}
Rejestracja& Rejestracja::operator = (const Rejestracja& inna) {
	if (this != &inna) {
		baza = inna.baza;

	}
	return *this;

}
std::vector<int> Rejestracja::wyborLekarza() {
	int i = 0;
	while (strlen(baza.lekarze[i].getPesel()) > 0 && i < 50) {
		std::cout << i << "." << baza.lekarze[i].getImie() << " " << baza.lekarze[i].getNazwisko()<<" ("<<baza.lekarze[i].getSpecjalizacja()<<")" << std::endl;
		i++;
	}
	int akcja2;
	std::cin >> akcja2;
	system("cls");
	std::vector<int> dniTyg;
	Lekarz wybranyLekarz = baza.lekarze[akcja2];
	int j = 0;
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
    dniTyg.push_back(akcja2);
	return dniTyg;
}
std::vector<char*> Rejestracja::wyborDatyLekarz(std::vector<int> dniTyg) {
	std::vector<char*> daty;
	time_t teraz = time(nullptr);
	std::tm data = {};
	localtime_s(&data, &teraz);
	
	for (int i = 0; i <= 30; ++i) {
		std::tm aktualnaData = data;
		aktualnaData.tm_mday += i;
		mktime(&aktualnaData);
		int dzienTyg = aktualnaData.tm_wday;

		for (int j = 0; j < dniTyg.size(); ++j) {
			if (dzienTyg == dniTyg[j]) {
				char *dataStr = new char[11];
				strftime(dataStr, 11, "%d-%m-%Y", &aktualnaData);
				daty.push_back(dataStr);
				break;
			}
		}
	}

	// Wypisz tylko te, które zosta³y zapisane
	for (int i = 0; i < daty.size(); ++i) {
		std::cout << i << ". " << daty[i] << std::endl;
	}
	return daty;
}
std::vector<char*> Rejestracja::pokazDostepneGodziny(Lekarz& lekarz, const char* data) {
    std::vector<char*> dostepne;

    std::tm tmData = {};
    int dzien, miesiac, rok;
    sscanf_s(data, "%d-%d-%d", &dzien, &miesiac, &rok);
    tmData.tm_mday = dzien;
    tmData.tm_mon = miesiac - 1;
    tmData.tm_year = rok - 1900;
    tmData.tm_isdst = -1;
    mktime(&tmData);

    const char* dniTygodnia[7] = {
        "Niedziela", "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota"
    };
    const char* szukanyDzien = dniTygodnia[tmData.tm_wday];

    // ZnajdŸ indeks dnia w lekarz.dniPrzyjec
    int indeks = -1;
    for (int i = 0; i < 7; ++i) {
        if (strcmp(lekarz.dniPrzyjec[i], szukanyDzien) == 0) {
            indeks = i;
            break;
        }
    }

    if (indeks == -1 || strlen(lekarz.godzinyPrzyjec[indeks]) == 0) {
        std::cout << "Lekarz nie przyjmuje w tym dniu." << std::endl;
        return dostepne;
    }

    // formatuj
    int godzStart, minStart, godzEnd, minEnd;
    sscanf_s(lekarz.godzinyPrzyjec[indeks], "%d:%d-%d:%d", &godzStart, &minStart, &godzEnd, &minEnd);


    int startMinuty = godzStart * 60 + minStart;
    int endMinuty = godzEnd * 60 + minEnd;

    for (int min = startMinuty; min + 15 <= endMinuty; min += 15) {
        int godz = min / 60;
        int minut = min % 60;

        char godzinaStr[6];
        sprintf_s(godzinaStr, 6, "%02d:%02d", godz, minut);

        //czy godzina jest ju¿ zajêta
        bool zajeta = false;
        for (int i = 0; i < 500; ++i) {
            if (strlen(baza.wizyty[i].getIdLekarza()) > 0 &&
                strcmp(baza.wizyty[i].getIdLekarza(), lekarz.getPesel()) == 0 &&
                strcmp(baza.wizyty[i].getData(), data) == 0 &&
                strcmp(baza.wizyty[i].getGodzina(), godzinaStr) == 0) {
                zajeta = true;
                break;
            }
        }

        if (!zajeta) {
            char* nowaGodzina = new char[6]; // 5 znaków + \0
            strcpy_s(nowaGodzina, 6, godzinaStr);
            dostepne.push_back(nowaGodzina);
        }
    }


    std::cout << "Dostepne godziny na dzien " << data << " (" << szukanyDzien << "):" << std::endl;
    for (int i = 0; i < dostepne.size(); ++i) {
        std::cout << i  << ". " << dostepne[i] << std::endl;
    }

    return dostepne;
}

void Rejestracja::dodajWizyte(char *pesel, char* data, char* godzina, const char* plikBaza) {
    char* idWizyty = new char[17];
    char nowaGodzina[5];
    char nowaData[9];
    char czescPesel[5];
    snprintf(nowaData, sizeof(nowaData), "%.2s%.2s%.4s", data, data + 3, data + 6);
    snprintf(nowaGodzina, sizeof(nowaGodzina), "%.2s%.2s", godzina, godzina + 3);
    strncpy_s(czescPesel, pesel + 7, 4);
    czescPesel[4] = '\0'; // dodaj null terminator

    // Po³¹cz wszystko
    snprintf(idWizyty, 17, "%s%s%s", nowaData, nowaGodzina, czescPesel);
    int i = 0;
    Wizyta nowaWizyta(idWizyty, "aa", pesel, data, godzina);
    do {
        if (strlen(baza.wizyty[i].getIdWizyty()) == 0) {
            baza.wizyty[i] = nowaWizyta;
            break;
        }
        i++;
    } while (strlen(baza.wizyty[i - 1].getIdWizyty()) > 0);
    std::cout << "Poprawnie dodano wizyte. Id wizyty to: " << idWizyty << std::endl;
    baza.zapiszBaze(plikBaza);
}


void Rejestracja::anulujWizyte(const char* idWizytyDoUsuniecia, const char* plikBaza) {
    int index = -1;

    // ZnajdŸ indeks wizyty do usuniêcia
    for (int i = 0; i < 500; ++i) {
        if (strlen(baza.wizyty[i].getIdWizyty()) == 0) break; // koniec aktywnych wizyt
        if (strcmp(baza.wizyty[i].getIdWizyty(), idWizytyDoUsuniecia) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        std::cout << "Nie znaleziono wizyty o ID: " << idWizytyDoUsuniecia << std::endl;
        return;
    }

    // Zwolnij pamiêæ z obiektu, który usuwamy (dziêki destruktorowi)
    baza.wizyty[index] = Wizyta();

    // Przesuñ pozosta³e wizyty
    for (int i = index; i < 499; ++i) {
        if (strlen(baza.wizyty[i + 1].getIdWizyty()) == 0) {
            baza.wizyty[i] = Wizyta(); // wyczyœæ ostatni element
            break;
        }
        baza.wizyty[i] = baza.wizyty[i + 1];
    }

    std::cout << "Wizyta o ID " << idWizytyDoUsuniecia << " zostala anulowana." << std::endl;
    baza.zapiszBaze(plikBaza);
}


