import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import scipy.optimize as optimization
from scipy.stats.stats import pearsonr
import csv

sns.set()

def costoTeorico(x, a, b):
    return a*x+b

data = np.array(list(csv.reader(open("exp_tiempo.csv", 'r')))).astype("float") 

n = np.array([(n*20)**2 for n in range(1,41)])

parametros, covar = optimization.curve_fit(costoTeorico, n, data[:,0])


plt.xlabel("Cantidad de vertices")
plt.ylabel("Tiempo (ms)")
plt.plot(n, data[:,0], linewidth=2.5, color="coral", label= "Algoritmo de Felzenszwalb")
plt.plot(n, (costoTeorico)(n, (parametros)[0], (parametros)[1]), linewidth=2.5, color="cornflowerblue", linestyle='--' , label= str(round(parametros[0],2))+'$n+$'+str(round(parametros[1],2)))
plt.xscale('log')
plt.legend()
plt.savefig("../../../informe/segmentation/plots/tiempo_Felzen.pdf", bbox_inches='tight')
plt.clf()

plt.xlabel("Algoritmo de Felzenszwalb")
plt.ylabel("Costo teórico")
plt.scatter(data[:,0], (costoTeorico)(n, (parametros)[0], (parametros)[1]), color="darksalmon")
plt.title("Coeficiente de Pearson: "+str(pearsonr(data[:,0], (costoTeorico)(n, (parametros)[0], (parametros)[1]))[0]))
plt.savefig("../../../informe/segmentation/plots/Felzen_corr.pdf", bbox_inches='tight')
plt.clf()