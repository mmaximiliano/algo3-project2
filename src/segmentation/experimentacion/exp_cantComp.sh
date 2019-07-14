cd ..

echo Compilando...
make clean > /dev/null 
make tp > /dev/null

if [ ! -d "resultados" ]
then
	mkdir resultados
fi
if [ -f resultados/exp_cantComp.txt ]
then
	rm resultados/exp_cantComp.txt
fi

cd img
if [ ! -d "txts/BSDS" ]
then
	echo Convirtiendo a txt de imagenes greyscale...
	mkdir txts/BSDS
	for f in originales/BSDS/*.jpg;
	do
		base=$(basename "$f" .jpg)
		echo BSDS/$base | python3 to_grey.py
		rm originales/BSDS/$base'_'grey.png
	done
fi
cd ..

for ((k=2000; k<=12000; k+=500))
do
	echo corriendo para k=$k
	for f in img/originales/BSDS/*.jpg; 
	do
		base=$(basename "$f" .jpg)
		cat img/txts/BSDS/$base.txt | bin/tp $k >> resultados/exp_cantComp.txt
		echo -n ' ' >> resultados/exp_cantComp.txt
	done
	echo  >> resultados/exp_cantComp.txt
done

cd resultados
python3 k_plots.py