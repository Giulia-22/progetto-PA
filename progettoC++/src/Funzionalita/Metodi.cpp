
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
	// Dottore
	lista_dottori.push_back(creaDottore(1986,"codFiscdottA","Giuseppe","Verdi","cardiologia"));
	lista_dottori.push_back(creaDottore(1989,"codFiscdottB","Antonio","Vivaldi","chirurgia"));
	lista_dottori.push_back(creaDottore(1963,"codFiscdottC","Mario","Blu","fisioterapia"));
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
	sort(lista_pazienti.begin(), lista_pazienti.end(), comparePazByID);
}

//DOTTORE
// Costruttore con passaggio parametri
dottore_ref Metodi::creaDottore(int an, string cod, string name, string surname, string spe){
	dottore_ref d (new Dottore(an,cod,name,surname,spe));
	return d;
}
// Costruttore con parametri chiesti utente
dottore_ref Metodi::creaDottore(){
	int an;
	bool giaIns = false;
	string cod, name, surname, spe;
	do{
		cout<<"Inserisci anno di nascita: ";
		cin>>an;
	} while(an<1900 || an>annocorrente);
	do{
		cout<<"Inserire codice fiscale: ";
		cin>>cod;
		giaIns = ctrl_dott(cod);
	} while(giaIns);
	cout<<"Inserire nome: ";
	cin>>name;
	cout<<"Inserire cognome: ";
	cin>>surname;
	cout<<"Inserire specializzazione: ";
	cin>>spe;
	dottore_ref d (creaDottore(an,cod,name,surname,spe));
	return d;
}

bool Metodi::ctrl_dott(string codice){
	for(vector<dottore_ref>::iterator i = lista_dottori.begin(); i != lista_dottori.end(); ++i){
		if(codice.compare(i->get()->getCf()) == 0){
			cout<<"Utente gia' presente nel sistema! ";
			return true;
		}
	}
	return false;
}

void Metodi::inserisciDottore(){
	lista_dottori.push_back(creaDottore());
}

void Metodi::stampaElenco_dott(){
	for(vector<dottore_ref>::iterator i = lista_dottori.begin(); i != lista_dottori.end(); ++i){
		cout<<"Nome: "<<i->get()->getNome()<<endl;
		cout<<"Cognome: "<<i->get()->getCognome()<<endl;
		cout<<"Anno di nascita: "<<i->get()->getAnnonascita()<<endl;
		cout<<"Codice fiscale: "<<i->get()->getCf()<<endl;
		cout<<"ID: "<<i->get()->getIdDott()<<endl;
		cout<<"Specializzazione: "<<i->get()->getSpecializzazione()<<endl<<endl;
	}
}

void Metodi::ordinaElenco_Specializzazione_dott(){
	sort(lista_dottori.begin(), lista_dottori.end(), compareBySpecializzazione);
}

void Metodi::ordinaElenco_ID_dott(){
	sort(lista_dottori.begin(), lista_dottori.end(), compareDottByID);
}






int Metodi::getYear(){
	return this->annocorrente;
}

Metodi::~Metodi() {
}
