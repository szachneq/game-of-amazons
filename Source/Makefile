all: a clean

a: main.o libmylib.a#libmylib.a is the dependency for the executable
		gcc -lm -o a main.o -L. -lmylib

main.o : main.c Libinteractive.o Libmovement.o Libavailable.o
		gcc -g -c main.c -o main.o

Libinteractive.o: ../Lib/Libinteractive.c ../Lib/Libinteractive.h
		gcc -g -c ../Lib/Libinteractive.c -o Libinteractive.o

Libavailable.o: ../Lib/Libavailable.c ../Lib/Libavailable.h 
		gcc -g -c ../Lib/Libavailable.c -o Libavailable.o

Libmovement.o: ../Lib/Libmovement.c ../Lib/Libmovement.h 
		gcc -g -c ../Lib/Libmovement.c -o Libmovement.o

libmylib.a: Libinteractive.o Libavailable.o Libmovement.o #let's link library files into a static library
		ar rcs libmylib.a Libinteractive.o Libavailable.o Libmovement.o

libs: libmylib.a

clean:
		rm -f *.o *.a *.gch #This way is cleaner than my moms house