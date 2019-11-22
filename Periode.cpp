#include "stdafx.h"										/// ISMAILI ALAOUI HAMZA
#include "Periode.h"


Periode::Periode() : Periode(Date(), 0)
{
}

Periode::Periode(Date const & D, unsigned int nomb_jours) : date_arrivee(D), nomb_jours(nomb_jours)
{
}

Periode::Periode(Periode const & P) : Periode(P.date_arrivee, P.nomb_jours)
{
}


Periode::~Periode()
{
}

bool Periode::operator==(Periode const & P) const
{
	return (this->date_arrivee == P.date_arrivee && this->nomb_jours == P.nomb_jours);
}

bool Periode::operator!=(Periode const & P) const
{
	return !(*this == P);
}

void Periode::print() const
{
	cout << *this << endl;
}

ostream & operator<<(ostream & flux, Periode const & P)
{
	flux << "Arrivee le " << P.date_arrivee << " et veut rester " << P.nomb_jours << " jours";
	return flux;
}
