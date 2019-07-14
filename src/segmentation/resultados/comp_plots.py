import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import scipy.optimize as optimization
from scipy.stats.stats import pearsonr
import csv

sns.set()


data = np.array(list(csv.reader(open("exp_comp.csv", 'r')))).astype("float") 
n = np.array([(n*20)**2 for n in range(1,41)])

nombres = ["Arreglo", "Arbol", "Arbol con PC"]
colores=['cornflowerblue', 'darksalmon', 'orangered']

plt.xlabel("Cantidad de vertices")
plt.ylabel("Tiempo (ms)")
plt.xscale('log')
for i in range(0,len(nombres)):
	plt.plot(n, data[:,i], linewidth=2.5, color=colores[i], label= nombres[i])
plt.legend()
plt.savefig("../../../informe/segmentation/plots/compEstr.pdf", bbox_inches='tight')
plt.clf()

plt.xlabel("Cantidad de vertices")
plt.ylabel("Tiempo (ms)")
plt.xscale('log')
plt.plot(n, data[:,0], linewidth=2.5, color=colores[0], label= nombres[0])
plt.legend()
plt.savefig("../../../informe/segmentation/plots/arr_solo.pdf", bbox_inches='tight')
plt.clf()

plt.xlabel("Cantidad de vertices")
plt.ylabel("Tiempo (ms)")
plt.xscale('log')
plt.plot(n, data[:,1], linewidth=2.5, color=colores[1], label= nombres[1])
plt.plot(n, data[:,2], linewidth=2.5, color=colores[2], label= nombres[2])
plt.legend()
plt.savefig("../../../informe/segmentation/plots/comp_arbs.pdf", bbox_inches='tight')
plt.clf()