edit : main.o Libautonomous.o Libavaliable.o Libmovement.o \
        gcc -o edit main.o Libautonomous.o Libavaliable.o Libmovement.o main

main.o : main.c
        gcc -o main.c
Libautonomous.o :  Libautonomous.c 
		gcc -o Libautonomous.c Libautonomous
Libavaliable.o : Libavaliable.c Libavaliable
        gcc -o Libavaliable.c Libavaliable
# Libinteractive.o : Libinteractive.c
#         gcc -o Libinteractive.c
Libmovement.o : Libmovement.c
        gcc -o Libmovement.c Libmovement

clean :
        rm edit main.o Libautonomous.o Libavaliable.o Libmovement.o