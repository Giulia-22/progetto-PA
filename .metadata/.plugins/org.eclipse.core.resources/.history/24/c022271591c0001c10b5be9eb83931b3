#include <iostream>
#include <vector>
#include <memory>

#include "Funzionalita/Metodi.h"
//#include "Utenti/Persona.h"
//#include "Utenti/Paziente.h"
#include "Visite/Pet.h"

using namespace std;

int main() {

	char scelta;
	unique_ptr<Metodi> m (new Metodi());
	do{
		cout<<endl;
		cout<<"***** Benvenuto nel menu *****"<<endl;
		cout<<"Digita la lettera corrispondente all'azione che desideri eseguire. "<<endl;
		cout<<"Digita 0 se desideri terminare il programma."<<endl;
		cout<<"a) Inserimento di un nuovo paziente nel sistema "<<endl;
		cout<<"b) Visualizzazione di tutti i pazienti del sistema "<<endl;
		cout<<"c) Ordinamento dei pazienti per categoria "<<endl;
		cout<<"d) Ordinamento dei pazienti per ID "<<endl;
		cout<<"e) Inserimento di un nuovo dottore nel sistema "<<endl;
		cout<<"f) Visualizzazione di tutti i dottori del sistema "<<endl;
		cout<<"g) Ordinamento dei dottori per specializzazione "<<endl;
		cout<<"h) Ordinamento dei dottori per ID "<<endl;
		cout<<"i) Inserimento di un nuovo esame nel sistema "<<endl;
		cout<<"j) Visualizzazione di tutti gli esami del sistema "<<endl;
		cout<<"k) Visualizzazione di tutti gli esami eseguiti da un dottore "<<endl;
		cout<<"l) Visualizzazione di tutti gli esami effettuati da un paziente "<<endl;
		cout<<"m) Inserimento di un nuovo esame PET nel sistema "<<endl;
		cout<<"n) Visualizzazione di tutti gli esami PET del sistema "<<endl;
		cout<<"o) Visualizzazione di tutti gli esami PET brevi "<<endl;
		cout<<"p) Inserimento di un nuovo esame MR nel sistema "<<endl;
		cout<<"q) Visualizzazione di tutti gli esami MR del sistema "<<endl;
		cout<<"r) Visualizzazione di tutti gli esami MR forti "<<endl;
		cout<<"s) Inserimento di un nuovo esame PET/MR nel sistema "<<endl;
		cout<<"t) Visualizzazione di tutti gli esami PET/MR del sistema "<<endl;
		cout<<"u) Visualizzazione di tutti gli esami PET/MR forti e brevi del sistema "<<endl;
		cout<<"0) TERMINA "<<endl<<endl;
		cout<<"La tua scelta: ";
		cin>>scelta;
		switch(scelta){
		case 'a':
			m->inserisciPaziente();
			break;
		case 'b':
			m->stampaElenco_paz();
			break;
		case 'c':
			m->ordinaElenco_Categoria_paz();
			break;
		case 'd':
			m->ordinaElenco_ID_paz();
			break;
		case 'e':
			m->inserisciDottore();
			break;
		case 'f':
			m->stampaElenco_dott();
			break;
		case 'g':
			m->ordinaElenco_Specializzazione_dott();
			break;
		case 'h':
			m->ordinaElenco_ID_dott();
			break;
		case 'i':
			m->inserisciEsame();
			break;
		case 'j':
			m->stampaElenco_esami();
			break;
		case 'k':
			m->stampaEsami_ID_dott();
			break;
		case 'l':
			m->stampaEsami_ID_paz();
			break;
		case 'm':
			m->inserisciEsamePet();
			break;
		case 'n':
			m->stampaElenco_esami_pet();
			break;
		case 'o':
			m->stampaEsami_PET_corti();
			break;
		case 'p':
			m->inserisciEsameMr();
			break;
		case 'q':
			m->stampaElenco_esami_mr();
			break;
		case 'r':
			m->stampaEsami_MR_forti();
			break;
		case 's':
			m->inserisciEsamePetMr();
			break;
		case 't':
			m->stampaElenco_esami_pet_mr();
			break;
		case 'u':
			m->stampaEsami_PETMR_corti_forti();
			break;
		case '0':
			cout<<endl<<"Arrivederci!"<<endl;
			break;
		default:
			cout<<"scelta non valida"<<endl;
			break;
		}
	} while(scelta != '0');

	return 0;
}
