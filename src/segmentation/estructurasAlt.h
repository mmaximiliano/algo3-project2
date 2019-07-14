#include <bits/stdc++.h>

using namespace std;

class disjoint_set_arr
{
private:
	mutable vector<int> arr;
	vector<int> tams;

public:
	~disjoint_set_arr(){};
	disjoint_set_arr(int n)
	{
		arr = vector<int> (n);
		tams = vector<int> (n);
		for(int i=0; i<n; i++) {arr[i]=i; tams[i]=1;}
	}
	
	int find(int v){ return arr[v];}

	int unite(int v, int w)
	{
		int rep_v = find(v);
		int rep_w = find(w);

		int cant=0;
		for (int i = 0; i < arr.size(); ++i)
		{
			if(i!=rep_v && arr[i]==rep_v) arr[i]=rep_w; 
		}

		tams[rep_w]+=tams[rep_v];
		arr[rep_v]=rep_w;
	}

	int tam(int i){ return tams[i];}

	vector<int>& comps(){ return arr;}
};

class disjoint_set_arb
{
private:
	mutable vector<int> arbol;
	vector<int> tams;

public:
	~disjoint_set_arb(){};
	disjoint_set_arb(int n)
	{
		arbol = vector<int> (n);
		tams = vector<int> (n);
		for(int i=0; i<n; i++) {arbol[i]=i; tams[i]=1;}
	}
	
	int find(int v){ return arbol[v]==v ? v : find(arbol[v]);}

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

	void aplanar(){for(int i=0; i<arbol.size(); i++) arbol[i]=find(i);}

	vector<int>& comps(){ return arbol;}
};