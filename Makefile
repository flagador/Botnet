BIN = botnet test_random test_virus test_jeu
OBJ= test_random.o  computer.o country_list.o botnet.o country.o

botnet: botnet.o jeu.o virus.o upgrade.o country_list.o computer_list.o country.o random_lib.o
	gcc botnet.o jeu.o virus.o upgrade.o country_list.o computer_list.o country.o random_lib.o -o botnet -lm


botnet.o : botnet.c country_list.h
	gcc -c botnet.c -o botnet.o

country_list.o : country_list.c country.h
	gcc -c country_list.c -o country_list.o

computer_list.o: computer_list.c computer.h
	gcc -c computer_list.c -o computer_list.o

country.o : country.c computer_list.h
	gcc -c country.c -o country.o

computer.o : computer.c 
	gcc -c computer.c -o computer.o

upgrade.o: upgrade.c
	gcc -c upgrade.c -o upgrade.o

test_random : test_random.o random_lib.o
	gcc random_lib.o test_random.o -o test_random -lm 

test_random.o : test_random.c
	gcc -c test_random.c

random_lib.o : random_lib.c
	gcc -c random_lib.c

test_virus : test_virus.o virus.o country_list.o country.o computer_list.o random_lib.o
	gcc test_virus.o virus.o country_list.o country.o computer_list.o random_lib.o -o test_virus -lm

test_virus.o : test_virus.c
	gcc -c test_virus.c


test_jeu : test_jeu.o jeu.o virus.o upgrade.o country_list.o computer_list.o country.o random_lib.o
	gcc test_jeu.o jeu.o virus.o upgrade.o country_list.o computer_list.o country.o random_lib.o -o test_jeu -lm

test_jeu.o : test_jeu.c
	gcc -c test_jeu.c -o test_jeu.o



clean:
	rm -rf *.o
	rm botnet
	rm test_random


all : $(BIN) $(OBJ)
