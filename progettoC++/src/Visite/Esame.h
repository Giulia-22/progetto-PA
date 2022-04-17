
#ifndef VISITE_ESAME_H_
#define VISITE_ESAME_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Utenti/Persona.h"
#include "../Utenti/Paziente.h"
#include "../Utenti/Dottore.h"

using namespace std;

static int ID_esame_count = 0;

class Esame {
public:
	int ID_esame = ID_esame_count;
	int durata = 0;
	Dottore* d;
	Paziente* p;

	int getIdEsame();
	virtual int getDurata();
	Dottore* getDott();
	Paziente* getPaz();
	virtual void stampa();
	virtual ~Esame();

//protected:
	Esame();
	Esame(int,Dottore*,Paziente*);
	void setDurata(int);
	void setDott(dottore_ref);
	void setPaz(paziente_ref);
};

typedef unique_ptr<Esame> esame_ref;

#endif /* VISITE_ESAME_H_ */
