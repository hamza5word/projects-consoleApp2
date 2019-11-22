#pragma once											/// ISMAILI ALAOUI HAMZA
#include "Client.h"
#include "Chambre.h"
#include "Periode.h"

class Reservation
{
public:
	Reservation();
	Reservation(Client const& C, Chambre const& S);
	Reservation(Client const& C, Chambre const& S, Periode const& P);
	Reservation(Reservation const& R);
	~Reservation();

	bool operator==(Reservation const& R) const;
	bool operator!=(Reservation const& R) const;
	friend ostream & operator<<(ostream & flux, Reservation const& R);

	void print() const;

	Client getClient() {
		return this->client;
	}
	Chambre getChambre() {
		return this->chambre;
	}
	Periode getPeriode() {
		return this->periode;
	}

private :
	Client client;
	Chambre chambre;
	Periode periode;
};

