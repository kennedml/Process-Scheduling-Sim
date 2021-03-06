CPP=g++
CFLAGS=-std=c++11 -g -Wall
LDFLAGS=
SOURCES=scheduler.cpp proc_handler.cpp utilities.cpp mfqs_table.cpp mfqs_proc.cpp proc.cpp rts_table.cpp whs_table.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=scheduler

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CPP) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp Makefile
	$(CPP) $(CFLAGS) -c -o $@ $<

%.o: %.cpp %.h Makefile
	$(CPP) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(EXECUTABLE)
