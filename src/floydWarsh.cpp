#include <bits/stdc++.h>

using namespace std;

#define null = -1;
using vertice = int;
using eje = pair<int,int>;
using arco = tuple<int,int,int>;
using graph = list<arco>;
using matriz = vector<vector<int>>;


void imprimirVec(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<< " ";
	}
	cout<<endl;
}

matriz floydWarshall(graph& G, int n)
{
	matriz Distancias (n, vector<int> (n, 10000));
	//Inicializacion D^0
	for(int i=0; i<n; i++) Distancias[i][i]=0;
	for(auto it=G.begin(); it!=G.end(); it++) Distancias[get<1>(*it)][get<2>(*it)]= get<0>(*it);
	for(int i=1; i<n; i++) {for(int v=0; v<n; v++){for(int w=0; w<n; w++)
		{
			Distancias[v][w] = min(Distancias[v][w], Distancias[v][i]+Distancias[i][w]); 
		}}}

	return Distancias;

}

int main()
{
	int n;
	cin>>n;
	graph G (n);
	int v,w, peso;
	while(cin>>v>>w>>peso)
	{
		G.push_back({peso, v, w});
	}

	matriz distancias = floydWarshall(G, n);

	for (int i = 0; i < distancias.size(); ++i) imprimirVec(distancias[i]);

	return 0;
}