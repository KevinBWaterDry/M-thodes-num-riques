# M-thodes-num-riques
travail du cours

#define _CRT_SECURE_NO_WARNINGS



　


#include <stdio.h>


#include <stdlib.h>


#include <conio.h>


#include <iostream>


#include <cmath>


#include <fstream>


#include "algorithmes.h"



double FoncDeX(double X);


double FoncDeriv(double X);


double Fonc2Deriv(double X);


double FoncDeriv1(double X);


double FoncDeriv2(double X);


double FoncTest(double X);


double FoncTest2(double X);


using namespace std;



　


　


int main()


{


	printf("Debut de l'algorithme\n");


	printf("*********************\n\n\n");


	printf("Lecture des donnees\n\n");


	


	Texte Donnee;


	ifstream lecturefichier("texte.txt"); //sortie:  std::ofstream lecturefichier("texteReponse.txt")


	ofstream sortiefichier("texteReponse.txt");



	if (!sortiefichier.is_open())


	{


		printf("impossible de rouvrir le fichier sortie.\n");


		return 0;


	}



	if (!lecturefichier)


	{


		printf("une erreur est survenue lors de la lecture du fichier\n");


		return 0;


	}



	lecturefichier >> Donnee.precision;


	lecturefichier >> Donnee.NbMax;


	lecturefichier >> Donnee.BorneG;


	lecturefichier >> Donnee.BorneD;


	lecturefichier >> Donnee.T;



　


　


　


	RepAlgo zeroBi;


	zeroBi = Bissection(FoncDeriv,Donnee.precision, Donnee.NbMax, Donnee.BorneG, Donnee.BorneD);


	printf("la hauteur est %.10lf  pour la bissection a X = %.10lf \net en %d itterations",Donnee.T*FoncDeX(zeroBi.reponse), zeroBi.reponse, zeroBi.Nbiteration);



　


	RepAlgo zeroPoint;


	zeroPoint = PointFixe(FoncDeriv2, Donnee.precision, Donnee.NbMax, Donnee.BorneG);


	printf("\n\n\nla hauteur est %.10lf  pour le point fixe  a X = %.10lf \net en %d itterations", Donnee.T*FoncDeX(zeroPoint.reponse), zeroPoint.reponse, zeroPoint.Nbiteration);



	zeroPoint = PointFixe(FoncDeriv1, Donnee.precision, Donnee.NbMax, Donnee.BorneG);


	printf("\n\n\nla hauteur est %.10lf pour le point fixe  a X = %.10lf \net en %d itterations", Donnee.T*FoncDeX(zeroPoint.reponse), zeroPoint.reponse, zeroPoint.Nbiteration);



　


	RepAlgo zeroNewton;


	zeroNewton = Newton(FoncDeriv, Fonc2Deriv, Donnee.precision, Donnee.NbMax, Donnee.BorneG);


	printf("\n\n\nla hauteur est %.10lf pour Newton  a X = %.10lf \net en %d itterations", Donnee.T*FoncDeX(zeroNewton.reponse), zeroNewton.reponse, zeroNewton.Nbiteration);



	


	



　


	sortiefichier << "la reponse pour la methode de bissection est y = "<< Donnee.T*FoncDeX(zeroBi.reponse) << endl;


	sortiefichier << "trouvé en " << zeroBi.Nbiteration << " ittérations."<< endl<< endl ;



	sortiefichier << "la reponse pour la methode du point est y = " << Donnee.T*FoncDeX(zeroPoint.reponse) << endl;


	sortiefichier << "trouvé en " << zeroPoint.Nbiteration << " ittérations." << endl << endl ;



	sortiefichier << "la reponse pour la methode de Newton est y = " << Donnee.T*FoncDeX(zeroNewton.reponse) << endl;


	sortiefichier << "trouvé en " << zeroNewton.Nbiteration << " ittérations." << endl << endl ;



	sortiefichier.close();



　


	printf("\n\n\n*********************\n");


	printf("Fin de l'algorithme\n");


	



　


	_getch();


	return 0;


}



double Fonc2Deriv(double X)


{


	return(-1.85 / (2*pow(X, 1.5)) - 3.6*pow(X, 2));


}



double FoncDeriv(double X)


{


	return (1.85/sqrt(X) -3.4 - 1.2*  pow(X, 3));


}



double FoncDeX(double X)


{


	return(3.7*pow(X, 1 / 2) - 3.4*X - 0.3*pow(X, 4));


}



double FoncDeriv1(double X)


{


	return(3.4/1.85*pow(X,3.0/2.0)+1.2*pow(X,9.0/2.0));


}



double FoncDeriv2(double X)


{


	return (pow(-17 / 6 + 37 / (24 * sqrt(X)), 1.0 / 3.0));


}



double FoncTest(double X)


{


	return(sqrt(2 * X + 3));


}



double FoncTest2(double X)


{


	return(3 / (X - 2));


}


