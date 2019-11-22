#pragma once										/// ISMAILI ALAOUI HAMZA
#include <vector>
#include "Reservation.h"
#include "Occupation.h"

#define SEP1 "----------------------------------------------------------------------------------------------"
#define SEP2 "##############################################################################################"
#define SEP3 "______________________________________________________________________________________________"

class Hotel
{
public:
	Hotel();
	~Hotel();

	void ajoutChambre(Chambre & S);
	void ajoutClient(Client & C);
	bool isIN(int idClient);
	bool isIN2(int numChambre);
	Chambre cherchChambre(int numero);
	Chambre cherchChambre(string nomClient);
	Chambre cherchChambreReserv(string nomClient);
	void reserver(Chambre & S, Client & C);
	void reserver(Chambre & S, Client & C, Periode const& P);
	int reservIndex(int idClient);
	void annulerResrv(int idClient);
	void attribuer(Chambre & S, Client & C);
	Client cherchClient(int numeroChambre);
	Client cherchClientReserv(int numeroChambre);
	void showInfos();
	void sort(int key);

	friend void ln(int number, string separator);
	friend void ln();
	

private:
	vector<Client> clients;
	vector<Chambre> chambres;
	vector<Reservation> reservations;
	vector<Occupation> occupations;
};

