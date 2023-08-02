#include <iostream>
#include <cmath>
#include <cstring>
#include "Punto.h"

using namespace std ;

Punto::Punto () { //Contructor vacio
	x = y = 0 ;
	}
	
double Punto::GetX () {   //Función Get de X
	return x;
}
	
double Punto::GetY () {   //Función Get de Y
	return y;
}
	
void Punto::SetX (double valor) {   //Función Set de X
	x = valor ;
}
	

void Punto::SetY (double valor) {   //Función Set de Y
	y = valor ;
}	

string Punto::To_String () {    //Función para mostrar las cordenadas como un string
	return to_string(x) + "," + to_string(y) ;
}

double Punto::Dist_eu (Punto otro) {   //Función para calcular la distacia euclidea entre los puntos
	return sqrt(pow(x-otro.GetX(),2)+pow(y-otro.GetY(),2));
}
