
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
	dottore_ref d ;
	paziente_ref p;
	friend class Metodi;

	int getIdEsame();
	dottore_ref getDott();
	paziente_ref getPaz();
	virtual void stampa();
	virtual ~Esame();

protected:
	Esame();
	Esame(dottore_ref,paziente_ref);
	void setDott(dottore_ref);
	void setPaz(paziente_ref);
};

typedef shared_ptr<Esame> esame_ref;

#endif /* VISITE_ESAME_H_ */
