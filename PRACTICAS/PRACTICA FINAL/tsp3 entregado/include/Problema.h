#ifndef PROBLEMA_H
#define PROBLEMA_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <random>
#include "Solucion.h"
#include "Punto.h"

using namespace std ;

class Problema {

	private:
	
		int ciudades;
		Punto* coordenada;
		int **distancias ;   // Matriz que contiene distancia entre "i" y "j"
		void Reservar ();   //Función para reservar memoria
		void Liberar ();    //Función para liberar la memoria reservada
		void Copiar (const Problema &orig);   //Función para copiar dos problema
		
	public:

		Problema (char* nombreFichero) ;   //Contructor para dormar un problema atrves de un archivo
		Problema (Problema &otro) ;        //Constructor para construir un problema atraves de otro
		Problema ();       //Constructor vacio
		~Problema ();      //Destructor del objeto
		int Tamanio() const;              //Función para saber el número de ciudades
		Punto Coordenadas (int c) ;                 //Función que devuelve un punto con las cordenadas
		void CalcularDistancia (int i,int j) ;      //Función para calcular la distancias
		int Distancia (int i, int j) const ;        //Función para consultar la distancia en la matriz
		int longitudRecorrido (const Solucion &s) const ; //Función que calcula la longitud del recorrido
		Problema &operator=(const Problema &orig);       //Sobrecarga del operador "="
};

#endif

