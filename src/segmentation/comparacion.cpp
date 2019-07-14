#include "funciones.h"
#include "estructurasAlt.h"


imagen segmentar_arr(grafo G, int k, int height, int width)
{
    disjoint_set_arr componentes (G.tam);
    vector<int> internal_difference (G.tam,0);
    for (auto it = G.ejes.begin(); it != G.ejes.end(); ++it)
    {
        arco a = *it;
        int c1 = componentes.find(a.cola);
        int c2 = componentes.find(a.cabeza);

        int M_int = min(internal_difference[c1]+k/componentes.tam(c1), internal_difference[c2]+k/componentes.tam(c2));

        if(c1!=c2 && a.peso <= M_int)
        {
            int padre = componentes.unite(c1,c2);
            internal_difference[padre] = max(internal_difference[padre], a.peso);
        }
    }

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
imagen segmentar_arb(grafo G, int k, int height, int width)
{
    disjoint_set_arb componentes (G.tam);
    vector<int> internal_difference (G.tam,0);
    for (auto it = G.ejes.begin(); it != G.ejes.end(); ++it)
    {
        arco a = *it;
        int c1 = componentes.find(a.cola);
        int c2 = componentes.find(a.cabeza);

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


int main(int argc, char *argv[])
{
	int k=atoi(argv[1]);
	imagen img = leerImagen();
	int height=img.size();
	int width=img[0].size();
	grafo G = img_2_sortedGraph(img);

	vector<double> tiempos(3);
	imagen segmentado;

    auto start = chrono::steady_clock::now();
    segmentado = segmentar_arr(G, k, height, width); // ESTE ES CON ARREGLO DE REP
    auto end = chrono::steady_clock::now();
    auto elapsed = end - start;
    tiempos[0] = elapsed.count();

    start = chrono::steady_clock::now();
    segmentado = segmentar_arb(G, k, height, width); //ESTE ES CON ARBOL DE REP
    end = chrono::steady_clock::now();
    elapsed = end - start;
    tiempos[1] = elapsed.count();

	start = chrono::steady_clock::now();
    segmentado = segmentar(G, k, height, width); //ESTE ES CON ARBOL DE REP CON PC
    end = chrono::steady_clock::now();
    elapsed = end - start;
    tiempos[2] = elapsed.count();

    cout<< tiempos[0] << ", " << tiempos[1] << ", " << tiempos[2]<<'\n';
	
	return 0;
}