#include "funciones_auxiliares.h"

grafo_ad crear_grafo_modificado(){
  grafo_ad G;
  int ciudades;
  int rutas;
  int precio_nafta;

  cin >> ciudades >> rutas;

  for(int i = 0; i < ciudades; i++){
    cin>>precio_nafta;
    G.agregar_nodo();
    for(int j = 1; j < 61; j++){
      G.agregar_nodo();
      G.agregar_eje(precio_nafta, 61*i+j-1, 61*i+j); //aristas tipo A
    }
  }

  int a, b, l;
  for(int i = 0; i < rutas; i++){
    cin>>a>>b>>l;
    for(int j = 0; j < 61; j++){
      if (j-l >= 0){
        G.agregar_eje(0,a*61+j,b*61+(j-l)); //aristas tipo B
        G.agregar_eje(0,b*61+j,a*61+(j-l));
      }
    }
  }

  return G;
}

void imprimir_resultado(vector<vector<int> >& distancias){
  for(int i = 0; i < distancias.size(); i++){
    for(int j = 0; j < distancias.size() ; j++){
      if(i != j) cout<<i<<' '<<j<<' '<<distancias[i][j]<<'\n';
    }
  }
}

void imprimir_resultado_floyd(vector<vector<int> >& distancias){
  for(int i = 0; i < distancias.size(); i+=61){
    for(int j = 0; j < distancias.size() ; j+=61){
      if(i != j) cout<<i/61<<' '<<j/61<<' '<<distancias[i][j]<<'\n';
    }
  }
}
