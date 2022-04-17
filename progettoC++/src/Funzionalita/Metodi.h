
#ifndef METODI_H_
#define METODI_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "../Utenti/Persona.h"
#include "../Utenti/Paziente.h"
#include "../Utenti/Dottore.h"
#include "../Visite/Esame.h"

using namespace std;

class Metodi {
private:
	time_t data = time(0);
	tm* now = localtime(&data);
	int annocorrente = now->tm_year+1900;
	vector<paziente_ref> lista_pazienti;
	vector<dottore_ref> lista_dottori;
	vector<esame_ref> lista_esami;
private:
	void caricadati();
	bool ctrl_paz(string);
	bool ctrl_dott(string);
	paziente_ref ctrl_paz(int);
	dottore_ref ctrl_dott(int);
public:
	Metodi();
	// paziente
	void inserisciPaziente();
	void stampaElenco_paz();
	void ordinaElenco_ID_paz();
	void ordinaElenco_Categoria_paz();
	// dottore
	void inserisciDottore();
	void stampaElenco_dott();
	void ordinaElenco_ID_dott();
	void ordinaElenco_Specializzazione_dott();
	// esame
	void inserisciEsame();
	virtual void stampaElenco_esami();// TODO
	void stampaEsami_ID_dott();// TODO
	void stampaEsami_ID_paz();// TODO


	int getYear();
	virtual ~Metodi();
private:
	paziente_ref creaPaziente();
	paziente_ref creaPaziente(Paziente*);
	paziente_ref creaPaziente(int, string, string, string, string);
	dottore_ref creaDottore();
	dottore_ref creaDottore(Dottore*);
	dottore_ref creaDottore(int, string, string, string, string);
	esame_ref creaEsame();
	esame_ref creaEsame(int, dottore_ref, paziente_ref);

};

#endif /* METODI_H_ */
