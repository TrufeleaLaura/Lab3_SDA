#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
	if (e1 <= e2) return true;
	return false;
}

Nod::Nod(TElem el, PNod next, PNod prev) {
	//teta(1)
	this->el = el;
	this->next = next;
	this->prev = prev;

}

Colectie::Colectie() {
	//teta(1)
	this->prim = nullptr;
	this->ult = nullptr;
	this->lg = 0;
}

PNod Nod::urmator() {
	//teta(1)
	return next;
}

PNod Nod::precedent() {
	//teta(1)
	return prev;
}
TElem Nod::element() {
	//teta(1)
	return el;   
}

void Colectie::adauga(TElem e) {
	//o(n)
	Nod* i = this->prim;
	if (this->lg == 0) {
		Nod* nodNou = new Nod(e,nullptr,i);
		this->prim = nodNou;
		this->lg++;
		return;
	}
	if (rel(e, i->el)) {
		Nod* nodNou = new Nod(e,this->prim,nullptr);
		this->prim = nodNou;
		this->lg++;
		return;
	}
	while (i->next != 0) {
		if (rel(e, i->next->el)) {
			Nod* nodNou = new Nod(e,i->next,i);
			i->next = nodNou;
			this->lg++;
			return;
		}
		else i = i->next;
	}
	i->next = new Nod(e,nullptr,i);
	this->lg++;
}


bool Colectie::sterge(TElem e) {
	//O(n)
	Nod* i = this->prim;
	Nod* aux;
	if (this->lg == 0) return false;
	if (i->el == e) {
		this->prim = i->next;
		this->lg--;
		delete i;
		return true;
	}
	while (i->next != 0) {
		if (i->next->el == e) {
			aux = i->next;
			i->next = i->next->next;
			delete aux;
			this->lg--;
			return true;
		}
		else i = i->next;
	}
	return false;
}


bool Colectie::cauta(TElem elem) const {
	//o(n)
	Nod* i = this->prim;
	while (i != 0) {
		if (i->el == elem)
			return true;
		i = i->next;
	}
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	//teta(n)
	int nr = 0;
	Nod* i = this->prim;
	while (i != 0) {
		if (i->el == elem)
			nr++;
		i = i->next;
	}
	return nr;
}

int Colectie:: numaraElementeUnice() const {
	int nr=0;
	Nod* i = this->prim;
	int var = this->prim->el;
	while (nrAparitii(i->el) != 1 && (i==0) )
		i = i->next;
	while (i!=0) {
		if (nrAparitii(i->el) == 1 && (i->el) != var)
		{
			nr++;
			var = i->el;
		}
			i = i->next;
	}
	return nr;

}

int Colectie::dim() const {
	//teta(1)
	return this->lg;
}


bool Colectie::vida() const {
	//teta(1)
	if (this->lg!= 0) return false;
	return true;
}


IteratorColectie Colectie::iterator() const {
	//teta(1)
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	//teta(n)
	Nod* i = this->prim;
	Nod* aux;
	while (i != 0) {
		aux = i->next;
		delete i;
		i = aux;
	}
}
