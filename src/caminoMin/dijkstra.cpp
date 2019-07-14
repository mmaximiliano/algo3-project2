#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

//vecino, costo
using neigh = pair<int, int>;
using graph = vector<vector<neigh>>;
//costo, v, w
using bridge = tuple<int,int,int>;

const int none = -1;

int costo(neigh x) {return x.second;}
int vecino(neigh x) {return x.first;}

int main() {
 
  int n, m; cin >> n >> m;
  graph G(n);

  vector<int> precioNafta(n);

  //obtengo el precio de la nafta por ciudad
  for(int i = 0; i < n; ++i) {
    int l; cin >> l;
    precioNafta[i] = l;
  }

  //transformacion de aristas a adyacencias
  for(int i = 0; i < m; ++i) {
    int v, w, c; cin >> v >> w >> c;
    G[v].push_back({w,c});
    G[w].push_back({v,c});
  }
  
  //algoritmo de dijkstra
  int r;  // r es el origen
  for(r = 0; r < n; r++){
    vector<int> T(n, none), D(n); T[r] = r; D[r] = 0;
    priority_queue<bridge> S;
    for(auto x : G[r]) S.push({-costo(x), r, vecino(x)});
    while(not S.empty()) {
      int c, v, w;
      tie(c,v,w) = S.top();
      S.pop();
      if(T[w] == none) {
        T[w] = v; D[w] = -c;
        for(auto x : G[w]) if(T[vecino(x)] == none)
          S.push({c-costo(x), w, vecino(x)}); //le sumo mi distancia y hago push
      }
    }
    
    //output del algoritmo
    //for(int i = 0; i < n; ++i) cout << "T[" << i << "] = " << T[i] << " "; cout << endl;
    for(int i = 0; i < n; ++i) cout << r << ' ' << i << ' ' << D[i] << endl;
  }
  return 0;
}
