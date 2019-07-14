echo Que imagen quiere usar \(debe estar en img/originales, escribir nombre sin extension\)
read archivo

if [[ ! -f img/txts/$archivo.txt ]]; then
	echo
	echo Pasando a escala de grises...
	cd img
	echo $archivo | python3 to_grey.py
	cd ..
fi


make clean > /dev/null
make tp > /dev/null

echo Corriendo algoritmo...
cat img/txts/$archivo.txt | bin/tp 30000 > img/$archivo.txt

echo Reconstruyendo imagen...
cd img
echo $archivo | python3 reconstruir.py