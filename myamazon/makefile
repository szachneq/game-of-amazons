CC=gcc
CFLAGS=-I.
DEPS = board_entities.h
OBJ = main.o board.o file_parser.o game.o cli_parser.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~