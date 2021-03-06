
#ifndef FUNZIONALITA_COMPARATORI_H_
#define FUNZIONALITA_COMPARATORI_H_

static bool compareByCategoria(paziente_ref &a, paziente_ref &b) {
	return a->getCategoria() < b->getCategoria();
}

static bool compareBySpecializzazione(dottore_ref &a, dottore_ref &b) {
	return a->getSpecializzazione() < b->getSpecializzazione();
}

static bool comparePazByID(paziente_ref &a, paziente_ref &b) {
	return a->getIdPaz() < b->getIdPaz();
}

static bool compareDottByID(dottore_ref &a, dottore_ref &b) {
	return a->getIdDott() < b->getIdDott();
}


#endif /* FUNZIONALITA_COMPARATORI_H_ */
