from PIL import Image
import numpy as np
import csv

foto = input("Que imagen queres convertir? (sin extension porfa)")

img = Image.open(foto+'.jpg')


# Convierte a greyscale
img_grey = img.convert('L')
img_grey.save(foto+'_grey.png')
#img_grey.show()

# Guardo a csv greyscale values
value = np.asarray(img_grey.getdata(), dtype=np.int).reshape((img_grey.size[1], img_grey.size[0]))

print(value)
with open("img_pixels.csv", 'w') as f:
    writer = csv.writer(f)
    for v in value:
	    writer.writerow(v)