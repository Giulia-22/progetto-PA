#include <iostream>
#include <vector>
#include <memory>

#include "Funzionalita/Metodi.h"

using namespace std;

int main() {
	char scelta1,scelta2;
	unique_ptr<Metodi> m (Metodi::getOggetto());
	do{
		cout<<endl;
		cout<<"***** Benvenuto nel menu *****"<<endl;
		cout<<"Digita la lettera corrispondente all'azione che desideri eseguire. "<<endl;
		cout<<"Digita 0 se desideri terminare il programma."<<endl;
		cout<<"a) Operazioni su pazienti "<<endl;
		cout<<"b) Operazioni su dottori "<<endl;
		cout<<"c) Operazioni su esami "<<endl;
		cout<<"0) TERMINA "<<endl<<endl;
		cout<<"La tua scelta: ";
		cin>>scelta1;
		switch(scelta1){
		// Paziente
		case 'a':
			cout<<"Digita la lettera corrispondente all'azione che desideri eseguire. "<<endl;
			cout<<"Digita 0 se desideri tornare al menu principale."<<endl;
			cout<<"a) Inserimento di un nuovo paziente nel sistema "<<endl;
			cout<<"b) Visualizzazione di tutti i pazienti del sistema "<<endl;
			cout<<"c) Ordinamento dei pazienti per categoria "<<endl;
			cout<<"d) Ordinamento dei pazienti per ID "<<endl;
			cout<<"0) Torna al MENU PRINCIPALE "<<endl<<endl;
			cout<<"La tua scelta: ";
			cin>>scelta2;
			switch(scelta2){
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
			case '0':
				break;
			default:
				cout<<"scelta non valida"<<endl;
				break;
			}
			break;
		// Dottore
		case 'b':
			cout<<"Digita la lettera corrispondente all'azione che desideri eseguire. "<<endl;
			cout<<"Digita 0 se desideri tornare al menu principale."<<endl;
			cout<<"a) Inserimento di un nuovo dottore nel sistema "<<endl;
			cout<<"b) Visualizzazione di tutti i dottori del sistema "<<endl;
			cout<<"c) Ordinamento dei dottori per specializzazione "<<endl;
			cout<<"d) Ordinamento dei dottori per ID "<<endl;
			cout<<"0) Torna al MENU PRINCIPALE "<<endl<<endl;
			cout<<"La tua scelta: ";
			cin>>scelta2;
			switch(scelta2){
			case 'a':
				m->inserisciDottore();
				break;
			case 'b':
				m->stampaElenco_dott();
				break;
			case 'c':
				m->ordinaElenco_Specializzazione_dott();
				break;
			case 'd':
				m->ordinaElenco_ID_dott();
				break;
			case '0':
				break;
			default:
				cout<<"scelta non valida"<<endl;
				break;
			}
			break;
			// Esame
			case 'c':
				cout<<"Digita la lettera corrispondente all'azione che desideri eseguire. "<<endl;
				cout<<"Digita 0 se desideri tornare al menu principale."<<endl;
				cout<<"a) Inserimento di un nuovo esame nel sistema "<<endl;
				cout<<"b) Visualizzazione di tutti gli esami del sistema "<<endl;
				cout<<"c) Visualizzazione di tutti gli esami eseguiti da un dottore "<<endl;
				cout<<"d) Visualizzazione di tutti gli esami effettuati da un paziente "<<endl;
				cout<<"e) Inserimento di un nuovo esame PET nel sistema "<<endl;
				cout<<"f) Visualizzazione di tutti gli esami PET del sistema "<<endl;
				cout<<"g) Visualizzazione di tutti gli esami PET brevi "<<endl;
				cout<<"h) Inserimento di un nuovo esame MR nel sistema "<<endl;
				cout<<"i) Visualizzazione di tutti gli esami MR del sistema "<<endl;
				cout<<"l) Visualizzazione di tutti gli esami MR forti "<<endl;
				cout<<"m) Inserimento di un nuovo esame PET/MR nel sistema "<<endl;
				cout<<"n) Visualizzazione di tutti gli esami PET/MR del sistema "<<endl;
				cout<<"o) Visualizzazione di tutti gli esami PET/MR forti e brevi del sistema "<<endl;
				cout<<"p) Eliminazione di un esame PET/MR del sistema "<<endl;
				cout<<"0) Torna al MENU PRINCIPALE "<<endl<<endl;
				cout<<"La tua scelta: ";
				cin>>scelta2;
				switch(scelta2){
				case 'a':
					m->inserisciEsame();
					break;
				case 'b':
					m->stampaElenco_esami();
					break;
				case 'c':
					m->stampaEsami_ID_dott();
					break;
				case 'd':
					m->stampaEsami_ID_paz();
					break;
				case 'e':
					m->inserisciEsamePet();
					break;
				case 'f':
					m->stampaElenco_esami_pet();
					break;
				case 'g':
					m->stampaEsami_PET_corti();
					break;
				case 'h':
					m->inserisciEsameMr();
					break;
				case 'i':
					m->stampaElenco_esami_mr();
					break;
				case 'l':
					m->stampaEsami_MR_forti();
					break;
				case 'm':
					m->inserisciEsamePetMr();
					break;
				case 'n':
					m->stampaElenco_esami_pet_mr();
					break;
				case 'o':
					m->stampaEsami_PETMR_corti_forti();
					break;
				case 'p':
					m->eliminaEsame_PETMR();
					break;
				case '0':
					break;
				default:
					cout<<"scelta non valida"<<endl;
					break;
				}
				break;
				case '0':
					cout<<endl<<"Arrivederci!"<<endl;
					break;
				default:
					cout<<"scelta non valida"<<endl;
					break;
		}
	} while(scelta1 != '0');

	return 0;
}
