
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
	// TODO stesso con dottore
	void inserisciPaziente();
	void stampaElenco_paz(); // da fare per le 2
	void ordinaElenco_ID_paz(); // da fare per le 2
	void ordinaElenco_Categoria_paz(); // da fare per le 2
	int getYear();
	virtual ~Metodi();
private:
	persona_ref creaPersona();
	persona_ref creaPersona(int, string, string, string);
	paziente_ref creaPaziente();
	paziente_ref creaPaziente(int, string, string, string, string);

};

#endif /* METODI_H_ */
