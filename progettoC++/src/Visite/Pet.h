
#ifndef VISITE_PET_H_
#define VISITE_PET_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Visite/Esame.h"

using namespace std;

class Pet : virtual public Esame {
public:
	int durata = 30;
	friend class Metodi;
protected:
	Pet();
	Pet(int,dottore_ref,paziente_ref);
	void setDurata(int);
public:
	virtual int getDurata();
	virtual void stampa();
	virtual ~Pet();
};

typedef shared_ptr<Pet> pet_ref;

#endif /* VISITE_PET_H_ */
