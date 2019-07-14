import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
sns.set()

#grafico complejidad de exp
df = pd.read_csv("tiempos_exp_1.csv")

# Nano -> Milli
df['d']  /= 1000000.0
df['dp']  /= 1000000.0
df['bf']  /= 1000000.0
df['fw']  /= 1000000.0

#r = np.corrcoef(df['time'], df['teorica'])[0,1]
#print(r)
# out: r = 0.9999204732522591


df.plot('ciudades', ['d', 'dp', 'bf'])
df.plot('ciudades', ['d', 'dp', 'bf', 'fw'])

#ax1 = sns.lmplot(x='rutas', y='d', data=df);
#ax1 = sns.lmplot(x='rutas', y='dp', data=df);
#ax1 = sns.lmplot(x='rutas', y='bf', data=df);
#ax1 = sns.lmplot(x='rutas', y='fw', data=df);
plt.xlabel("ciudades");
plt.ylabel("tiempo");

plt.show()
