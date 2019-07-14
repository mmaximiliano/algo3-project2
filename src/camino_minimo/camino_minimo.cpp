#include "bellman_ford.h"
#include "dijkstra.h"
#include "dijkstra_cp.h"
#include "floyd_warshall.h"
#include "estructuras.h"
#include "funciones_auxiliares.h"
#include <chrono>

int infinito = 10000000;

int main(){
  grafo_ad G = crear_grafo_modificado();
  vector<vector<int> > distancias;
  string metodo;
  auto start = std::chrono::steady_clock::now();
  auto end = std::chrono::steady_clock::now();
  long long total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

  cout << "Recordar poner método de resoulción al final del archivo: d: dijkstra, dp: dijkstra cola prioridad, bf: ford, fw: floyd" << endl;
  cin >> metodo;
  if(metodo == "d"){
    start = std::chrono::steady_clock::now();
    //llamar dijkstra n veces
    for(int i = 0; i < G.cant_nodos; i+=61){
      vector<int> aux = dijkstra(G, i);
      vector<int> aux2;
      for(int j = 0; j < aux.size(); j+=61){
        aux2.push_back(aux[j]);
      }
      distancias.push_back(aux2);
    }
    end = std::chrono::steady_clock::now();
    total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    cout<<total<<'\n';
    imprimir_resultado(distancias);
  }else if (metodo == "dp"){
    start = std::chrono::steady_clock::now();
    //llamar dijkstra_cp n veces
    for(int i = 0; i < G.cant_nodos; i+=61){
      vector<int> aux = dijkstra_cp(G, i);
      vector<int> aux2;
      for(int j = 0; j < aux.size(); j+=61){
        aux2.push_back(aux[j]);
      }
      distancias.push_back(aux2);
    }
    end = std::chrono::steady_clock::now();
    total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    cout<<total<<'\n';
    imprimir_resultado(distancias);
  }else if(metodo == "bf"){
    start = std::chrono::steady_clock::now();
    //llamar bf n veces
    for(int i = 0; i < G.cant_nodos; i+=61){
      vector<int> aux = bellman_ford(G, i);
      vector<int> aux2;
      for(int j = 0; j < aux.size(); j+=61){
        aux2.push_back(aux[j]);
      }
      distancias.push_back(aux2);
    }
    end = std::chrono::steady_clock::now();
    total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    cout<<total<<'\n';
    imprimir_resultado(distancias);
  }else if(metodo == "fw"){
    start = std::chrono::steady_clock::now();
    //llamar a floyd warshall
    distancias = floyd_warshall(G);
    end = std::chrono::steady_clock::now();
    total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    cout<<total<<'\n';
    imprimir_resultado_floyd(distancias);
  }else{
    cout << "no se ingresó un método válido" << endl;
    return 1;
  }

  return 0;
}
