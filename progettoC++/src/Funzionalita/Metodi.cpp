
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
	// Esame
	lista_esami.push_back(creaEsame(50,lista_dottori[0],lista_pazienti[1]));
	lista_esami.push_back(creaEsame(60,lista_dottori[0],lista_pazienti[2]));
	lista_esami.push_back(creaEsame(90,lista_dottori[2],lista_pazienti[0]));
	lista_esami.push_back(creaEsame(20,lista_dottori[2],lista_pazienti[0]));
	lista_esami.push_back(creaEsame(15,lista_dottori[0],lista_pazienti[0]));

}

//PAZIENTE
// Costruttore con passaggio parametri
paziente_ref Metodi::creaPaziente(int an, string cod, string name, string surname, string cat){
	paziente_ref p (new Paziente(an,cod,name,surname,cat));
	return p;
}
// Costruttore con passaggio puntatore
paziente_ref Metodi::creaPaziente(Paziente* pazref){
	paziente_ref p (new Paziente(pazref));
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
		/*
		cout<<"Nome: "<<i->get()->getNome()<<endl;
		cout<<"Cognome: "<<i->get()->getCognome()<<endl;
		cout<<"Anno di nascita: "<<i->get()->getAnnonascita()<<endl;
		cout<<"Codice fiscale: "<<i->get()->getCf()<<endl;
		cout<<"ID: "<<i->get()->getIdPaz()<<endl;
		cout<<"Categoria: "<<i->get()->getCategoria()<<endl<<endl;
		*/
		i->get()->stampa();
	}
}

void Metodi::ordinaElenco_Categoria_paz(){
	sort(lista_pazienti.begin(), lista_pazienti.end(), compareByCategoria);
	stampaElenco_paz();
}

void Metodi::ordinaElenco_ID_paz(){
	sort(lista_pazienti.begin(), lista_pazienti.end(), comparePazByID);
	stampaElenco_paz();
}

//DOTTORE
// Costruttore con passaggio parametri
dottore_ref Metodi::creaDottore(int an, string cod, string name, string surname, string spe){
	dottore_ref d (new Dottore(an,cod,name,surname,spe));
	return d;
}
// Costruttore con passaggio puntatore
dottore_ref Metodi::creaDottore(Dottore* dottref){
	dottore_ref d (new Dottore(dottref));
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
		/*
		cout<<"Nome: "<<i->get()->getNome()<<endl;
		cout<<"Cognome: "<<i->get()->getCognome()<<endl;
		cout<<"Anno di nascita: "<<i->get()->getAnnonascita()<<endl;
		cout<<"Codice fiscale: "<<i->get()->getCf()<<endl;
		cout<<"ID: "<<i->get()->getIdDott()<<endl;
		cout<<"Specializzazione: "<<i->get()->getSpecializzazione()<<endl<<endl;
		*/
		i->get()->stampa();
	}
}

void Metodi::ordinaElenco_Specializzazione_dott(){
	sort(lista_dottori.begin(), lista_dottori.end(), compareBySpecializzazione);
	stampaElenco_dott();
}

void Metodi::ordinaElenco_ID_dott(){
	sort(lista_dottori.begin(), lista_dottori.end(), compareDottByID);
	stampaElenco_dott();
}

// ESAMI
// Costruttore con passaggio parametri
esame_ref Metodi::creaEsame(int du, dottore_ref dr, paziente_ref pr){
	esame_ref es (new Esame(du,dr,pr));
	return es;
}
// Costruttore con parametri chiesti utente
esame_ref Metodi::creaEsame(){
	int du;
	int temp = 0;
	int pos_dott = -1;
	int pos_paz = -1;
	dottore_ref dr;
	paziente_ref pr;
	do{
		cout<<"Inserisci durata esame: ";
		cin>>du;
	} while(du<0);
	do{
		cout<<"Inserire ID dottore: ";
		cin>>temp;
		pos_dott = ctrl_dott(temp);
	} while(pos_dott == -1);
	dr = lista_dottori[pos_dott];
	do{
		cout<<"Inserire ID paziente: ";
		cin>>temp;
		pos_paz = ctrl_paz(temp);
	} while(pos_paz == -1);
	pr = lista_pazienti[pos_paz];
	esame_ref e (creaEsame(du,dr,pr));
	return e;

}

int Metodi::ctrl_dott(int id_dott){
	int index = 0;
	for(vector<dottore_ref>::iterator i = lista_dottori.begin(); i != lista_dottori.end(); ++i){
		if(i->get()->getIdDott() == id_dott){
			return index;
		}
		index++;
	}
	cout<<"Dottore non presente nel sistema! "<<endl;
	return -1;
}

int Metodi::ctrl_paz(int id_paz){
	int index = 0;
	for(vector<paziente_ref>::iterator i = lista_pazienti.begin(); i != lista_pazienti.end(); ++i){
		if(i->get()->getIdPaz() == id_paz){
			return index;
		}
		index++;
	}
	cout<<"Paziente non presente nel sistema! "<<endl;
	return -1;
}

void Metodi::inserisciEsame(){
	lista_esami.push_back(creaEsame());
}

void Metodi::stampaElenco_esami(){
	for(vector<esame_ref>::iterator i = lista_esami.begin(); i != lista_esami.end(); ++i){
		i->get()->stampa();
	}
}

void Metodi::stampaEsami_ID_dott(){
	int id_c = -1;
	cout<<"Inserisci l'ID del dottore da cercare: ";
	cin>>id_c;
	cerca_dott(id_c);
}

void Metodi::cerca_dott(int id_dott){
	bool trovato = false;
	for(vector<esame_ref>::iterator i = lista_esami.begin(); i != lista_esami.end(); ++i){
		if(i->get()->d->getIdDott() == id_dott){
			i->get()->stampa();
			trovato = true;
		}
	}
	if(!(trovato))
		cout<<"Dottore non presente nel sistema! "<<endl;
}

void Metodi::stampaEsami_ID_paz(){
	int id_c = -1;
	cout<<"Inserisci l'ID del paziente da cercare: ";
	cin>>id_c;
	cerca_paz(id_c);
}

void Metodi::cerca_paz(int id_paz){
	bool trovato = false;
	for(vector<esame_ref>::iterator i = lista_esami.begin(); i != lista_esami.end(); ++i){
		if(i->get()->p->getIdPaz() == id_paz){
			i->get()->stampa();
			trovato = true;
		}
	}
	if(!(trovato))
		cout<<"Paziente non presente nel sistema! "<<endl;
}

int Metodi::getYear(){
	return this->annocorrente;
}

Metodi::~Metodi() {
}
