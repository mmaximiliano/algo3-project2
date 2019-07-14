#include "dijkstra_cp.h"

//vecino, costo
//using neigh = pair<int, int>;
//costo, v, w
using bridge = tuple<int,int,int>;

const int none = -1;
int costo(arco x) {return x.peso;}
int vecino(arco x) {return x.cabeza;}

vector<int> dijkstra_cp(grafo_ad& G, int salida){
  int r = salida;
  int n = G.cant_nodos;

  //algoritmo de dijkstra
  vector<int> T(n, none), D(n); T[r] = r; D[r] = 0;
  priority_queue<bridge> S;
  for(auto x : G.lista_ady[r]){
    tuple<int, int, int> t{-costo(x), r, vecino(x)};
    S.push(t);
  }
  while(not S.empty()) {
    int c, v, w;
    tie(c,v,w) = S.top();
    S.pop();
    if(T[w] == none) {
      T[w] = v; D[w] = -c;
      for(auto x : G.lista_ady[w]) if(T[vecino(x)] == none){
        tuple<int, int, int> t{c-costo(x), w, vecino(x)};
        S.push(t);
      }
    }
  }

  return D;
}
