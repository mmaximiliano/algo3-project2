#include "dijkstra.h"

int minDistance(vector<int> dist, vector<bool> sptSet){
   // Initialize min value
   int min = infinito;
   int min_index;

   for (int v = 0; v < dist.size(); v++){
     if (sptSet[v] == false && dist[v] <= min){
       min = dist[v], min_index = v;
     }
   }
   return min_index;
}


vector<int> dijkstra(grafo_ad& G, int salida){
    vector<int> dist;

    vector<bool> sptSet; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    std::list<arco>::iterator it;

     // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < G.cant_nodos; i++){
      dist.push_back(infinito);
      sptSet.push_back(false);
    }

     dist[salida] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < G.cant_nodos - 1; count++){
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in the first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (it = G.lista_ady[u].begin(); it != G.lista_ady[u].end(); it++){

         // Update dist[v] only if is not in sptSet, there is an edge from
         // u to v, and total weight of path from src to  v through u is
         // smaller than current value of dist[v]
         if (!sptSet[(*it).cabeza] && dist[u] != infinito && dist[u]+(*it).peso < dist[(*it).cabeza]){
           dist[(*it).cabeza] = dist[u] + (*it).peso;
         }
       }
     }

     return dist;
}



/* vector<int> dijkstra(grafo_ad& G, int salida) {
  vector<int> distancias;
  for(int i = 0; i < G.cant_nodos; i++){
    distancias.push_back(infinito);
  }
  distancias[salida] = 0;
  int desde;
  int hasta;
  int dist;
  int desde_aux;
  int hasta_aux;
  int dist_aux;
  std::list<arco>::iterator it;
  for(int i = 0; i < distancias.size() - 1; i++){
    for(int j = 0; j < distancias.size(); j++){
      if(distancias[j]!=infinito){
        desde_aux = j;
        for(it =  G.lista_ady[j].begin(); it != G.lista_ady[j].end(); it++){
          if(distancias[desde] + (*it).peso < dist_aux){

          }
        }
      }
    }
    distancias[hasta] = dist;
  }
  return distancias;
} */
