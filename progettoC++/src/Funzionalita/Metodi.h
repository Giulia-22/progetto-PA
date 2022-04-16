
#ifndef METODI_H_
#define METODI_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "../Utenti/Persona.h"
#include "../Utenti/Paziente.h"

using namespace std;

class Metodi {
private:
	time_t data = time(0);
	tm* now = localtime(&data);
	int annocorrente = now->tm_year+1900;
	vector<paziente_ref> lista_pazienti;
private:
	void caricadati();
public:
	Metodi();
	persona_ref inserisciPersona();
	persona_ref inserisciPersona(int, string, string, string);
	paziente_ref inserisciPaziente();
	paziente_ref inserisciPaziente(int, string, string, string, string);
	// TODO stesso con dottore
	void stampaElenco_paz(); // da fare per le 2
	void ordinaElenco_ID_paz(); // da fare per le 2
	void ordinaElenco_Cognome_paz(); // da fare per le 2
	int getYear();
	virtual ~Metodi();

};

#endif /* METODI_H_ */
