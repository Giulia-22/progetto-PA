
#include "PetMr.h"

PetMr::PetMr() {

}

PetMr::PetMr(int du_pet,int du_mr,int intensit,dottore_ref dottp,dottore_ref dottm,paziente_ref paz):Esame(dottp,paz),Pet(du_pet,dottp,paz),Mr(du_mr,intensit,dottm,paz) {

}


int PetMr::getDurata(){
	return Pet::durata+Mr::durata;
}

int PetMr::getDurataPet(){
	return Pet::durata;
}

int PetMr::getDurataMr(){
	return Mr::durata;
}

void PetMr::stampa(){
	cout<<"ID esame PET/MR: "<<this->getIdEsame()<<endl;
	cout<<"Durata totale prevista: "<<this->getDurata()<<endl;
	cout<<"INFORMAZIONI PET: "<<endl;
	this->Pet::stampa();
	cout<<"INFORMAZIONI MR: "<<endl;
	this->Mr::stampa();
}

PetMr::~PetMr() {

}
