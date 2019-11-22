#include "stdafx.h"									/// ISMAILI ALAOUI HAMZA
#include "Occupation.h"


Occupation::Occupation() : Occupation(Client(), Chambre())
{
}

Occupation::Occupation(Client const & C, Chambre const & S) : client(C), chambre(S)
{
}

Occupation::Occupation(Occupation const & O) : Occupation(O.client, O.chambre)
{
}


Occupation::~Occupation()
{
}

bool Occupation::operator==(Occupation const & O) const
{
	return (this->client == O.client && this->chambre == O.chambre);
}

bool Occupation::operator!=(Occupation const & O) const
{
	return !(*this == O);
}

void Occupation::print() const
{
	cout << *this << endl;
}

ostream & operator<<(ostream & flux, Occupation const & O)
{
	flux << "Information Client  : " << endl << O.client << endl
		<< "Information Chambre : " << endl << O.chambre;
	return flux;
}
