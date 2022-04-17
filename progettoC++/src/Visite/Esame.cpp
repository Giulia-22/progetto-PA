
#include "Esame.h"

Esame::Esame() {
	this->ID_esame = ID_esame_count++;
}

Esame::Esame(int du,dottore_ref dr,paziente_ref pr){
	this->ID_esame = ID_esame_count++;
	this->durata = du;
	this->d = dr;
	this->p = pr;
}

dottore_ref Esame::getDott() {
	return this->d;
}

void Esame::setDott(dottore_ref dott) {
	this->d = dott;
}

int Esame::getDurata() {
	return durata;
}

void Esame::setDurata(int durata) {
	this->durata = durata;
}

int Esame::getIdEsame() {
	return ID_esame;
}

paziente_ref Esame::getPaz() {
	return this->p;
}

void Esame::setPaz(paziente_ref paz) {
	this->p = paz;
}

void Esame::stampa(){
	cout<<"ID esame: "<<this->getIdEsame()<<endl;
	cout<<"Durata: "<<this->getDurata()<<endl;
	cout<<"Eseguito da: "<<endl;
	this->getDott()->stampa();
	cout<<"Paziente: "<<endl;
	this->getPaz()->stampa();
	cout<<endl<<endl;
}

Esame::~Esame() {
}

