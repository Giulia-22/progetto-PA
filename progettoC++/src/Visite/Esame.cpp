
#include "Esame.h"

Esame::Esame() {
	this->ID_esame = ID_esame_count++;
}

Esame::Esame(int du,Dottore* dr,Paziente* pr){
	this->ID_esame = ID_esame_count++;
	this->durata = du;
	this->d = dr;
	this->p = pr;
}

Dottore* Esame::getDott() {
	//dottore_ref res (new Dottore(this->d));
	//return res;
	return this->d;
}

void Esame::setDott(dottore_ref dott) {
	this->d = dott.get();
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

Paziente* Esame::getPaz() {
	//paziente_ref res (new Paziente(this->p));
	//return res;
	return this->p;
}

void Esame::setPaz(paziente_ref paz) {
	this->p = paz.get();
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

