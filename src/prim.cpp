
#include <bits/stdc++.h>
using namespace std;

#define null = -1;
using vertice = int;
using eje = pair<int,int>;
using arco = tuple<int,int,int>;
using graph = vector<vector<eje> >;

void imprimirVec(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<< " ";
	}
	cout<<endl;
}

//NO FUNCIONA
vector<int> prim_ralo(graph& G, vertice v)
{
	vector<int> arbol (G.size(), -1); arbol[v]=v;
	priority_queue<arco> S;
	for (int i = 0; i < G[v].size(); ++i) S.push(make_tuple(G[v][i].second, G[v][i].first,v));
	for (int i = 0; i < G.size()-1;)
	{
		arco e = S.top(); S.pop();
		if(arbol[get<1>(e)]==-1)
		{
			arbol[get<1>(e)] = get<2>(e); i++;
			for(auto w :G[get<2>(e)]) S.push({w.second, w.first, get<2>(e)});
		}
	}
	return arbol;

}

int main()
{
	int n;
	cin>>n;
	graph G (n);
	int v,w, peso;
	while(cin>>v>>w>>peso)
	{
		G[v].push_back({w,peso});
		G[w].push_back({v,peso});
	}
	cout<<"llego"<<endl;

	vector<int> AGM = prim_ralo(G,0);
	imprimirVec(AGM);

	return 0;
}