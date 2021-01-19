CC=gcc
CFLAGS=-I.
DEPS = board_entities.h
OBJ_AUTONOMOUS = main_autonomous.o board.o file_parser.o game.o cli_parser.o
OBJ_INTERACTIVE = main_interactive.o

.PHONY: default
default: autonomous ;

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

autonomous: $(OBJ_AUTONOMOUS)
	$(CC) -o $@ $^ $(CFLAGS)
	$(MAKE) clean

interactive: $(OBJ_INTERACTIVE)
	$(CC) -o $@ $^ $(CFLAGS)
	$(MAKE) clean

.PHONY: clean

clean:
	rm -f *.o *~