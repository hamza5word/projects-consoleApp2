#include "stdafx.h"												/// ISMAILI ALAOUI HAMZA
#include "Chambre.h"

unsigned int Chambre::counter = 0;
// CONSTRUCTEUR PAR DEFAULT
Chambre::Chambre() : Chambre(T1)
{
}
// AUTRES CONSTRUCTEURS
Chambre::Chambre(string type) : Chambre(type, 0)
{
}

Chambre::Chambre(string type, unsigned int nomb_lits) : Chambre(type , nomb_lits, 0.0)
{
	this->etat = E1;
}

Chambre::Chambre(string type, unsigned int nomb_lits, double prix) : 
	type(type), etat(etat), nomb_lits(nomb_lits), prix(prix)
{
	counter++;
	this->numero = counter;
}
// CONSTRUCTEUR DE COPIE
Chambre::Chambre(Chambre const& C) : Chambre(C.type, C.nomb_lits, C.prix)
{
	this->etat = C.etat;
	this->numero = C.numero;
	counter = this->numero;
}
// DESTRUCTEUR
Chambre::~Chambre()
{
}

bool Chambre::operator==(Chambre const& C) const
{
	return (this->type == C.type && this->etat == C.etat && this->nomb_lits == C.nomb_lits && this->prix == C.prix);
}

bool Chambre::operator!=(Chambre const& C) const
{
	return !(*this == C);
}

void Chambre::print() const
{
	cout << *this << endl;
}

ostream & operator<<(ostream & flux, Chambre const& C) 
{
	flux << "\t\t\tNumero du Chambre : " << C.numero << endl
		<< "\t\t\tType   du Chambre : " << C.type << endl
		<< "\t\t\tEtat   du Chambre : " << C.etat << endl
		<< "\t\t\tNombre de Lits    : " << C.nomb_lits << endl
		<< "\t\t\tPrix   du Chambre : " << C.prix << " DH";
	return flux;
}
