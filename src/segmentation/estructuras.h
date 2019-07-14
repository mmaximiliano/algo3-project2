#include <bits/stdc++.h>

using namespace std;

#define null = -1;
typedef int vertice;
typedef vector<vector<int> > imagen; 


struct arco
{
	int peso;
	int cola;
	int cabeza;

	arco(int p, int v1, int v2)
	{
		peso=p;
		cola=v1;
		cabeza=v2;
	}
};

struct grafo
{
	list<arco> ejes;
	int tam;
};


class disjoint_set_PC
{
private:
	mutable vector<int> arbol;
	vector<int> tams;

public:
	~disjoint_set_PC(){};
	disjoint_set_PC(int n)
	{
		arbol = vector<int> (n);
		tams = vector<int> (n);
		for(int i=0; i<n; i++) {arbol[i]=i; tams[i]=1;}
	}
	
	int find(int v){ return arbol[v]==v ? v : arbol[v]=find(arbol[v]);}

	int unite(int v, int w)
	{
		int rep_v = find(v);
		int rep_w = find(w);

		int tam_v = tams[rep_v];
		int tam_w = tams[rep_w];

		if(tam_v<tam_w)
		{
			tams[rep_w]+=tams[rep_v];
			arbol[rep_v]=rep_w;
			return rep_w;
		}
		else
		{
			tams[rep_v]+=tams[rep_w];
			arbol[rep_w]=rep_v;
			return rep_v;
		}
	}

	int tam(int i){ return tams[i];}

	void aplanar(){for (int i = 0; i < arbol.size(); ++i) find(i);}

	vector<int>& comps(){ return arbol;}
};


