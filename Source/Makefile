all: a

a: main.o libmylib.a#libmylib.a is the dependency for the executable
		gcc -lm -o a main.o -L. -lmylib
		

main.o : main.c Libinteractive.o Libmovement.o Libmovement.o
		gcc -Wall -g -c main.c -o main.o

Libinteractive.o: ../Lib/Libinteractive.c ../Lib/Libinteractive.h
		gcc -Wall -g -c ../Lib/Libinteractive.c -o Libinteractive.o

Libavaliable.o: ../Lib/Libavaliable.c ../Lib/Libavaliable.h 
		gcc -Wall -g -c ../Lib/Libavaliable.c -o Libavaliable.o

Libmovement.o: ../Lib/Libmovement.c ../Lib/Libmovement.h 
		gcc -Wall -g -c ../Lib/Libmovement.c -o Libmovement.o

libmylib.a: Libinteractive.o Libavaliable.o Libmovement.o #let's link library files into a static library
		ar rcs libmylib.a Libinteractive.o Libavaliable.o Libmovement.o
		

libs: libmylib.a

clean:
		rm -f *.o *.a *.gch #This way is cleaner than your clean