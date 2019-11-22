#pragma once											/// ISMAILI ALAOUI HAMZA
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Periode
{
public:
	Periode();
	Periode(Date const& D, unsigned int nomb_jours);
	Periode(Periode const& P);
	~Periode();

	bool operator==(Periode const& P) const;
	bool operator!=(Periode const& P) const;
	friend ostream & operator<<(ostream & flux, Periode const& P);

	void print() const;

private:
	Date date_arrivee;
	unsigned int nomb_jours;
};

