
#include "Dottore.h"

Dottore::Dottore() {
	this->ID_dott = ID_dott_count++;
	this->specializzazione = "";
}

Dottore::Dottore(Dottore* pers){
	this->annonascita = pers->getAnnonascita();
	this->cf = pers->getCf();
	this->nome = pers->getNome();
	this->cognome = pers->getCognome();
	this->ID_dott = ID_dott_count++;
	this->specializzazione = "";
}

Dottore::Dottore(int an, string codfisc, string n, string c, string spe):Persona(an,codfisc,n,c){
	this->ID_dott = ID_dott_count++;
	this->specializzazione = spe;
}

string Dottore::getSpecializzazione() {
	return this->specializzazione;
}

void Dottore::setSpecializzazione(string s) {
	this->specializzazione = s;
}

int Dottore::getIdDott() {
	return ID_dott;
}

void Dottore::stampa(){
	cout<<"Nome: "<<this->getNome()<<endl;
	cout<<"Cognome: "<<this->getCognome()<<endl;
	cout<<"Anno di nascita: "<<this->getAnnonascita()<<endl;
	cout<<"Codice fiscale: "<<this->getCf()<<endl;
	cout<<"ID dottore: "<<this->getIdDott()<<endl;
	cout<<"Specializzazione: "<<this->getSpecializzazione()<<endl<<endl;
}

Dottore::~Dottore() {
	cout<<"distruggo dottore"<<endl;
}

