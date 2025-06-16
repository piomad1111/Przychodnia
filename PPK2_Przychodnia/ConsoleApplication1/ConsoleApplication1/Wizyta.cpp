#include "Wizyta.h"
Wizyta::Wizyta(){
	idWizyty = new char[1];
	idPacjenta = new char[1];
	idLekarza = new char[1];
	data = new char[1];
	godzina = new char[1];

	idWizyty[0] = '\0';
	idPacjenta[0] = '\0';
	idLekarza[0] = '\0';
	data[0] = '\0';
	godzina[0] = '\0';



}
Wizyta::Wizyta(const char* _idWizyty, const char* _idPacjenta, const char* _idLekarza, const char* _data, const char* _godzina){
	idWizyty = new char[strlen(_idWizyty) + 1];
	strcpy_s(idWizyty, strlen(_idWizyty) + 1, _idWizyty);
	
	idPacjenta = new char[strlen(_idPacjenta) + 1];
	strcpy_s(idPacjenta, strlen(_idPacjenta) + 1, _idPacjenta);

	idLekarza = new char[strlen(_idLekarza) + 1];
	strcpy_s(idLekarza, strlen(_idLekarza) + 1, _idLekarza);

	data = new char[strlen(_data) + 1];
	strcpy_s(data, strlen(_data) + 1, _data);

	godzina = new char[strlen(_godzina) + 1];
	strcpy_s(godzina, strlen(_godzina) + 1, _godzina);
}
Wizyta::Wizyta(const Wizyta &inna) {
	idWizyty = new char[strlen(inna.idWizyty) + 1];
	strcpy_s(idWizyty, strlen(inna.idWizyty) + 1, inna.idWizyty);

	idPacjenta = new char[strlen(inna.idPacjenta) + 1];
	strcpy_s(idPacjenta, strlen(inna.idPacjenta) + 1, inna.idPacjenta);

	idLekarza = new char[strlen(inna.idLekarza) + 1];
	strcpy_s(idLekarza, strlen(inna.idLekarza) + 1, inna.idLekarza);

	data = new char[strlen(inna.data) + 1];
	strcpy_s(data, strlen(inna.data) + 1, inna.data);

	godzina = new char[strlen(inna.godzina) + 1];
	strcpy_s(godzina, strlen(inna.godzina) + 1, inna.godzina);
}
Wizyta& Wizyta::operator = (const Wizyta& inny) {
	if (this != &inny) {
		delete[] idWizyty;
		delete[] idPacjenta;
		delete[] idLekarza;
		delete[] data;
		delete[] godzina;

		idWizyty = new char[strlen(inny.idWizyty) + 1];
		strcpy_s(idWizyty, strlen(inny.idWizyty) + 1, inny.idWizyty);

		idPacjenta = new char[strlen(inny.idPacjenta) + 1];
		strcpy_s(idPacjenta, strlen(inny.idPacjenta) + 1, inny.idPacjenta);

		idLekarza = new char[strlen(inny.idLekarza) + 1];
		strcpy_s(idLekarza, strlen(inny.idLekarza) + 1, inny.idLekarza);

		data = new char[strlen(inny.data) + 1];
		strcpy_s(data, strlen(inny.data) + 1, inny.data);

		godzina = new char[strlen(inny.godzina) + 1];
		strcpy_s(godzina, strlen(inny.godzina) + 1, inny.godzina);
		

	}
	return *this;

}
char* Wizyta::getIdWizyty(){
	return idWizyty;
}
char* Wizyta::getIdPacjenta() {
	return idPacjenta;
}
char* Wizyta::getIdLekarza(){
	return idLekarza;
}
char* Wizyta::getData() {
	return data;
}
char* Wizyta::getGodzina() {
	return godzina;
}
Wizyta::~Wizyta() {
	delete[] idWizyty;
	delete[] idPacjenta;
	delete[] idLekarza;
	delete[] data;
	delete[] godzina;
}
