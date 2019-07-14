#ifndef FAUX_H
#define FAUX_H
#include "estructuras.h"

grafo_ad crear_grafo_modificado(); //para crear directamente el grafo modificado
void imprimir_resultado(vector<vector<int> >& distancias); //imprimir por salida estándar
void imprimir_resultado_floyd(vector<vector<int>>& distancias); //imprimir por salida estándar resultado de floyd

#endif
