# M-thodes-num-riques
travail du cours

#ifndef PROJET_1_ALGORITHMES


#define PROJET_1_ALGORITHMES



#include <stdio.h>


#include <stdlib.h>


#include <conio.h>


#include <cmath>


#include <iostream>


#include <cmath>


#include <fstream>



struct RepAlgo


{


	double reponse;


	int Nbiteration;



};


struct Texte


{


	double precision;


	int NbMax;


	double BorneG;


	double BorneD;


	double T;


	



};



　


　


RepAlgo Bissection(double(*FdeX)(double), double Tolerence, int Nbmax, double Xgauche, double Xdroite);



RepAlgo PointFixe(double(*FdeX)(double), double Tolerence, int Nbmax, double X);



RepAlgo Newton(double(*FdeX)(double), double(*Fderiv)(double), double Tolerence, int Nbmax, double X);



#endif


