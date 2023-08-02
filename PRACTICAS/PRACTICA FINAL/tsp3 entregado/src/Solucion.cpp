#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Solucion.h"



using namespace std ;

	
		Solucion::Solucion (int* v, int n)  { // Constructor con par�metros, pas�ndole un vector y un n�mero n de elementos para reservar //
			Recorrido= new int [n];			
			for (int i = 0 ; i < n ; i++) {
				Recorrido [i] = v[i] ;
			}
			num_ciudade = n;
		}
		

		Solucion::Solucion (int n) { // Constructor al que le pasamos �nicamente un par�metro, que ser� el numero de elementos a reservar en Recorrido (dato miembro de la clase Soluci�n) //
			num_ciudade = n;
			Recorrido= new int [n];
			long int sol_aleatoria;
			for (int i = 0 ; i < n ; i++) {
				sol_aleatoria = rand()%n;
				Recorrido [i] = sol_aleatoria  ;
			}
		}
		void Solucion:: Reservar () { // Funci�n auxiliar que reserva para Recorrido en funci�n de num_ciudade //
			int n = num_ciudade;
			Recorrido = new int [n] ;
		}

		void Solucion:: Liberar () { // Funci�n auxiliar que se encarga de liberar todos los datos de la clase Soluci�n //
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

		bool Solucion::esCorrecta() const { // M�todo que se encarga de evaluar si un valor est� repetido o no dentro del vector Recorrido //
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

		int Solucion::ciudad (int pos) const { // M�todo que devuelve la ciudad c situada en la posici�n del vector pasada como argumento //
			return Recorrido [pos] ;
		}

		int Solucion::posicion (int c) const { // M�todo que devuelve la posici�n de la ciudad c en el recorrido //

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

		int Solucion::GetNumCiudades () const { // M�todo encargado de devolver el n�mero de ciudades de la Soluci�n //
			return num_ciudade ;
		}

		string Solucion::to_string (const Solucion &sol) const { // M�todo tipo string //
			string solu ;
			for (int i = 0 ; i < num_ciudade ; i++) {
				solu = sol.to_string (sol.ciudad(i))+ "," + sol.to_string (sol.GetNumCiudades()) ;
			}
			return solu ;
		}

		void Solucion::Copiar (const Solucion &orig) { //M�todo auxiliar encargado de copiar //
			num_ciudade = orig.num_ciudade ;
			for (int i = 0 ; i < num_ciudade ; i++) {
				Recorrido[i] = orig.Recorrido[i] ;
			}
		}
		
		Solucion& Solucion::operator= (const Solucion &orig) { //Operador de asignaci�n //
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
