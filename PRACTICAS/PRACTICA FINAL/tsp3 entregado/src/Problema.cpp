#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <random>
#include "Punto.h"
#include "Problema.h"
#include "Solucion.h"


using namespace std ;
   
		void Problema::Reservar () { //Función para reservar memoria
			int n = ciudades ;
			distancias = new int* [n] ;
			coordenada = new Punto[n];
			for (int i = 0 ; i < n ; i++) { //Creamos la matriz
				distancias [i] = new int [n] ;
			}
		}

		void Problema::Liberar () { //Función para liberar la memoria reservada
			int n = ciudades ;
			for (int i = 0 ; i < n ; i++) {
				delete [] distancias [i];
			}
			delete [] distancias ;
			delete [] coordenada;
			
			coordenada = 0 ;
			distancias = 0 ; 
			ciudades = 0 ;
		}

		void Problema::Copiar (const Problema &orig) { //Función para copiar dos problemas
			ciudades = orig.ciudades ;
			for (int k = 0 ; k < ciudades ; k++) {
				coordenada[k] = orig.coordenada[k] ;  //Copiamos las cordenadas
			}
			for (int i = 0 ; i < ciudades ; i++) {
				for (int j = 0 ; j < ciudades ; j++) {
					distancias[i][j] = orig.distancias[i][j]; //Copiamos la matriz distancias
				}
			}
		}

		Problema::Problema(char* nombreFichero)  { //Contructor para dormar un problema atrves de un archivo
			int numCiudades;
			double x,y;
			string cabecera;
			ifstream archi;
			
		
			archi.open(nombreFichero);// Abrimos el archivo
			archi >> cabecera; //leemos la cabecera para saber si se trata e un archivo tipo tsp
			archi >> numCiudades; //Leemos el numero de ciudades

			ciudades = numCiudades;
			Reservar(); //LLamamos a la funcion para reservar memoria


			for(int i = 0; i < numCiudades; i++){  //Bucle para leer las cordenadas
				archi >> x; //Leemos la cordenada X
				coordenada[i].SetX(x); //Guardamos la cordenada X
				archi >> y;//Leemos la cordenada Y
				coordenada[i].SetY(y);//Guardamos la cordenada Y
			}
			for (int i = 0 ; i < ciudades ; i++) {  //Bucles anidados para la construcion de la matriz
				for (int j = 0 ; j < ciudades ; j++) {
					CalcularDistancia(i,j) ; //Calculamos la distancia entrelos dos puntos
				}
			}		
		}

		Problema::Problema (const Problema &otro) { //Constructor para construir un problema atraves de otro
			ciudades = otro.Tamanio() ;
			for (int k = 0 ; k < ciudades ; k++) {
				coordenada [k] = otro.coordenada [k] ;
			}
			for (int i = 0 ; i < ciudades ; i++) {
				for (int j = 0 ; j < ciudades ; j++) {
					otro.distancas[i][j]= this->distancia[i][j] ;
				}
			}
		}

		Problema::Problema () { //Constructor vacio
			ciudades = 0 ;
			coordenada = 0 ;
			distancias = 0 ;
		}

		Problema::~Problema () { //Destructor del objeto
			Liberar () ;
		}
		int Problema::Tamanio () const{ //Función para saber el número de ciudades
			return ciudades ;
		}
		Punto Problema::Coordenadas (int c) { //Función que devuelve un punto con las cordenadas
			return coordenada[c] ;
		}

		void Problema::CalcularDistancia (int i, int j) { //Función para calcular la distancias
			double distance = round( Coordenadas(i).Dist_eu(Coordenadas(j)));
			distancias[i][j] = distance ;
		}


		int Problema::Distancia (int i, int j) const{ //Función para consultar la distancia en la matriz
			return distancias[i][j] ;
		}

		int Problema::longitudRecorrido (const Solucion &s) const { //Función que calcula la longitud del recorrido
			int suma_dist = 0;
			int n = s.GetNumCiudades();
			for (int i = 0 ; i < n-1 ; i++) {
				suma_dist += Distancia(s.ciudad(i),s.ciudad(i+1));
			}
			suma_dist += Distancia(s.ciudad(n-1),s.ciudad(0));
			return suma_dist;
		}
		

		Problema& Problema::operator=(const Problema &orig) {  //Sobrecarga del operador "="
			if (this != &orig) {
				Liberar() ;
				Reservar() ;
				Copiar(orig) ;
			}

			return *this ;
		}






			

