#include "floyd_warshall.h"

using matrix = vector<vector<int> >;

const int none = -1;

vector<vector<int> > floyd_warshall(grafo_ad& G) {
  //transformacion de aristas a adyacencias
  int n = G.cant_nodos;
  int m = G.cant_aristas;

  matrix D(n, vector<int>(n, infinito));  //Matriz de pesos
  matrix P(n, vector<int>(n, none));   //Matriz de caminos
  for(int i = 0; i < m; ++i) {
    int v, w, c;
    D[v][w] = c;
    P[v][w] = v;
  }

  for(int i = 0; i < n; i++){
    for(auto j = G.lista_ady[i].begin(); j != G.lista_ady[i].end(); j++){
      D[i][(*j).cabeza] = (*j).peso;
    }
  }

  for(int v = 0; v < n; ++v) {D[v][v] = 0; P[v][v] = v;}

  //Algoritmo de Floyd-Warshall
  for(int k = 0; k < n; ++k) for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) if(D[i][j] > D[i][k] + D[k][j]) {
      D[i][j] = D[i][k] + D[k][j];
    }
  }

  return D;
}
