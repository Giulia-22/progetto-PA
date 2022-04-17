
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

using namespace std;

class Metodi {
private:
	time_t data = time(0);
	tm* now = localtime(&data);
	int annocorrente = now->tm_year+1900;
	vector<paziente_ref> lista_pazienti;
	vector<dottore_ref> lista_dottori;
private:
	void caricadati();
	bool ctrl_paz(string);
	bool ctrl_dott(string);
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
	int getYear();
	virtual ~Metodi();
private:
	paziente_ref creaPaziente();
	paziente_ref creaPaziente(int, string, string, string, string);
	dottore_ref creaDottore();
	dottore_ref creaDottore(int, string, string, string, string);

};

#endif /* METODI_H_ */
