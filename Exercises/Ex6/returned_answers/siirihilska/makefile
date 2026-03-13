files = $(wildcard *.C)
OBJS = $(addsuffix .o,$(basename $(files)))
garbage = $(wildcard *~ *.o eventdict* *.root *.so *.png RandNumbers reading)

ROOTCFLAGS := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --glibs)

CXX = g++

%.o: %.C
	$(CXX) -O -Wall $(ROOTCFLAGS) -c $< -o $@

RandNumbers: RandNumbers.o
	$(CXX) RandNumbers.o  $(ROOTLIBS) -o $@

reading: reading.o
	$(CXX) reading.o $(ROOTLIBS) -o $@

clean:
	rm -f  $(garbage)
