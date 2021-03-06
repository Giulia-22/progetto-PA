
#ifndef UTENTI_DOTTORE_H_
#define UTENTI_DOTTORE_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Utenti/Persona.h"

using namespace std;

static int ID_dott_count = 0;

class Dottore : public Persona {
public:
	int ID_dott = ID_dott_count;
	string specializzazione = "";
	friend class Metodi;
protected:
	Dottore();
	Dottore(Dottore*);
	Dottore(int, string, string, string, string);
	void setSpecializzazione(string);
public:
	string getSpecializzazione();
	int getIdDott();
	virtual void stampa();
	virtual ~Dottore();
};

typedef shared_ptr<Dottore> dottore_ref;

#endif /* UTENTI_DOTTORE_H_ */
