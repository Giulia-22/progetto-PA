
#ifndef UTENTI_PERSONA_H_
#define UTENTI_PERSONA_H_

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

class Persona {
public:
	int annonascita;
	string cf;
	friend class Metodi;
protected:
	string nome;
	string cognome;
	Persona();
	Persona(int, string, string, string);
	Persona(const Persona&);
	void setAnnonascita(int);
	void setCf(string);
	void setCognome(string);
	void setNome(string);
public:
	int getAnnonascita();
	string getCf();
	string getCognome();
	string getNome();
	virtual void stampa();
	virtual ~Persona();
};

typedef shared_ptr<Persona> persona_ref;

#endif /* UTENTI_PERSONA_H_ */
