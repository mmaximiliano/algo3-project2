make clean && make tp

for ((k=800; k<=1200; k+=100)) 
do
	echo "k="$k
	cat img/txts/selfi.txt | bin/./tp $k > img/output"_"$k.txt
	cd img
	echo output"_"$k | python3 reconstruir.py
	rm output"_"$k.txt
	cd ..
done