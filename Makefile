BIN = botnet test_random 
OBJ= test_random.o  computer.o country.o botnet.o

botnet: botnet.o country.o
	gcc botnet.o country.o -o botnet

botnet.o : botnet.c
	gcc -c botnet.c -o botnet.o

country.o : country_list.c
	gcc -c country_list.c -o country.o

computer_list.o: computer_list.c computer.c
	gcc -c computer.c computer_list.c -o computer_list.o

computer.o : computer.c
	gcc -c computer.c -o computer.o

test_random : test_random.o random_lib.o
	gcc random_lib.o test_random.o -o test_random -lm 

test_random.o : test_random.c
	gcc -c test_random.c

random_lib.o : random_lib.c
	gcc -c random_lib.c


clean:
	rm -rf *.o
	rm botnet
	rm test_random

all : $(BIN) $(OBJ)
