
#ifndef VISITE_MR_H_
#define VISITE_MR_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../Visite/Esame.h"

using namespace std;

class Mr : virtual public Esame {
public:
	int intensita = 2;
	int durata = 15;
	friend class Metodi;
protected:
	Mr();
	Mr(int,int,dottore_ref,paziente_ref);
	void setDurata(int);
	void setIntensita(int);
public:
	virtual int getDurata();
	int getIntensita();
	virtual void stampa();
	virtual ~Mr();
};

typedef shared_ptr<Mr> mr_ref;

#endif /* VISITE_MR_H_ */
