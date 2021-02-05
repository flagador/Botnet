botnet: botnet.o country.o
	gcc botnet.o country.o -o botnet

botnet.o : botnet.c
	gcc -c botnet.c -o botnet.o

country.o : country_list.c
	gcc -c country_list.c -o country.o

computer_list.o: computer_list.c computer.c
	gcc -c computer.c computer_list.c -o computer_list.o

computer.o: computer.c
	gcc -c computer.c -o computer.o