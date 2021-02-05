botnet: botnet.o country.o
	gcc botnet.o country.o -o botnet

botnet.o : botnet.c
	gcc -c botnet.c -o botnet.o

country.o : country.c
	gcc -c country.c -o country.o
