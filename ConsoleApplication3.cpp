// ConsoleApplication3.cpp : Defines the entry point for the console application.
// Gestion d'hôtel exercice 5
#include "stdafx.h"
#include "Hotel.h"


// Programme Principale
int main()
{
	Client C1("hamza", "fes", "maroc"), C2("youssef");
	Chambre S1(T1), S2, S3(T2), S4, S5;
	Hotel H;
	H.attribuer(S1, C1);
	H.ajoutClient(C2);
	H.reserver(S3, C2, Periode(Date(1,9,2019), 12));
	H.reserver(S3, C1);
	H.annulerResrv(102);
	H.ajoutChambre(S2);
	H.ajoutChambre(S3);
	H.ajoutChambre(S4);
	H.ajoutChambre(S5);
	H.showInfos();
    return system("pause");
}

