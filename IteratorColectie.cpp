#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	//teta(1)
	this->curent = c.prim;
}

TElem IteratorColectie::element() const {
	//teta(1)
	if (valid()) return this->curent->element();
	else throw "Iteratorul nu este valid";
	return -1;
}

bool IteratorColectie::valid() const {
	//teta(1)
	if (this->curent != 0) return true;
	return false;
}

void IteratorColectie::urmator() {
	//teta(1)
	this->curent = this->curent->urmator();
	valid();
}

void IteratorColectie::prim() {
	//teta(1)
	this->curent = col.prim;
}
