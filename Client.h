#pragma once											/// ISAMILI ALAOUI HAMZA
#include <iostream>
#include <string>

using namespace std;

class Client
{
public:
	Client();
	Client(string nom);
	Client(string nom, string ville);
	Client(string nom, string ville, string pays);
	Client(Client const& C);
	~Client();

	bool operator==(Client const& C) const;
	bool operator!=(Client const& C) const;
	friend ostream & operator<<(ostream & flux, Client const& C);

	void print() const;

	string getNom() {
		return this->nom;
	}
	int getID() {
		return this->id;
	}
	string getVille() {
		return this->ville;
	}
	string getPays() {
		return this->pays;
	}

private :
	unsigned static int counter;
	int id;
	string nom;
	string ville;
	string pays;
};

