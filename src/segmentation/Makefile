tp: main.cpp funciones.cpp funciones.h estructuras.h
	mkdir -p bin
	g++ -g -O3 main.cpp funciones.cpp -o bin/tp

exp: comparacion.cpp funciones.cpp funciones.h estructuras.h estructurasAlt.h
	mkdir -p bin
	g++ -O3 comparacion.cpp funciones.cpp -o bin/comparacion

estad: estadistica.cpp funciones.cpp funciones.h estructuras.h
	mkdir -p bin
	g++ -O3 estadistica.cpp funciones.cpp -o bin/estad


clean:
	rm -r bin/