#include "bellman_ford.h"

using namespace std;

using neigh = pair<int, int>;         //vecino, costo

const int infty = numeric_limits<int>::max() / 2 - 1;
const int none = -1;

int cost(arco x) {return x.peso;}
int to(arco x) {return x.cabeza;}

vector<int> bellman_ford(grafo_ad& G, int salida){
  int r = salida;
  int n = G.cant_nodos;

  //algoritmo de Bellman-Ford
  vector<int> D(n, infty), T(n, none), M(n, false);
  D[r] = 0; bool changed = M[r] = true;
  for(int i = 0; i <= n and changed; ++i) {
    changed = false;
    for(int v = 0; v < n; ++v) if(M[v]) {
      M[v] = false;
      for(auto e: G.lista_ady[v]) if(D[v] + cost(e) < D[to(e)])
      {
        M[to(e)] = changed = true;
        D[to(e)] = D[v] + cost(e);
        T[to(e)] = v;
      }
    }
  }
  return D;
}
