
#ifndef UTENTI_PAZIENTE_H_
#define UTENTI_PAZIENTE_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Utenti/Persona.h"
#include "../Utenti/Categoria.h"

using namespace std;

static int ID_paz_count = 0;

class Paziente : public Persona {
public:
	int ID_paz = ID_paz_count;
	category categoria = sconosciuto;
	friend class Metodi;
protected:
	Paziente();
	Paziente(Paziente*);
	Paziente(int, string, string, string, category);
	void setCategoria(category);
public:
	category getCategoria();
	int getIdPaz();
	virtual void stampa();
	virtual ~Paziente();
};

typedef shared_ptr<Paziente> paziente_ref;

#endif /* UTENTI_PAZIENTE_H_ */
