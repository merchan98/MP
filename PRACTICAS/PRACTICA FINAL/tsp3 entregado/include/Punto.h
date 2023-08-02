#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std ;

class Punto {
	
	private:
		
		double x,y;  //definicion de variables
		
	public: 
	
	Punto() ; //Contructor vacio
	double GetX ();     //Función Get de X
	double GetY ();     //Función Get de Y
	void SetX (double valor) ;     //Función Set de X
	void SetY (double valor) ;     //Función Set de Y
	string To_String () ;     //Función para mostrar las cordenadas como un string
	double Dist_eu (Punto otro);     //Función para calcular la distacia euclidea entre los puntos
};

#endif /* PUNTO_H */
		
