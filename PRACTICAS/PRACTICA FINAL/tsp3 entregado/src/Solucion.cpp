#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Solucion.h"



using namespace std ;

	
		Solucion::Solucion (int* v, int n)  { // Constructor con parámetros, pasándole un vector y un número n de elementos para reservar //
			Recorrido= new int [n];			
			for (int i = 0 ; i < n ; i++) {
				Recorrido [i] = v[i] ;
			}
			num_ciudade = n;
		}
		

		Solucion::Solucion (int n) { // Constructor al que le pasamos únicamente un parámetro, que será el numero de elementos a reservar en Recorrido (dato miembro de la clase Solución) //
			num_ciudade = n;
			Recorrido= new int [n];
			long int sol_aleatoria;
			for (int i = 0 ; i < n ; i++) {
				sol_aleatoria = rand()%n;
				Recorrido [i] = sol_aleatoria  ;
			}
		}
		void Solucion:: Reservar () { // Función auxiliar que reserva para Recorrido en función de num_ciudade //
			int n = num_ciudade;
			Recorrido = new int [n] ;
		}

		void Solucion:: Liberar () { // Función auxiliar que se encarga de liberar todos los datos de la clase Solución //
			delete[] Recorrido ;
			num_ciudade = 0 ;
			Recorrido = NULL ;
		}
		Solucion::Solucion (const Solucion &orig) { // Constructor de copia //
			Reservar();
			Copiar (orig) ;
		}
		
		Solucion::Solucion(){ //Constructor por defecto //
			Recorrido = 0 ;
			num_ciudade = 0 ;
		}

		Solucion::~Solucion () { // Destructor //
			Liberar() ;
		}

		bool Solucion::esCorrecta() const { // Método que se encarga de evaluar si un valor está repetido o no dentro del vector Recorrido //
			bool correcto = true ;
			int contador;
			for (int i = 0 ; i < num_ciudade && contador > 1 ; i++) {
				contador = 0;
				for (int j = 0 ; i < num_ciudade && contador > 1; j++){
					if (Recorrido [i] == Recorrido [j]) {
						contador++;
					}
				}
			}
			if (contador > 1){
				correcto = false;
			}

			return correcto ;
		}

		int Solucion::ciudad (int pos) const { // Método que devuelve la ciudad c situada en la posición del vector pasada como argumento //
			return Recorrido [pos] ;
		}

		int Solucion::posicion (int c) const { // Método que devuelve la posición de la ciudad c en el recorrido //

			bool encontrado = false ;
			int pos = -1 ;
			for (int i = 0 ; i < num_ciudade && encontrado  ; i++) {
				if (Recorrido [i] == c) {
					encontrado = true ;
					pos = i ;
				}
			}
			return pos;
		}

		int Solucion::GetNumCiudades () const { // Método encargado de devolver el número de ciudades de la Solución //
			return num_ciudade ;
		}

		string Solucion::to_string (const Solucion &sol) const { // Método tipo string //
			string solu ;
			for (int i = 0 ; i < num_ciudade ; i++) {
				solu = sol.to_string (sol.ciudad(i))+ "," + sol.to_string (sol.GetNumCiudades()) ;
			}
			return solu ;
		}

		void Solucion::Copiar (const Solucion &orig) { //Método auxiliar encargado de copiar //
			num_ciudade = orig.num_ciudade ;
			for (int i = 0 ; i < num_ciudade ; i++) {
				Recorrido[i] = orig.Recorrido[i] ;
			}
		}
		
		Solucion& Solucion::operator= (const Solucion &orig) { //Operador de asignación //
			if (this != &orig)  {
				Liberar() ;
				Reservar() ;
				Copiar (orig) ;
			}
			return *this ;
		}

/*		ostream& Solucion::operator<< (ostream &flujo, const Solucion& orig) { //Sobrecarga del operador "<<"
			for(int i=0; i< num_ciudade; i++){
				flujo<< orig.Recorrido[i] << ", "
			}
			flujo<<endl;
			return flujo ;
		}
*/
