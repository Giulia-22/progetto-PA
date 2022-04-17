
#ifndef UTENTI_PAZIENTE_H_
#define UTENTI_PAZIENTE_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Utenti/Persona.h"

using namespace std;

static int ID_paz_count = 0;

class Paziente : public Persona {
public:
	int ID_paz = ID_paz_count;
	string categoria = "";
	friend class Metodi;
protected:
	Paziente();
	Paziente(Paziente*);
	Paziente(int, string, string, string, string);
	void setCategoria(string);
public:
	string getCategoria();
	int getIdPaz();
	virtual void stampa();
	virtual ~Paziente();
};

typedef shared_ptr<Paziente> paziente_ref;

#endif /* UTENTI_PAZIENTE_H_ */
