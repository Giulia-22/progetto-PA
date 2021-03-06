
#include "../Funzionalita/Metodi.h"
#include "Comparatori.h"

Metodi::Metodi(){
	caricadati();
}

Metodi* Metodi::mOgg = NULL;

Metodi* Metodi::getOggetto(){
	if(mOgg == NULL)
		mOgg = new Metodi();
	return mOgg;
}

void Metodi::caricadati(){
	// Paziente
	lista_pazienti.push_back(creaPaziente(1956,"codFiscmr","Mario","Rossi",adulto));
	lista_pazienti.push_back(creaPaziente(1965,"codFiscmv","Mario","Verdi",bambino));
	lista_pazienti.push_back(creaPaziente(1932,"codFiscmb","Mario","Bianchi",anziano));
	// Dottore
	lista_dottori.push_back(creaDottore(1986,"codFiscdottA","Giuseppe","Verdi","cardiologia"));
	lista_dottori.push_back(creaDottore(1989,"codFiscdottB","Antonio","Vivaldi","chirurgia"));
	lista_dottori.push_back(creaDottore(1963,"codFiscdottC","Mario","Blu","fisioterapia"));
	// Esame
	lista_esami.push_back(creaEsame(lista_dottori[0],lista_pazienti[1]));
	lista_esami.push_back(creaEsame(lista_dottori[0],lista_pazienti[2]));
	lista_esami.push_back(creaEsame(lista_dottori[2],lista_pazienti[0]));
	lista_esami.push_back(creaEsame(lista_dottori[2],lista_pazienti[0]));
	lista_esami.push_back(creaEsame(lista_dottori[0],lista_pazienti[0]));
	// Pet
	lista_esami_pet.push_back(creaEsamePet(35,lista_dottori[0],lista_pazienti[2]));
	lista_esami_pet.push_back(creaEsamePet(40,lista_dottori[1],lista_pazienti[1]));
	lista_esami_pet.push_back(creaEsamePet(20,lista_dottori[2],lista_pazienti[1]));
	lista_esami_pet.push_back(creaEsamePet(60,lista_dottori[2],lista_pazienti[0]));
	// MR
	lista_esami_mr.push_back(creaEsameMr(15,3,lista_dottori[2],lista_pazienti[0]));
	lista_esami_mr.push_back(creaEsameMr(20,4,lista_dottori[1],lista_pazienti[1]));
	lista_esami_mr.push_back(creaEsameMr(60,2,lista_dottori[1],lista_pazienti[2]));
	lista_esami_mr.push_back(creaEsameMr(10,6,lista_dottori[0],lista_pazienti[2]));
	// PET/MR
	lista_esami_petmr.push_back(creaEsamePetMr(15,60,5,lista_dottori[2],lista_pazienti[0]));
	lista_esami_petmr.push_back(creaEsamePetMr(20,35,10,lista_dottori[2],lista_pazienti[2]));
	lista_esami_petmr.push_back(creaEsamePetMr(60,20,2,lista_dottori[0],lista_pazienti[1]));
	lista_esami_petmr.push_back(creaEsamePetMr(10,75,1,lista_dottori[0],lista_pazienti[2]));


}

//PAZIENTE
// Costruttore con passaggio parametri
paziente_ref Metodi::creaPaziente(int an, string cod, string name, string surname, category cat){
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
	string cod, name, surname;
	string cat; category ca;
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
	cout<<"Inserire categoria: "<<endl;
	cin>>cat;
	// switch non possible con string --> if-else
	if(cat.compare("bambino") == 0)
		ca = bambino;
	else if(cat.compare("adulto") == 0)
		ca = adulto;
	else if(cat.compare("anziano") == 0)
		ca = anziano;
	else
		ca = sconosciuto;

	paziente_ref p (creaPaziente(an,cod,name,surname,ca));
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
esame_ref Metodi::creaEsame(dottore_ref dr, paziente_ref pr){
	esame_ref es (new Esame(dr,pr));
	return es;
}
// Costruttore con parametri chiesti utente
esame_ref Metodi::creaEsame(){
	int temp = 0;
	int pos_dott = -1;
	int pos_paz = -1;
	dottore_ref dr;
	paziente_ref pr;
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
	esame_ref e (creaEsame(dr,pr));
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


// ESAMI ** PET **
// Costruttore con passaggio parametri
pet_ref Metodi::creaEsamePet(int dur, dottore_ref dr, paziente_ref pr){
	pet_ref es_p (new Pet(dur,dr,pr));
	return es_p;
}
// Costruttore con parametri chiesti utente
pet_ref Metodi::creaEsamePet(){
	int temp = 0;
	int dur = 30;
	int pos_dott = -1;
	int pos_paz = -1;
	dottore_ref dr;
	paziente_ref pr;
	do{
		cout<<"Inserisci durata esame: ";
		cin>>dur;
	} while(dur<0);
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
	pet_ref es_pet (creaEsamePet(dur,dr,pr));
	return es_pet;

}

void Metodi::inserisciEsamePet(){
	lista_esami_pet.push_back(creaEsamePet());
}

void Metodi::stampaElenco_esami_pet(){
	for(vector<pet_ref>::iterator i = lista_esami_pet.begin(); i != lista_esami_pet.end(); ++i){
		i->get()->stampa();
	}
}

void Metodi::stampaEsami_PET_corti(){
	int dur = 20;
	do{
		cout<<"Inserisci durata (0-40): ";
		cin>>dur;
	} while(dur<0 || dur>40);

	for(vector<pet_ref>::iterator i = lista_esami_pet.begin(); i != lista_esami_pet.end(); ++i){
		if(i->get()->durata <= dur)
			i->get()->stampa();
	}
}


// ESAMI ** MR **
// Costruttore con passaggio parametri
mr_ref Metodi::creaEsameMr(int dur, int inten, dottore_ref dr, paziente_ref pr){
	mr_ref es_m (new Mr(dur,inten,dr,pr));
	return es_m;
}
// Costruttore con parametri chiesti utente
mr_ref Metodi::creaEsameMr(){
	int temp = 0;
	int dur = 30;
	int inte = 2;
	int pos_dott = -1;
	int pos_paz = -1;
	dottore_ref dr;
	paziente_ref pr;
	do{
		cout<<"Inserisci durata esame: ";
		cin>>dur;
	} while(dur<0);
	do{
		cout<<"Inserisci intensita' esame: ";
		cin>>inte;
	} while(inte<0);
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
	mr_ref es_mr (creaEsameMr(dur,inte,dr,pr));
	return es_mr;

}

void Metodi::inserisciEsameMr(){
	lista_esami_mr.push_back(creaEsameMr());
}

void Metodi::stampaElenco_esami_mr(){
	for(vector<mr_ref>::iterator i = lista_esami_mr.begin(); i != lista_esami_mr.end(); ++i){
		i->get()->stampa();
	}
}

void Metodi::stampaEsami_MR_forti(){
	int intensity = 2;
	do{
		cout<<"Inserisci intensita' (5-10): ";
		cin>>intensity;
	} while(intensity<5 || intensity>10);

	for(vector<mr_ref>::iterator i = lista_esami_mr.begin(); i != lista_esami_mr.end(); ++i){
		if(i->get()->intensita <= intensity)
			i->get()->stampa();
	}
}

// ESAMI ** PET/MR **
// Costruttore con passaggio parametri
petmr_ref Metodi::creaEsamePetMr(int dur_p, int dur_m, int inten, dottore_ref dr, paziente_ref pr){
	petmr_ref es_pm (new PetMr(dur_p,dur_m,inten,dr,pr));
	return es_pm;
}
// Costruttore con parametri chiesti utente
petmr_ref Metodi::creaEsamePetMr(){
	int temp = 0;
	int dur_pet = 30;
	int dur_mr = 15;
	int inte = 2;
	int pos_dott = -1;
	int pos_paz = -1;
	dottore_ref dref;
	paziente_ref pr;
	do{
		cout<<"Inserisci durata esame PET: ";
		cin>>dur_pet;
	} while(dur_pet<0);
	do{
		cout<<"Inserire ID dottore: ";
		cin>>temp;
		pos_dott = ctrl_dott(temp);
	} while(pos_dott == -1);
	dref = lista_dottori[pos_dott];
	do{
		cout<<"Inserisci durata esame MR: ";
		cin>>dur_mr;
	} while(dur_mr<0);
	do{
		cout<<"Inserisci intensita' esame: ";
		cin>>inte;
	} while(inte<0);
	do{
		cout<<"Inserire ID paziente: ";
		cin>>temp;
		pos_paz = ctrl_paz(temp);
	} while(pos_paz == -1);
	pr = lista_pazienti[pos_paz];
	petmr_ref es_petmr (creaEsamePetMr(dur_pet,dur_mr,inte,dref,pr));
	return es_petmr;

}

void Metodi::inserisciEsamePetMr(){
	lista_esami_petmr.push_back(creaEsamePetMr());
}

void Metodi::stampaElenco_esami_pet_mr(){
	for(vector<petmr_ref>::iterator i = lista_esami_petmr.begin(); i != lista_esami_petmr.end(); ++i){
		i->get()->stampa();
	}
}

void Metodi::stampaEsami_PETMR_corti_forti(){
	int intensity = 2;
	int dur = 20;
	do{
		cout<<"Inserisci intensita' MR (5-10): ";
		cin>>intensity;
	} while(intensity<5 || intensity>10);
	do{
		cout<<"Inserisci durata PET (0-40): ";
		cin>>dur;
	} while(dur<0 || dur>40);
	for(vector<petmr_ref>::iterator i = lista_esami_petmr.begin(); i != lista_esami_petmr.end(); ++i){
		if(i->get()->Pet::durata <= dur && i->get()->Mr::intensita <= intensity)
			i->get()->stampa();
	}


}

void Metodi::eliminaEsame_PETMR(){
	int id_es = -1;
	bool trovato = false;
	do{
		cout<<"Inserisci ID esame: ";
		cin>>id_es;
	} while (id_es < 0);
	for(vector<petmr_ref>::iterator i = lista_esami_petmr.begin(); i != lista_esami_petmr.end(); ++i){
		if(i->get()->ID_esame == id_es){
			lista_esami_petmr.erase(i);
			trovato = true;
			break;
		}
	}
	if(!(trovato))
		cout<<"Esame non presente nel sistema! "<<endl;
}

int Metodi::getYear(){
	return this->annocorrente;
}

Metodi::~Metodi() {
	delete(now);
}
