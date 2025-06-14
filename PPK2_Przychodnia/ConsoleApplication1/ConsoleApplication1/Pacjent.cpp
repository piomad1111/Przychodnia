#include "Pacjent.h"
Pacjent::Pacjent(const char* _Imie, const char* _Nazwisko, int _idPacjenta) :Osoba(_Imie, _Nazwisko) {

}
int Pacjent::getID() const{
    return idPacjenta;
}