#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <random>
#include "Punto.h"
#include "Problema.h"
#include "Solucion.h"
#include <chrono>


using namespace std ;

ostream& Solucion::operator<< (ostream &flujo, const Solucion& orig) { //Sobrecarga del operador "<<"
			for(int i=0; i< orig.GetNumCiudades(); i++){
				flujo<< orig.Recorrido[i] << ", "
			}
			flujo<<endl;
			return flujo ;
		}

bool Ciudad_encontrada(int *vec, int ciudad, int num_ciudades){ //Funcion que sirve para comprobar si un numero esta en un vector y devuelve un booleano
	bool encontrado = false ;	
	for(int i=0; i< num_ciudades && !encontrado; i++){
		if(vec[i] == ciudad)
			encontrado = true ;
	}
	return encontrado;
}

void VecinoMasCercano(const Problema & p, int inicio, const Solucion & sol, int & longi){ //Funcion creadorea de una solucion dada una ciudad incial
	//Reserva de memoria y incializacion de variables
	int n = p.Tamanio(); 
	int *vec_ciudades;
	vec_ciudades=new int[n];
	//variables para los bucles
	int ciudad_paso=inicio;
	int dist=99999999;
	int cont_ciudades=0;
	vec_ciudades[cont_ciudades]=inicio;
	int ciudad_i=inicio;

	//Bucles anidados usados para recorres las cuidades varias veces
	for(int i=0;i<n-1;i++){	//Bucle for que sirve para que recorra todas las ciudades
		for(int j=0;j<n;j++){ //Bucle for que sirve para recorrer el numero de ciudades
		
			bool dis = p.Distancia(ciudad_i,j)>0 ;
			bool ciu = !Ciudad_encontrada(vec_ciudades,j,cont_ciudades) ;
			bool dis2 = p.Distancia(ciudad_i,j) < dist ;
	
			if(dis && ciu  && dis2){ 
				dist=p.Distancia(ciudad_i,j);
				ciudad_paso=j;	
			}				  
		}
		
		dist=999999; //devolvemos distancia al valor max
		//Aumentamos el contador en una unidad y guardamos la ciudad en el vector 
		cont_ciudades++;		
		vec_ciudades[cont_ciudades]=ciudad_paso;
		ciudad_i=ciudad_paso;	
		
	}
	//Creamos una solucion y calculamos la longitud del recorrido
	Solucion sol_copia(vec_ciudades,n);
	//sol= sol_copia;
	longi= p.longitudRecorrido(sol_copia);
	delete [] vec_ciudades; //liberamos la memoria dinamica
}

int main(int argc, char* argv[]){
	srand (time(NULL)); //Semilla aleatoria
	
	if(argc==2){
		fstream fi;
		
		open.fi ("listado.tsp")
		if(fi){
			fi.ri
			
			
		}
		
	};
	
	if(argc ==3){
		
		
	}
	
	Problema problem(argv[1]); //Declarion de problema
	int num_ciudades=problem.Tamanio(); //Declariacion de varuables
	Solucion sol(num_ciudades);
	int longi= 0 ;
	int longi_total= 0;
	int fin=0;
	//string solu;
	VecinoMasCercano(problem, 0, sol, longi);
	longi_total= longi;
	
	for(int i=1;i<num_ciudades;i++){  //Bucle que calcula la solución con la longitud más corta
		VecinoMasCercano(problem, i, sol, longi);
		if(longi < longi_total){ //Filtro para sacar el recorrido mas pequeño
			longi_total= longi;
			fin=i;
			
		}
	}
	//solu= to_string(sol);
	//Mostramos la solución más optima
	cout << "Ciudad de inicio del recorrido mas corto "<< fin << endl;
	cout << "El orden de las ciudades segun el recorrido son: "<< endl;
		
	for(int i = 0; i < num_ciudades; i++){
		cout << "Ciudad "<< i << endl;
		cout << problem.Coordenadas(i).GetX()<< endl;
		cout << problem.Coordenadas(i).GetY()<< endl;
			}		
	cout << "Longitud del recorrido" << longi_total << endl;
	
}
