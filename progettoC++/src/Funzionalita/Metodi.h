
#ifndef METODI_H_
#define METODI_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Utenti/Persona.h"

using namespace std;

class Metodi {
public:
	Metodi();
	void stampaElenco(vector<Persona> p);
	persona_ref inserisciPersona(int, string, string, string);
	virtual ~Metodi();

};

#endif /* METODI_H_ */
