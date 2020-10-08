CC = gcc
CFLAGS = -g -Wall -Werror -std=gnu11
LDFLAGS = -g -fsanitize=address
LIBS += -lm

TARGETS = run 
CFILES = onegin_main.c functions.c test.c
HFILES = headers.h
OFILES = $(CFILES: .c=.o)

all: run

run : $(OFILES)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

include deps.make

deps.make : $(CFILES) $(HFILES)
	$(CC) -MM $(CFILES) > deps.make

clean: 
	-rm -f $(TARGETS) *.o deps.make