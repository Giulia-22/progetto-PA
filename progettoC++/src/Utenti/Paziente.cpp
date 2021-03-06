
#include "Paziente.h"

Paziente::Paziente() {
	this->ID_paz = ID_paz_count++;
	this->categoria = sconosciuto;
}

Paziente::Paziente(Paziente* pers){
	this->annonascita = pers->getAnnonascita();
	this->cf = pers->getCf();
	this->nome = pers->getNome();
	this->cognome = pers->getCognome();
	this->ID_paz = ID_paz_count++;
	this->categoria = pers->categoria;
}

Paziente::Paziente(int an, string codfisc, string n, string c, category cat):Persona(an,codfisc,n,c){
	this->ID_paz = ID_paz_count++;
	this->categoria = cat;
}

category Paziente::getCategoria() {
	return this->categoria;
}

void Paziente::setCategoria(category c) {
	this->categoria = c;
}

int Paziente::getIdPaz() {
	return ID_paz;
}

void Paziente::stampa(){
	cout<<"Nome: "<<this->getNome()<<endl;
	cout<<"Cognome: "<<this->getCognome()<<endl;
	cout<<"Anno di nascita: "<<this->getAnnonascita()<<endl;
	cout<<"Codice fiscale: "<<this->getCf()<<endl;
	cout<<"ID paziente: "<<this->getIdPaz()<<endl;
	cout<<"Categoria: "<<this->getCategoria()<<endl<<endl;
}

Paziente::~Paziente() {
	cout<<"distruggo paziente"<<endl;
}

