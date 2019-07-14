make clean && make tp
cat img/txts/selfi.txt | bin/./tp 1000 > img/output.txt

cd img
echo output | python3 reconstruir.py