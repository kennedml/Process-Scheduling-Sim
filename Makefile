CPP=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=scheduler.cpp
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=scheduler

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CPP) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c Makefile
	$(CPP) $(CFLAGS) -c -o $@ $<

%.o: %.c %.h Makefile
	$(CPP) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o scheduler 
