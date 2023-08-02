#ifndef SOLUCION_H
#define SOLUCION_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <random>


using namespace std ;

class Solucion {

	private:
		
		int *Recorrido ;
		int num_ciudade ;

		void Reservar(int n) ;	// Función auxiliar que reserva para Recorrido en función de num_ciudade
		void Liberar() ;	// Función auxiliar que se encarga de liberar todos los datos de la clase Solución
		void Copiar (const Solucion &orig) ;	//Método auxiliar encargado de copiar

	public:
		Solucion(int* v, int n); 	//Constructor con parámetros, pasándole un vector y un número n de elementos para reserva
		Solucion(int n) ; 	// Constructor al que le pasamos únicamente un parámetro, que será el numero de elementos a reservar en Recorrido (dato miembro de la clase Solución
		Solucion(const Solucion &otra) ;	// Constructor de copia
		Solucion();	//Constructor por defecto
		~Solucion() ;	// Destructor
		bool esCorrecta() const; 	// Método que se encarga de evaluar si un valor está repetido o no dentro del vector Recorrido
		int ciudad(int pos) const;	// Método que devuelve la ciudad c situada en la posición del vector pasada como argumento
		int GetNumCiudades () const;	// Método que devuelve la posición de la ciudad c en el recorrido
		int posicion(int c) const;	// Método encargado de devolver el número de ciudades de la Solución
		string to_string(l) const;	// Método tipo string
		Solucion &operator= (const Solucion &orig) ;	//Operador de asignación
/*		ostream &operator<< (ostream &flujo, const Solucion &orig); */ //Sobrecarga del operador "<<"
		
		
		
};

#endif
