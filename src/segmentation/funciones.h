#include "estructuras.h"

imagen leerImagen();
grafo img_2_sortedGraph(imagen& img);
imagen segmentar(grafo& G, int k, int height, int width);
void imprimir(imagen& img);

int cantComps(imagen& img);