
#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
using namespace std;

class Persona {
public:
	int annonascita = 1900;
	string cf = "";
	friend class Metodi;
protected:
	string nome = "";
	string cognome = "";
protected:
	Persona();
	Persona(int, string, string, string);
	Persona(Persona*);
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

typedef unique_ptr<Persona> persona_ref;

#endif /* PERSONA_H_ */
