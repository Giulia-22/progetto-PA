
#ifndef VISITE_PETMR_H_
#define VISITE_PETMR_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Visite/Pet.h"
#include "../Visite/Mr.h"

using namespace std;

class PetMr : public Pet, public Mr {
	friend class Metodi;
protected:
	PetMr();
	PetMr(int,int,int,dottore_ref,dottore_ref,paziente_ref);
public:
	virtual int getDurata();
	int getDurataPet();
	int getDurataMr();
	virtual void stampa();
	virtual ~PetMr();
};

typedef shared_ptr<PetMr> petmr_ref;

#endif /* VISITE_PETMR_H_ */
