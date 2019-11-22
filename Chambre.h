#pragma once											/// ISMAILI ALAOUI HAMZA
#include <iostream>
#include <string>
#define T1 "SIMPLE"
#define T2 "DOUBLE"
#define E1 "LIBRE"
#define E2 "OCCUPEE"

using namespace std;

class Chambre
{
public:
	Chambre();
	Chambre(string type);
	Chambre(string type, unsigned int nomb_lits);
	Chambre(string type, unsigned int nomb_lits, double prix);
	Chambre(Chambre const& C);
	~Chambre();

	bool operator==(Chambre const& C) const;
	bool operator!=(Chambre const& C) const;
	friend ostream & operator<<(ostream & flux, Chambre const& C);

	void print() const;

	int getNumero() {
		return this->numero;
	}
	void setEtat(string etat) {
		this->etat = etat;
	}

private :
	unsigned static int counter;
	int numero;
	string type;
	unsigned int nomb_lits;
	string etat;
	double prix;
};

