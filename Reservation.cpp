#include "stdafx.h"										/// ISMAILI ALAOUI HAMZA
#include "Reservation.h"


Reservation::Reservation() : Reservation(Client(), Chambre())
{
}

Reservation::Reservation(Client const & C, Chambre const & S) : Reservation(C, S, Periode())
{
}

Reservation::Reservation(Client const & C, Chambre const & S, Periode const & P) :
	client(C), chambre(S), periode(P)
{
}

Reservation::Reservation(Reservation const & R) :
	Reservation(R.client, R.chambre, R.periode)
{
}


Reservation::~Reservation()
{
}

bool Reservation::operator==(Reservation const & R) const
{
	return (this->client == R.client && this->chambre == R.chambre && this->periode == R.periode);
}

bool Reservation::operator!=(Reservation const & R) const
{
	return !(*this == R);
}

void Reservation::print() const
{
	cout << *this << endl;
}

ostream & operator<<(ostream & flux, Reservation const & R)
{
	flux << "Information Client  : " << endl << R.client << endl
		<< "Information Chambre : " << endl << R.chambre << endl
		<< "Periode             :   " << R.periode;
	return flux;
}
