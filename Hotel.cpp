#include "stdafx.h"									/// ISMAILI ALAOUI HAMZA
#include "Hotel.h"


Hotel::Hotel() : clients(vector<Client>(0)), chambres(vector<Chambre>(0))
{
}

Hotel::~Hotel()
{
}

void Hotel::ajoutChambre(Chambre & S)
{
	if (!isIN2(S.getNumero())) this->chambres.push_back(S);
	this->sort(2);
}

void Hotel::ajoutClient(Client & C)
{
	if (!isIN(C.getID())) this->clients.push_back(C);
	this->sort(1);
}

bool Hotel::isIN(int idClient)
{
	for (unsigned int i = 0; i < this->clients.size(); i++)
		if (this->clients[i].getID() == idClient) return true;
	return false;
}

bool Hotel::isIN2(int numChambre)
{
	for (unsigned int i = 0; i < this->chambres.size(); i++)
		if (this->chambres[i].getNumero() == numChambre) return true;
	return false;
}

Chambre Hotel::cherchChambre(int numero)
{
	for (unsigned int i = 0; i < this->chambres.size(); i++)
	{
		if (this->chambres[i].getNumero() == numero) return this->chambres[i];
	}
	return Chambre();
}

Chambre Hotel::cherchChambre(string nomClient)
{
	for (unsigned int i = 0; i < this->occupations.size(); i++) {
		if (this->occupations[i].getClient().getNom() == nomClient)
			return this->occupations[i].getChambre();
	}
	return Chambre();
}

Chambre Hotel::cherchChambreReserv(string nomClient)
{
	for (unsigned int i = 0; i < this->reservations.size(); i++){
		if (this->reservations[i].getClient().getNom() == nomClient)
			return this->reservations[i].getChambre();
	}
	return Chambre();
}

void Hotel::reserver(Chambre & S, Client & C)
{
	if (!isIN(C.getID())) this->ajoutClient(C);
	if (!isIN2(S.getNumero())) this->ajoutChambre(S);
	Reservation R(C, S);
	this->reservations.push_back(R);
}

void Hotel::reserver(Chambre & S, Client & C, Periode const & P)
{
	if (!isIN(C.getID())) this->ajoutClient(C);
	if (!isIN2(S.getNumero())) this->ajoutChambre(S);
	Reservation R(C, S, P);
	this->reservations.push_back(R);
}

int Hotel::reservIndex(int idClient)
{
	for (unsigned int i = 0; i < this->reservations.size(); i++)
	{
		if (this->reservations[i].getClient().getID() == idClient) return i;
	}
	return 0;
}

void Hotel::annulerResrv(int idClient)
{
	if (isIN(idClient)) {
		this->reservations.erase(this->reservations.begin() + reservIndex(idClient));
	}
}

void Hotel::attribuer(Chambre & S, Client & C)
{
	S.setEtat(E2);
	if (!isIN(C.getID())) this->ajoutClient(C);
	if (!isIN2(S.getNumero())) this->ajoutChambre(S);
	Occupation O(C, S);
	this->occupations.push_back(O);
}

Client Hotel::cherchClient(int numeroChambre)
{
	for (unsigned int i = 0; i < this->occupations.size(); i++) {
		if (this->occupations[i].getChambre().getNumero() == numeroChambre)
			return this->occupations[i].getClient();
	}
	return Client();
}

Client Hotel::cherchClientReserv(int numeroChambre)
{
	for (unsigned int i = 0; i < this->reservations.size(); i++) {
		if (this->reservations[i].getChambre().getNumero() == numeroChambre)
			return this->reservations[i].getClient();
	}
	return Client();
}

void Hotel::showInfos() 
{
	ln();
	cout << "\t\t\t\t\tListe des Clients" << endl;
	ln();
	for (unsigned int i = 0; i < this->clients.size(); ++i) {
		this->clients[i].print();
		if(this->cherchChambre(this->clients[i].getNom()) != Chambre())
			cout << "\t\t\tOccupe la chambre numero : " << this->cherchChambre(this->clients[i].getNom()).getNumero() << endl;
		if (this->cherchChambreReserv(this->clients[i].getNom()) != Chambre())
			cout << "\t\t\tReserve la chambre numero : " << this->cherchChambreReserv(this->clients[i].getNom()).getNumero() << endl;
		ln();
	}
	system("pause");
	system("cls");
	ln();
	cout << "\t\t\t\t\tListe des Chambres" << endl;
	ln();
	for (unsigned int i = 0; i < this->chambres.size(); ++i) {
		this->chambres[i].print();
		if(this->cherchClient(this->chambres[i].getNumero()) != Client())
			cout << "\t\t\tOccupee par le Client : " << this->cherchClient(this->chambres[i].getNumero()).getNom() << endl;
		if (this->cherchClientReserv(this->chambres[i].getNumero()) != Client())
			cout << "\t\t\tReservee par le Client : " << this->cherchClientReserv(this->chambres[i].getNumero()).getNom() << endl;
		ln();
	}
	system("pause");
	system("cls");
	ln();
	cout << "\t\t\t\t\tListe des Reservations" << endl;
	ln();
	for (unsigned int i = 0; i < this->reservations.size(); ++i) {
		this->reservations[i].print();
		ln();
	}
	system("pause");
	system("cls");
	ln();
	cout << "\t\t\t\t\tListe des Occupations" << endl;
	ln();
	for (unsigned int i = 0; i < this->occupations.size(); ++i) {
		this->occupations[i].print();
		ln();
	}
}

void Hotel::sort(int key)
{
	switch (key)
	{
	case 1 :
		for (unsigned int i = 0; i < this->clients.size(); i++) 
			for (unsigned int j = 0; j < this->clients.size(); j++) {
				if (this->clients[i].getID() < this->clients[j].getID())
					swap(this->clients[i], this->clients[j]);
			}
	case 2 :
		for (unsigned int i = 0; i < this->chambres.size(); i++)
			for (unsigned int j = 0; j < this->chambres.size(); j++) {
				if (this->chambres[i].getNumero() < this->chambres[j].getNumero())
					swap(this->chambres[i], this->chambres[j]);
			}
	default:
		break;
	}
}


void ln(int number, string separator)
{
	for (int i = 0; i < number; i++) cout << separator << endl;
}

void ln()
{
	ln(1, SEP1);
}




