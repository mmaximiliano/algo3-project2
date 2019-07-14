from PIL import Image
from PIL import ImageFilter
import numpy as np

foto = input()

img = Image.open("originales/"+foto+'.jpg')
width, height = img.size


# Convierte a greyscale
img_grey = img.convert('L')
img_grey = img_grey.filter(ImageFilter.GaussianBlur(0.8))
img_grey.save("originales/"+foto+'_grey.png')


# Guardo a txt greyscale values
file = open("txts/"+foto+'.txt', "w+")

dims = np.array([width, height])
values = np.asarray(img_grey.getdata(), dtype=np.int).reshape((img_grey.size[1], img_grey.size[0]))

dims.tofile(file, sep=" ")
file.write('\n')
for v in values:
	v.tofile(file, sep=" ")
	file.write('\n')

file.close()
