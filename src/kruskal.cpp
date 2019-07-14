#include <bits/stdc++.h>

using namespace std;

#define null = -1;
using vertice = int;
using eje = pair<int,int>;
using arco = tuple<int,int,int>;
using graph = list<arco>;


class disjoint_set
{
private:
	mutable vector<int> arbol;

public:
	disjoint_set(int n)
	{
		arbol = vector<int> (n);
		for(int i=0; i<n; i++) arbol[i]=i;
	}
	
	int find(int v){ return arbol[v]==v ? v : arbol[v]=find(arbol[v]);}

	void unite(int v, int w)
	{
		int rep_v = find(v);
		arbol[rep_v]=find(w);
	}
};


graph kruskal(graph& G)
{
	graph AGM;
	disjoint_set conjuntos(G.size());
	G.sort();

	int v, w;
	for(auto it = G.begin(); it!=G.end(); it++)
	{
		v=get<1>(*it);
		w=get<2>(*it);
		if(conjuntos.find(v)!=conjuntos.find(w))
		{
			AGM.push_back(*it);
			conjuntos.unite(v,w);
		}
	}
	return AGM;
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

	graph AGM = kruskal(G);
	for(auto it = AGM.begin(); it != AGM.end(); it++)
	{
		cout<<"( "<< get<0>(*it)<< " " << get<1>(*it)<< " " << get<2>(*it)<< " " << ") ";
	}
	cout<<endl;


	return 0;
}