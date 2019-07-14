import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

import csv

sns.set()

data = np.loadtxt("f_scores.txt", dtype='float', delimiter=' ') 

d = {'k=10000': data[0,:], 'k=15000': data[1,:], 'k=20000': data[2,:],'k=25000': data[3,:], 'k=30000': data[4,:]}
df = pd.DataFrame(data=d)

std = np.array([np.std(data[i,:]) for i in range(0,5)])
k=[10000, 15000, 20000, 25000, 30000]

# pos, = np.where(data[4,:] == np.min(data[4,:]))
# print(pos)

plt.ylabel("Desviación estandar")
plt.xlabel("$k$")
plt.ylim(0,0.025)
plt.xticks(range(0,5), k)
plt.bar(np.array(range(0,5)), std, width=0.5, color="mediumslateblue")
plt.savefig("../../../informe/segmentation/plots/std_k.pdf", bbox_inches='tight')
plt.clf()

plt.ylabel("$F_2$ Score")
sns.boxplot(data = df, palette="Blues")
plt.savefig("../../../informe/segmentation/plots/fScores_k.pdf", bbox_inches='tight')
