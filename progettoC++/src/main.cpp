#include <iostream>
#include <vector>
#include <memory>

#include "Funzionalita/Metodi.h"
//#include "Utenti/Persona.h"
//#include "Utenti/Paziente.h"

using namespace std;

int main() {
	char scelta;
	Metodi *m = new Metodi;
	do{
		cout<<endl;
		cout<<"***** Benvenuto nel menu *****"<<endl;
		cout<<"Digita la lettera corrispondente all'azione che desideri eseguire. "<<endl;
		cout<<"Digita 0 se desideri terminare il programma."<<endl;
		cout<<"a) Inserimento di un nuovo paziente nel sistema "<<endl;
		cout<<"b) Visualizzazione di tutti i pazienti del sistema "<<endl;
		cout<<"c) Ordinamento dei pazienti per categoria "<<endl;
		cout<<"d) Ordinamento dei pazienti per ID "<<endl;
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
			//TODO
			m->ordinaElenco_Categoria_paz();
			break;
		case 'd':
			m->ordinaElenco_ID_paz();
			break;
		case '0':
			cout<<"Arrivederci"<<endl;
			break;
		default:
			//TODO
			cout<<"scelta non valida"<<endl;
			break;
		}
	} while(scelta != '0');

	return 0;
}
