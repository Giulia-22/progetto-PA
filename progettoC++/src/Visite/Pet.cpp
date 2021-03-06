
#include "Pet.h"

Pet::Pet() {
	this->durata = 30;
}

Pet::Pet(int du,dottore_ref dr,paziente_ref pr):Esame(dr,pr){
	this->durata = du;
}

void Pet::setDurata(int d) {
	this->durata = d;
}

int Pet::getDurata() {
	return durata;
}


void Pet::stampa(){
	cout<<"ID esame PET: "<<this->getIdEsame()<<endl;
	cout<<"Durata prevista: "<<this->durata<<endl;
	cout<<"Eseguito dal dottore: "<<endl;
	this->getDott()->stampa();
	cout<<"Paziente: "<<endl;
	this->getPaz()->stampa();
	cout<<endl<<endl;
}


Pet::~Pet() {
	cout<<"distruggo PET"<<endl;

}

