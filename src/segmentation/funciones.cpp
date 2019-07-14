#include "funciones.h"
imagen leerImagen()
{
	int width,height;
	cin>>width>> height;
	imagen img (height, vector<int> (width));
	int val;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cin>>val;
			img[i][j]=val;
		}
	}

	return img;
}

grafo img_2_sortedGraph(imagen& img)
{
	grafo G;
	G.tam = img.size()*img[0].size();
	vector<list<arco> > ejes (256, list<arco>());
	int height = img.size();
	int width = img[0].size();

	
	int row_size = img[0].size();
	int dif;
	int val;
	for (int i = 0; i < height-1; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			val=img[i][j];
			if(j!=0)
			{
				dif = abs(val - img[i+1][j-1]);
				arco diagIzq(dif, j+i*row_size, (j-1)+(i+1)*row_size);
				ejes[dif].push_back(diagIzq);
			}

			dif = abs(val - img[i+1][j]);
			arco down(dif, j+i*row_size, j+(i+1)*row_size);
			ejes[dif].push_back(down);
			
			if(j!=width-1)
			{
				dif = abs(val - img[i][j+1]);
				arco der(dif, j+i*row_size, j+i*row_size+1);
				ejes[dif].push_back(der);

				dif = abs(val - img[i+1][j+1]);
				arco diagDer(dif, j+i*row_size, j+(i+1)*row_size+1);
				ejes[dif].push_back(diagDer);
			}
		}
	}

	for (int j = 0; j < img[0].size()-1; ++j)
	{
		dif = abs(img[height-1][j] - img[height-1][j+1]);
		arco der(dif, j+(height-1)*row_size, j+1+(height-1)*row_size);
		ejes[dif].push_back(der);
	}

	for (int i = 0; i < ejes.size(); ++i) G.ejes.splice(G.ejes.end(), ejes[i]);

	return G;
}


imagen segmentar(grafo& G, int k, int height, int width)
{
	disjoint_set_PC componentes (G.tam);
	vector<int> internal_difference (G.tam,0);
	int c1;
	int c2;
	for (auto it = G.ejes.begin(); it != G.ejes.end(); ++it)
	{
		arco a = *it;
		c1 = componentes.find(a.cola);
		c2 = componentes.find(a.cabeza);

		int M_int = min(internal_difference[c1]+k/componentes.tam(c1), internal_difference[c2]+k/componentes.tam(c2));

		if(c1!=c2 && a.peso <= M_int)
		{
			int padre = componentes.unite(c1,c2);
			internal_difference[padre] = max(internal_difference[padre], a.peso);
		}
	}
	componentes.aplanar();
	vector<int> img_lineal = componentes.comps();
	imagen img(height, vector<int> (width));
	int pos=0;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			img[i][j]=img_lineal[pos];
			pos++;
		}
	}

	return img;
}

void imprimir(imagen& img)
{

	for (int i = 0; i < img.size(); ++i)
	{
		for (int j = 0; j < img[0].size(); ++j)
		{
			cout<<img[i][j]<< " ";
		}
		cout<<'\n';
	}
}


int cantComps(imagen& img)
{
	unordered_set<int> visto;
	int res=0;
	for (int i = 0; i < img.size(); ++i)
	{
		for (int j = 0; j < img[0].size(); ++j)
		{
			if(visto.count(img[i][j])==0)
			{
				res++;
				visto.insert(img[i][j]);
			}
		}
	}
	return res;
}