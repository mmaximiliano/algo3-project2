from PIL import Image
from PIL import ImageOps
import numpy as np
import random as rand
import os

ruta = input()

componentes = np.loadtxt(ruta+".txt", dtype=int)
height = componentes.shape[0]
width = componentes.shape[1]

exists = os.path.isfile('colores.txt')
if not exists:
	print("Generando colores...")
	f=open("colores.txt", "w")
	for i in range(0, 1920):
		for j in range(0,1920):
			f.write(str(rand.randint(0,255))+", "+str(rand.randint(0,255))+", "+str(rand.randint(0,255))+", 255 \n")

colores = []
with open('colores.txt') as f:
    colores = [tuple(map(int, i.split(','))) for i in f]



img = Image.new('RGB', componentes.shape)
segmentada = img.load()
for i in range(0,height):
	for j in range(0, width):
		segmentada[i,j]=colores[componentes[i,j]]

img = img.rotate(270, expand=True)
img = ImageOps.mirror(img)

img.save("resultados/"+ruta+"_seg.bmp")
