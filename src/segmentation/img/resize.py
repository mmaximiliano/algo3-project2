import os
import shutil
from PIL import Image

img_src = input('\n')


tams = [(n*20, n*20) for n in range(1, 41)] # Es primero width y despues height


img = Image.open('originales/'+img_src+'.jpg')
for i in range(0, len(tams)):
	r = img.resize(tams[i])
	r.save('originales/'+img_src+'_'+str(i)+'.jpg')

