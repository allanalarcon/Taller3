all: cifrado

cifrado: main.o codificacion.o cifrado.o libcifrado.so
	gcc -Llib/ obj/main.o obj/codificacion.o obj/cifrado.o -lcifrado -o bin/cifrado

main.o: src/main.c
	gcc -Wall -Iinclude/ -c src/main.c -o obj/main.o

codificacion.o: src/codificacion.c
	gcc -Wall -Iinclude/ -c src/codificacion.c -o obj/codificacion.o

cifrado.o: src/codificacion.c
	gcc -Wall -Iinclude/ -c src/cifrado.c -o obj/cifrado.o

libcifrado.so: src/cifrado.c
	gcc -Wall -Iinclude/ -shared -fPIC src/cifrado.c src/codificacion.c -o lib/libcifrado.so

.PHONY: clean
clean:
	rm -rf obj/* bin/* lib/*
