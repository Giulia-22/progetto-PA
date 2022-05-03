
#include "Persona.h"

Persona::Persona(){	 // @suppress("Class members should be properly initialized")

	this->annonascita = 1900;
	this->cf = "";
	this->nome = "";
	this->cognome = "";

}

Persona::Persona(int a, string codfisc, string n, string c) { 	// @suppress("Class members should be properly initialized")
	this->annonascita = a;
	this->cf = codfisc;
	this->nome = n;
	this->cognome = c;
}

Persona::Persona(const Persona &p){	 // @suppress("Class members should be properly initialized")
	Persona(p.annonascita,p.cf,p.nome,p.cognome);
}

int Persona::getAnnonascita() {
	return this->annonascita;
}

void Persona::setAnnonascita(int a) {
	this->annonascita = a;
}

string Persona::getCf() {
	return this->cf;
}

void Persona::setCf(string codfisc) {
	this->cf = cf;
}

string Persona::getCognome() {
	return cognome;
}

void Persona::setCognome(string c) {
	this->cognome = c;
}

string Persona::getNome() {
	return this->nome;
}

void Persona::setNome(string n) {
	this->nome = n;
}

void Persona::stampa(){
	cout<<"Nome: "<<this->getNome()<<endl;
	cout<<"Cognome: "<<this->getCognome()<<endl;
	cout<<"Anno di nascita: "<<this->getAnnonascita()<<endl;
	cout<<"Codice fiscale: "<<this->getCf()<<endl<<endl;
}

Persona::~Persona() {
	cout<<"distruggo persona"<<endl;
}
