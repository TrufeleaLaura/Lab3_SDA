#pragma once;

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

bool rel(TElem, TElem);

class IteratorColectie;

class Nod;

typedef Nod *PNod;//pnod e adresa unui nod

class Nod

{
		private:

			TElem el;       //elementul propriu-zis
			PNod next;     //pointer la urmatorul nod din LDI
			PNod prev;     //pointer la anteriorul nod din LDI


		public:

			friend class Colectie;

			Nod(TElem e, PNod urm, PNod prev);
			TElem element();
			PNod urmator();
			PNod precedent();


};

class Colectie {

	friend class IteratorColectie;

	private:
	
		PNod prim;//adresa primului nod din lista
		PNod ult;//adresa ultimului element
		int lg;


	public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;

		int numaraElementeUnice() const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();


};

