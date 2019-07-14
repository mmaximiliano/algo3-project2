#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define null = -1;
using vertice = int;
using eje = pair<int,int>;
using arco = tuple<int,int,int>;
using graph = list<arco>;


void imprimirVec(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<< " ";
	}
	cout<<endl;
}


vector<int> bellFord(graph& G, vertice v, int tamGrafo)
{
	vector<int> distancias_i (tamGrafo, INT_MAX); distancias_i[v]=0;
	bool cambio = true;
	int peso, x, y;
	for (int i = 0; i < G.size() && cambio; ++i)
	{
		cambio=false;
		for(auto it=G.begin(); it!=G.end(); it++)
		{
			peso = get<0>(*it);
			x = get<1>(*it);
			y = get<2>(*it);
			if(distancias_i[x]+peso < distancias_i[y]) 
			{
				distancias_i[y] = distancias_i[x]+peso;
				cambio=true;
			}
		}
	}

	if(cambio) cout<< "CICLO DE PESO NEGATIVO"<<endl;
	return distancias_i;
}


int main()
{
	int n,m;
	cin>> n >>m;
	graph G (n);
	int v,w, peso;
	vector<int> precioNafta(n);

  	//obtengo el precio de la nafta por ciudad
  	for(int i = 0; i < n; ++i) 
  	{
    	int l; cin >> l;
    	precioNafta[i] = l;
  	}

  	//obtengo grafo
  	for(int i = 0; i < m; ++i )
	{
		cin>>v>>w>>peso;
		G.push_back({peso, v, w});
	}

	//convierto a grafo completo
	vector<vector<int> > matrizDistancias(n);
	for(int i = 0; i < n; ++i)
	{
		vector<int> distancias = bellFord(G,i,n);
		matrizDistancias[i] = distancias;
	}

	return 0;
}