
#include "PetMr.h"

PetMr::PetMr() {

}

PetMr::PetMr(int du_pet,int du_mr,int intensit,dottore_ref dott,paziente_ref paz):Esame(dott,paz),Pet(du_pet,dott,paz),Mr(du_mr,intensit,dott,paz) {

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
	cout<<"***************"<<endl;
	cout<<"ID esame PET/MR: "<<this->getIdEsame()<<endl;
	cout<<"Durata totale prevista: "<<this->getDurata()<<endl<<endl;
	cout<<"INFORMAZIONI PET: "<<endl;
	this->Pet::stampa();
	cout<<"INFORMAZIONI MR: "<<endl;
	this->Mr::stampa();
}

PetMr::~PetMr() {
	cout<<"distruggo esame PET/MR"<<endl;

}

