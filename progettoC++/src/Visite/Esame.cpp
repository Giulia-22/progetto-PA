
#include "Esame.h"

Esame::Esame() {
	this->ID_esame = ID_esame_count++;
}

Esame::Esame(dottore_ref dr,paziente_ref pr){
	this->ID_esame = ID_esame_count++;
	this->d = dr;
	this->p = pr;
}

dottore_ref Esame::getDott() {
	return this->d;
}

void Esame::setDott(dottore_ref dott) {
	this->d = dott;
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
	cout<<"Eseguito dal dottore: "<<endl;
	this->getDott()->stampa();
	cout<<"Paziente: "<<endl;
	this->getPaz()->stampa();
	cout<<endl<<endl;
}

Esame::~Esame() {
}

