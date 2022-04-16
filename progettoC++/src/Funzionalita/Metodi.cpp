
#include "../Funzionalita/Metodi.h"

Metodi::Metodi(){

}

void Metodi::stampaElenco(vector<Persona> p){
	for(vector<Persona>::iterator i = p.begin(); i != p.end(); ++i){
		cout<<"Nome: "<<i->getNome()<<endl;
		cout<<"Cognome: "<<i->getCognome()<<endl;
		cout<<"Anno di nascita: "<<i->getAnnonascita()<<endl;
		cout<<"Codifce fiscale: "<<i->getCf()<<endl<<endl;
	}
}

persona_ref Metodi::inserisciPersona(int year, string cod, string name, string surname){
	persona_ref p (new Persona(year,cod,name,surname));
	return p;
}

Metodi::~Metodi() {
}
