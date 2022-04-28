
#ifndef METODI_H_
#define METODI_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "../Utenti/Persona.h"
#include "../Utenti/Paziente.h"
#include "../Utenti/Dottore.h"
#include "../Visite/Esame.h"
#include "../Visite/Pet.h"
#include "../Visite/Mr.h"
#include "../Visite/PetMr.h"

using namespace std;

class Metodi {
private:
	time_t data = time(0);
	tm* now = localtime(&data);
	int annocorrente = now->tm_year+1900;
	vector<paziente_ref> lista_pazienti;
	vector<dottore_ref> lista_dottori;
	vector<esame_ref> lista_esami;
	vector<pet_ref> lista_esami_pet;
	vector<mr_ref> lista_esami_mr;
	vector<petmr_ref> lista_esami_petmr;
private:
	Metodi();
	static Metodi* mOgg; //singleton
	void caricadati();
	bool ctrl_paz(string); // Overloading
	bool ctrl_dott(string);
	int ctrl_paz(int); // Overloading
	int ctrl_dott(int);
	void cerca_paz(int);
	void cerca_dott(int);
public:
	static Metodi* getOggetto();
	// paziente
	void inserisciPaziente();
	void stampaElenco_paz();
	void ordinaElenco_ID_paz();
	void ordinaElenco_Categoria_paz();
	// dottore
	void inserisciDottore();
	void stampaElenco_dott();
	void ordinaElenco_ID_dott();
	void ordinaElenco_Specializzazione_dott();
	// esame
	void inserisciEsame();
	virtual void stampaElenco_esami();
	void stampaEsami_ID_dott();
	void stampaEsami_ID_paz();
	// PET
	void inserisciEsamePet();
	virtual void stampaElenco_esami_pet();
	void stampaEsami_PET_corti();
	// MR
	void inserisciEsameMr();
	virtual void stampaElenco_esami_mr();
	void stampaEsami_MR_forti();
	// PET/MR
	void inserisciEsamePetMr();
	virtual void stampaElenco_esami_pet_mr();
	void stampaEsami_PETMR_corti_forti();


	int getYear();
	virtual ~Metodi();
private:
	paziente_ref creaPaziente();
	paziente_ref creaPaziente(Paziente*);
	paziente_ref creaPaziente(int, string, string, string, category);
	dottore_ref creaDottore();
	dottore_ref creaDottore(Dottore*);
	dottore_ref creaDottore(int, string, string, string, string);
	esame_ref creaEsame();
	esame_ref creaEsame(dottore_ref, paziente_ref);
	pet_ref creaEsamePet();
	pet_ref creaEsamePet(int,dottore_ref, paziente_ref);
	mr_ref creaEsameMr();
	mr_ref creaEsameMr(int,int,dottore_ref, paziente_ref);
	petmr_ref creaEsamePetMr();
	petmr_ref creaEsamePetMr(int,int,int,dottore_ref,paziente_ref);

};

#endif /* METODI_H_ */
