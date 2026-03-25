CXX = g++
CXXFLAGS = -O2 -std=c++17

PYTHIACONFIG = $(shell find ~ -type f -name "pythia8-config" | head -n 1)
PYTHIAFLAGS = $(shell $(PYTHIACONFIG) --cxxflags --libs --ldflags)
ROOTFLAGS   = $(shell root-config --cflags --libs)

SRC = minimum_bias.cc
EXE = minimum_bias

all: $(EXE)

$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE) $(PYTHIAFLAGS) $(ROOTFLAGS)

clean:
	rm -f $(EXE) *.o *.png
