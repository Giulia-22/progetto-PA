#include <iostream>
#include <vector>
#include <memory>

#include "Funzionalita/Metodi.h"
#include "Utenti/Persona.h"

using namespace std;

int main() {
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

	return 0;
}
