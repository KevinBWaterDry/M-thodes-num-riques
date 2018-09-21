# M-thodes-num-riques
travail du cours

#include "algorithmes.h"



　


　


RepAlgo Bissection(double(*FdeX)(double), double Tolerence, int Nbmax, double Xgauche, double Xdroite)


{


	RepAlgo bob;


	double Xm;


	int Nb;


	Nb = 0;


	Xm = 0;



	



	while (Nb < Nbmax && abs(Xgauche-Xdroite)>Tolerence)


	{


		Xm = (Xgauche + Xdroite) / 2;



		if (FdeX(Xgauche)*FdeX(Xm) <= 0 ) 


		{


			Xdroite = Xm;


		}


		else if(FdeX(Xgauche)*FdeX(Xm) > 0 ) 


			{


			Xgauche = Xm;


			}



		else 


			{


			printf("un problème est survenu lors de la détection des zero pour la Bissection\n");


			


			}


		Nb++;


	}



	if (Nb >= Nbmax)


	{


		printf("il n'y a pas eu de convergence\n");


	}



	bob.reponse = Xm;


	bob.Nbiteration = Nb;


	return bob;


	


}



RepAlgo PointFixe(double(*FdeX)(double), double Tolerence, int Nbmax,double X)


{


	RepAlgo bob;


	bob.Nbiteration = 0;


	bob.reponse = 0;


	int Nb;


	Nb = 0;


	double XPasse;


	double XTransition;


	XPasse = 0;


	XTransition = 0;



	while (Nb < Nbmax && abs(X-XPasse)/abs(XPasse) > Tolerence)


	{


		X = FdeX(X);


		XPasse = XTransition;


		XTransition = X;



		Nb++;


	}


	if (Nb >= Nbmax)


	{


		printf("il n'y a pas eu de convergence\n");


	}



	bob.Nbiteration = Nb;


	bob.reponse = X;



　


	return bob;


}



RepAlgo Newton(double(*FdeX)(double), double(*Fderiv)(double), double Tolerence, int Nbmax, double X)


{


	int Nb;


	double XPasse;


	double XTransition;


	RepAlgo bob;



	XPasse = X;


	XTransition = X;


	X = -1;


	Nb = 0;


	


	while (Nb < Nbmax && abs(X - XPasse) > Tolerence)


	{


		XPasse = XTransition;


		if (Fderiv(XPasse) == 0)printf("une erreure est survenue dans la methode de Newton\n");



		X = XPasse - FdeX(XPasse) / Fderiv(XPasse);


		Nb++;


		XTransition = X;


	}


	if (Nb >= Nbmax)


	{


		printf("il n'y a pas eu de convergence\n");


	}


	bob.Nbiteration = Nb;


	bob.reponse = X;


	return bob;



　


}
