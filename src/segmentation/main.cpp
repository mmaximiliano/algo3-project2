#include "funciones.h"
int main(int argc, char *argv[])
{

	// int k=atoi(argv[1]);
	int k = 10000;
	imagen img = leerImagen();
	int height=img.size();
	int width=img[0].size();
	
	auto start = chrono::steady_clock::now();
	grafo G = img_2_sortedGraph(img);
	imagen segmentado = segmentar(G, k, height, width);
	auto end = chrono::steady_clock::now();
	auto elapsed = end - start;
	
	// cout << cantComps(segmentado);
	// cout<< elapsed.count() << '\n';
	imprimir(segmentado);

	return 0;
}