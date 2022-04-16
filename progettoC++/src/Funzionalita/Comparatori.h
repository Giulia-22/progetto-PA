/*
 * Comparatori.h
 *
 *  Created on: 16 apr 2022
 *      Author: giuly
 */

#ifndef FUNZIONALITA_COMPARATORI_H_
#define FUNZIONALITA_COMPARATORI_H_


static bool compareByCognome(paziente_ref &a, paziente_ref &b) {
	return a->getCognome() < b->getCognome();
}

static bool compareByID(paziente_ref &a, paziente_ref &b) {
	return a->getIdPaz() < b->getIdPaz();
}


#endif /* FUNZIONALITA_COMPARATORI_H_ */