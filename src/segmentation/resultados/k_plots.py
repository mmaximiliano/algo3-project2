import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

import csv

sns.set()

data = np.loadtxt("exp_cantComp.txt", dtype='float', delimiter=' ') 

prom = np.mean(data, axis=1)

k = np.array([401+k*20 for k in range(0,data.shape[0])])


d = {'k=2000': data[0,:], 'k=5000': data[5,:], 'k=7500': data[10,:],'k=10000': data[15,:], 'k=12000': data[19,:]}
df = pd.DataFrame(data=d)

plt.xlabel("$k$")
plt.ylabel("Cantidad promedio de componentes")
plt.plot(k, prom, linewidth=2.5, color='cornflowerblue', label="Relación de cantidad de componentes y $k$")
plt.legend()
plt.savefig("../../../informe/segmentation/plots/cantProm_k.pdf", bbox_inches='tight')
plt.clf()

plt.ylabel("Cantidad de componentes")
sns.boxplot(data = df, palette="Blues")
plt.savefig("../../../informe/segmentation/plots/boxplot_k.pdf", bbox_inches='tight')
