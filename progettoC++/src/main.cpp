#include <iostream>
#include <vector>
#include <memory>

#include "Funzionalita/Metodi.h"
//#include "Utenti/Persona.h"
//#include "Utenti/Paziente.h"

using namespace std;

int main() {
/*
	Persona* p1 = new Persona(1999, "1234567890udtqq", "1", "A");
	Persona* p2 = new Persona(1999, "1234567890udtqq", "2", "A");
	Persona* p3 = new Persona(1999, "1234567890udtqq", "3", "A");
	Persona* p4 = new Persona(1999, "1234567890udtqq", "4", "A");
	vector<Persona> vp1;
	vp1.push_back(p1);
	vp1.push_back(p2);
	vp1.push_back(p3);
	vp1.push_back(p4);
	Metodi *m = new Metodi;
	persona_ref puni = m->inserisciPersona(1999, "1234567890udtqq", "5", "A");
	m->stampaElenco(vp1);
	vp1.push_back(puni.get());
	m->stampaElenco(vp1);
	puni->stampa();
	*/
	/*

	Metodi *m = new Metodi;
	paziente_ref pazuni = m->inserisciPaziente();
	paziente_ref pazuni2 = m->inserisciPaziente(1999, "1234567890udtqq", "1", "A","a1","1");
	pazuni->stampa();
	pazuni2->stampa();

	cout<<m->getYear()<<endl;
*/
	/*
	Paziente* p1 = new Paziente(1925,"codice1","nome1","cognome1","categ1");
	Paziente* p2 = new Paziente(1925,"codice2","nome2","cognome2","categ1");
	Paziente* p3 = new Paziente(1925,"codice3","nome3","cognome3","categ1");

	p1->stampa();
	p2->stampa();
	p3->stampa();
	*/
	char scelta;
	Metodi *m = new Metodi;
	do{
		cout<<"Benvenuto nel menu"<<endl;
		cout<<"a) azione 1 "<<endl;
		cout<<"b) azione 2 "<<endl;
		cout<<"c) azione 3 "<<endl;
		cout<<"0) TERMINA "<<endl;
		cin>>scelta;
		switch(scelta){
		case 'a':
			//TODO
			cout<<m->getYear()<<endl;
			break;
		case 'b':
			//TODO
			cout<<"2"<<endl;
			break;
		case 'c':
			//TODO
			cout<<"3"<<endl;
			break;
		case '0':
			//TODO
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
