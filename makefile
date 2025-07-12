

all: lxer_test 

lxer_test: ./main.c misc.o lxer.o
	gcc -I./src $< ./src/lxer.o ./src/misc.o -o $@ 

misc.o: ./src/misc.c ./src/misc.h 
	gcc -I./src -c $< -o src/$@ 

lxer.o: ./src/lxer.c ./src/lxer.h 
	gcc -I./src -c $< -o src/$@ 

