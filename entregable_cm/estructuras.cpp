#include "estructuras.h"

void grafo_ad::agregar_eje(int peso, int desde, int hasta){
  arco e = arco(peso, desde, hasta);
  cant_aristas++;
  lista_ady[desde].push_front(e);
}

void grafo_ad::agregar_nodo(){
  list<arco> l;
  lista_ady.push_back(l);
  cant_nodos++;
}

//no lo usamos
void ciudades_rutas::agregar_ruta(int peso, int desde, int hasta){
  arco e = arco(peso, desde, hasta);
  lista_ady[desde].push_front(e);
  cant_rutas++;
}

//no lo usamos
void ciudades_rutas::agregar_ciudad(int precio_nafta){
  list<arco> l;
  lista_ady.push_back(l);
  precios_nafta.push_back(precio_nafta);
  cant_ciudades++;
}

//no lo usamos
void grafo_ar::agregar_eje(int peso, int desde, int hasta){
  arco e = arco(peso, desde, hasta);
  cant_aristas++;
  ejes.push_front(e);
}

//no lo usamos
void grafo_ar::agregar_nodo(){
  cant_nodos++;
}

//no lo usamos
void grafo_mt::agregar_eje(int peso, int desde, int hasta){
  cant_aristas++;
  matriz_ady[desde][hasta] = peso;
}

//no lo usamos
void grafo_mt::agregar_nodo(){
  for(int i = 0; i < cant_nodos; i++){
    matriz_ady[i].push_back(infinito);
  }
  vector<int> v;
  matriz_ady.push_back(v);
  for(int i = 0; i < cant_nodos + 1; i++){
    matriz_ady[cant_nodos].push_back(infinito);
  }
  cant_nodos++;
}
