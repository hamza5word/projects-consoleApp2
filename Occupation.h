#pragma once											/// ISMAILI ALAOUI HAMZA
#include <iostream>
#include <string>
#include "Client.h"
#include "Chambre.h"

using namespace std;

class Occupation
{
public:
	Occupation();
	Occupation(Client const& C, Chambre const& S);
	Occupation(Occupation const& O);
	~Occupation();
	
	bool operator==(Occupation const& O) const;
	bool operator!=(Occupation const& O) const;
	friend ostream& operator<<(ostream & flux, Occupation const& O);

	void print() const;

	Client getClient() {
		return this->client;
	}
	Chambre getChambre() {
		return this->chambre;
	}

private:
	Client client;
	Chambre chambre;
};

