from PIL import Image
from PIL import ImageFilter
import numpy as np

foto = input()

img_GT = Image.open("ground-truth/"+foto+'.png')
img_test = Image.open("test/"+foto+'.jpg')
width, height = img_GT.size

dims = np.array([width, height])

# Convierte a greyscale
GT_grey = img_GT.convert('L')

test_grey = img_test.convert('L')
test_grey = test_grey.filter(ImageFilter.GaussianBlur(0.8))


# Guardo a txt greyscale values
GT_txt = open("txts/GT_txts/"+foto+'.txt', "w+")

values_GT = np.asarray(GT_grey.getdata(), dtype=np.int).reshape((GT_grey.size[1], GT_grey.size[0]))
dims.tofile(GT_txt, sep=" ")
GT_txt.write('\n')
for v in values_GT:
	v.tofile(GT_txt, sep=" ")
	GT_txt.write('\n')

GT_txt.close()

test_txt = open("txts/test_txts/"+foto+'.txt', "w+")
values_test = np.asarray(test_grey.getdata(), dtype=np.int).reshape((test_grey.size[1], test_grey.size[0]))
dims.tofile(test_txt, sep=" ")
test_txt.write('\n')
for v in values_test:
	v.tofile(test_txt, sep=" ")
	test_txt.write('\n')




