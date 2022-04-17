
#include "../Funzionalita/Metodi.h"
#include "Comparatori.h"

Metodi::Metodi(){
	caricadati();
}

void Metodi::caricadati(){
	// Paziente
	lista_pazienti.push_back(creaPaziente(1956,"codFiscmr","Mario","Rossi","1"));
	lista_pazienti.push_back(creaPaziente(1965,"codFiscmv","Mario","Verdi","2"));
	lista_pazienti.push_back(creaPaziente(1932,"codFiscmb","Mario","Bianchi","1"));
	// Stampe e ordinamenti vari
}

//PAZIENTE
// Costruttore con passaggio parametri
paziente_ref Metodi::creaPaziente(int an, string cod, string name, string surname, string cat){
	paziente_ref p (new Paziente(an,cod,name,surname,cat));
	return p;
}
// Costruttore con parametri chiesti utente
paziente_ref Metodi::creaPaziente(){
	int an;
	bool giaIns = false;
	string cod, name, surname, cat;
	do{
		cout<<"Inserisci anno di nascita: ";
		cin>>an;
	} while(an<1900 || an>annocorrente);
	do{
		cout<<"Inserire codice fiscale: ";
		cin>>cod;
		giaIns = ctrl_paz(cod);
	} while(giaIns);
	cout<<"Inserire nome: ";
	cin>>name;
	cout<<"Inserire cognome: ";
	cin>>surname;
	cout<<"Inserire categoria: ";
	cin>>cat;
	paziente_ref p (creaPaziente(an,cod,name,surname,cat));
	return p;
}

bool Metodi::ctrl_paz(string codice){
	for(vector<paziente_ref>::iterator i = lista_pazienti.begin(); i != lista_pazienti.end(); ++i){
		if(codice.compare(i->get()->getCf()) == 0){
			cout<<"Utente gia' presente nel sistema! ";
			return true;
		}
	}
	return false;
}

void Metodi::inserisciPaziente(){
	lista_pazienti.push_back(creaPaziente());
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

void Metodi::ordinaElenco_Categoria_paz(){
	sort(lista_pazienti.begin(), lista_pazienti.end(), compareByCategoria);
}

void Metodi::ordinaElenco_ID_paz(){
	sort(lista_pazienti.begin(), lista_pazienti.end(), compareByID);
}








int Metodi::getYear(){
	return this->annocorrente;
}

Metodi::~Metodi() {
}
