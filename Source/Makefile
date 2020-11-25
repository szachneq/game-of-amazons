LINK_TARGET = test_me.exe

OBJS =  	\
 Libinteractive.o \
 Libavaliable.o \
 Libmovement.o \
 main.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

clean : 
  rm -f $(REBUILDABLES)
  echo Clean done 

all : $(LINK_TARGET)
  echo All done

$(LINK_TARGET) : $(OBJS)
  g++ -g -o $@ $^

%.o : %.cpp
  g++ -g -o $@ -c $<

Main.o : Main.h Libinteractive.h Libavaliable.h Libmovement.h
Libinteractive.o : Libinteractive.h
Libavaliable.o : Libavaliable.h
Libmovement.o : Libmovement.h
