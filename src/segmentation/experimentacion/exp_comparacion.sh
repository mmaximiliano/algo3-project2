echo Que imagen quiere usar \(debe estar en img/originales, escribir nombre sin extension\)
read archivo

cd ..

make clean > /dev/null
make exp > /dev/null

if [ ! -d "resultados" ]
then
	mkdir resultados
fi
if [ -f resultados/exp_comp.csv ]
then
	rm resultados/exp_comp.csv
fi

echo "Armando imagenes"
cd img
echo $archivo | python3 resize.py

for ((i=0; i<40; i++))
do
	echo "Corriendo para tam "$i 
	echo $archivo'_'$i | python3 to_grey.py
	cat txts/$archivo"_"$i.txt|../bin/comparacion 1000 >> ../resultados/exp_comp.csv
	rm 'originales/'$archivo'_'$i.jpg
	rm 'originales/'$archivo'_'$i'_'grey.png
	rm 'txts/'$archivo'_'$i.txt
done

cd ../resultados
python3 comp_plots.py