
#include "Mr.h"

Mr::Mr() {
	this->durata  = 15;
	this->intensita = 2;
}
Mr::Mr(int du, int in, dottore_ref dr,paziente_ref pr):Esame(dr,pr){
	this->durata = du;
	this->intensita = in;
}

void Mr::setDurata(int d) {
	this->durata = d;
}

void Mr::setIntensita(int inte) {
	this->intensita = inte;
}

int Mr::getDurata() {
	return durata;
}

int Mr::getIntensita() {
	return intensita;
}

void Mr::stampa(){
	cout<<"ID esame PET: "<<this->getIdEsame()<<endl;
	cout<<"Durata prevista: "<<this->durata<<endl;
	cout<<"Intensita' utilizzata: "<<this->intensita<<endl;
	cout<<"Eseguito dal dottore: "<<endl;
	this->getDott()->stampa();
	cout<<"Paziente: "<<endl;
	this->getPaz()->stampa();
	cout<<endl<<endl;
}

Mr::~Mr() {
}

