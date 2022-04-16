
#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Persona {
public:
	int annonascita = 0;
	string cf;
protected:
	string nome;
	string cognome;
public:
	Persona() = default;
	Persona(int, string, string, string);
	Persona(Persona*);
	int getAnnonascita() const;
	void setAnnonascita(int);
	string getCf();
	void setCf(string);
	string getCognome();
	void setCognome(string);
	string getNome();
	void setNome(string);
	void stampa();
	virtual ~Persona();
};

typedef unique_ptr<Persona> persona_ref;

#endif /* PERSONA_H_ */
