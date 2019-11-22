#include "stdafx.h"											/// ISMAILI ALAOUI HAMZA
#include "Client.h"

unsigned int Client::counter = 100;

Client::Client() : Client("unknown")
{
}

Client::Client(string nom) : Client(nom, "unknown")
{
}

Client::Client(string nom, string ville) : Client(nom, ville, "unknown")
{
}

Client::Client(string nom, string ville, string pays) : nom(nom), ville(ville), pays(pays)
{
	counter++;
	this->id = counter;
}

Client::Client(Client const & C) : Client(C.nom, C.ville, C.pays)
{
	this->id = C.id;
	counter = this->id;
}


Client::~Client()
{
}

bool Client::operator==(Client const & C) const
{
	return (this->nom == C.nom && this->ville == C.ville && this->pays == C.pays);
}

bool Client::operator!=(Client const & C) const
{
	return !(*this == C);
}

void Client::print() const
{
	cout << *this << endl;
}

ostream & operator<<(ostream & flux, Client const & C)
{
	flux << "\t\t\tID    du Client  : " << C.id << endl
		<< "\t\t\tNom   du Client  : " << C.nom << endl
		<< "\t\t\tVille du Client  : " << C.ville << endl
		<< "\t\t\tPays  du Client  : " << C.pays;
	return flux;
}
