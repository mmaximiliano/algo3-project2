#ifndef ESTR_H
#define ESTR_H

#include<list>
#include <iostream>
#include <vector>

using namespace std;

using matrix_int = vector<vector<int> >;
extern int infinito;

struct arco{
	int peso;
	int cola;
	int cabeza;

	arco(int p, int v1, int v2){
		peso=p;
		cola=v1;
		cabeza=v2;
	}
};

struct grafo_ad{
	vector<list<arco> > lista_ady;
	int cant_nodos;
	int cant_aristas;
	void agregar_nodo();
	void agregar_eje(int peso, int desde, int hasta);
	grafo_ad(){
		cant_nodos = 0;
		cant_aristas = 0;
	}
};

//no lo usamos
struct ciudades_rutas{
	//representación de ciudades con sus rutas con lista de adyacencias. Cada ciudad además tiene un peso.
	vector<list<arco> > lista_ady;
	vector<int> precios_nafta;
	int cant_ciudades;
	int cant_rutas;
	void agregar_ciudad(int precio_nafta);
	void agregar_ruta(int peso, int desde, int hasta);
	ciudades_rutas(){
		cant_ciudades = 0;
		cant_rutas = 0;
	}
};

//no la usamos
struct grafo_ar{
	list<arco> ejes;
	int cant_aristas;
	int cant_nodos;
	void agregar_nodo();
	void agregar_eje(int peso, int desde, int hasta);
};

//no la usamos
struct grafo_mt{
	vector<vector<int> > matriz_ady;
	int cant_aristas;
	int cant_nodos;
	void agregar_nodo();
	void agregar_eje(int peso, int desde, int hasta);
};


#endif
