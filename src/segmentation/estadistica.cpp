#include "funciones.h"


bool indiceValido(int i, int j, int height, int width)
{
	return i>=0 and i<height and j>=0 and j<width;
}

bool esBordeDeComponentes(int i, int j, imagen& test)
{
	int height = test.size();
	int width = test[0].size();
	bool distinto=false;
	int k=1;
	for (int ii = i-k; ii <= i+k and !distinto; ++ii)
		{
			for (int jj = j-k; jj <= j+k and !distinto; ++jj)
			{
				if(indiceValido(ii,jj,height,width) && ii!=i && jj!=j)
				{
					if(test[i][j]!=test[ii][jj]) distinto=true;
				}
			}
		}
	return distinto;
}

double F(imagen& test, imagen& GT, int k)
{
	int tp=0; int fp=0; int tn=0; int fn=0;
	int height = test.size();
	int width = test[0].size();
	set<pair<int, int> > vistos;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if(esBordeDeComponentes(i,j,test))
			{
				for (int ii = i-k; ii <= i+k; ++ii)
				{
					for (int jj = j-k; jj <= j+k; ++jj)
					{
						if(indiceValido(ii,jj,height,width) && ii!=i && jj!=j && vistos.count({ii*height+jj, i*height+j})==0 && vistos.count({i*height+j, ii*height+jj})==0)
						{
							if(test[i][j]==test[ii][jj] && GT[i][j]==GT[ii][jj]) tp++;
							else if(test[i][j]==test[ii][jj] && GT[i][j]!=GT[ii][jj]) fp++;
							else if(test[i][j]!=test[ii][jj] && GT[i][j]==GT[ii][jj]) fn++;
							else if(test[i][j]!=test[ii][jj] && GT[i][j]!=GT[ii][jj]) tn++;

							vistos.insert(make_pair(ii*height+jj, i*height+j));
							vistos.insert(make_pair(i*height+j, ii*height+jj));
						}
					}
				}
			}
		}
	}

	double precision = tp/(double)(tp+fp);
	double recall = tp/(double)(tp+fn);
	return (1+pow(2,2))*(precision*recall)/(double)((pow(2,2))*precision+recall);
}


int main(int argc, char *argv[])
{

	int k=atoi(argv[1]);
	int k_ring = atoi(argv[2]);

	imagen img = leerImagen();
	imagen GT = leerImagen();
	
	int height=img.size();
	int width=img[0].size();

	grafo G = img_2_sortedGraph(img);
	imagen segmentado = segmentar(G, k, height, width);

	cout<<F(segmentado, GT, k_ring);
	

	return 0;
}

