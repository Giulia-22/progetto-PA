
#include "../Funzionalita/Metodi.h"
#include "Comparatori.h"

Metodi::Metodi(){
	caricadati();
}

void Metodi::caricadati(){
	// Paziente
	lista_pazienti.push_back(inserisciPaziente(1956,"codFiscmr","Mario","Rossi","1"));
	lista_pazienti.push_back(inserisciPaziente(1965,"codFiscmv","Mario","Verdi","2"));
	lista_pazienti.push_back(inserisciPaziente(1932,"codFiscmb","Mario","Bianchi","1"));
	// Stampe e ordinamenti vari
	stampaElenco_paz();
	ordinaElenco_Cognome_paz();
	stampaElenco_paz();
	ordinaElenco_ID_paz();
	stampaElenco_paz();
}

// PERSONA
// Costruttore con parametri chiesti utente
persona_ref Metodi::inserisciPersona(){
	int an;
	string cod, name, surname;
	do{
		cout<<"Inserisci anno di nascita: ";
		cin>>an;
	} while(an<1900 || an>annocorrente);
	cout<<"Inserire codice fiscale: ";
	cin>>cod;
	cout<<"Inserire nome: ";
	cin>>name;
	cout<<"Inserire cognome: ";
	cin>>surname;
	persona_ref p (new Persona(an,cod,name,surname));
	return p;
}
// Costruttore con passaggio parametri
persona_ref Metodi::inserisciPersona(int an, string cod, string name, string surname){
	persona_ref p (new Persona(an,cod,name,surname));
	return p;
}

//PAZIENTE
// Costruttore con parametri chiesti utente
paziente_ref Metodi::inserisciPaziente(){
	int an;
	string cod, name, surname, cat;
	do{
		cout<<"Inserisci anno di nascita: ";
		cin>>an;
	} while(an<1900 || an>annocorrente);
	cout<<"Inserire codice fiscale: ";
	cin>>cod;
	cout<<"Inserire nome: ";
	cin>>name;
	cout<<"Inserire cognome: ";
	cin>>surname;
	cout<<"Inserire codice fiscale: ";
	cin>>cod;
	cout<<"Inserire categoria: ";
	cin>>cat;
	paziente_ref p (new Paziente(an,cod,name,surname,cat));
	return p;
}

// Costruttore con passaggio parametri
paziente_ref Metodi::inserisciPaziente(int an, string cod, string name, string surname, string cat){
	paziente_ref p (new Paziente(an,cod,name,surname,cat));
	return p;
}

void Metodi::stampaElenco_paz(){
	for(vector<paziente_ref>::iterator i = lista_pazienti.begin(); i != lista_pazienti.end(); ++i){
		cout<<"Nome: "<<i->get()->getNome()<<endl;
		cout<<"Cognome: "<<i->get()->getCognome()<<endl;
		cout<<"Anno di nascita: "<<i->get()->getAnnonascita()<<endl;
		cout<<"Codice fiscale: "<<i->get()->getCf()<<endl;
		cout<<"ID: "<<i->get()->getIdPaz()<<endl;
		cout<<"Categoria: "<<i->get()->getCategoria()<<endl<<endl;
	}
}

void Metodi::ordinaElenco_Cognome_paz(){
	sort(lista_pazienti.begin(), lista_pazienti.end(), compareByCognome);
}

void Metodi::ordinaElenco_ID_paz(){
	sort(lista_pazienti.begin(), lista_pazienti.end(), compareByID);
}

int Metodi::getYear(){
	return this->annocorrente;
}

Metodi::~Metodi() {
}