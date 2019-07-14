
if [ ! -d "txts" ]
then
echo Armando archivos txt...
	mkdir txts 
	mkdir txts/GT_txts
	mkdir txts/test_txts
	for f in ground-truth/*.png;
		do
			base=$(basename "$f" .png)
			echo $base | python3 get_txt.py
		done
fi

echo compilando...
cd ..
make clean > /dev/null
make estad > /dev/null

cd estadistica

if [ -f ../resultados/f_scores.txt ]
then 
	rm ../resultados/f_scores.txt
fi

ks=(10000 15000 20000 25000 30000)

echo Computando F1 score...
for k in "${ks[@]}";
do
	echo Valor de k: $k
	for f in txts/GT_txts/*.txt;
	do
		base=$(basename "$f" .txt)
		echo "	Imagen $base"
		cat txts/test_txts/$base.txt txts/GT_txts/$base.txt | ../bin/estad $k 5  >> ../resultados/f_scores.txt
		echo -n ' ' >> ../resultados/f_scores.txt
	done
	echo ' ' >> ../resultados/f_scores.txt
done

