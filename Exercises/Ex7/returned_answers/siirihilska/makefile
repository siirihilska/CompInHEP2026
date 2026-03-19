CXX = g++
CXXFLAGS = -O2 -std=c++17

PYTHIACONFIG = $(shell find ~ -type f -name "pythia8-config" | head -n 1)
PYTHIAFLAGS = $(shell $(PYTHIACONFIG) --cxxflags --libs --ldflags)
ROOTFLAGS   = $(shell root-config --cflags --libs)

SRC = pythia_run.cpp
EXE = pythia_run

all: $(EXE)

$(EXE): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE) $(PYTHIAFLAGS) $(ROOTFLAGS)

fix_fflags:
	find ~ -path "*/HDECAY/makefile" -exec sed -i -f fix_fflags.sed {} \;

clean:
	rm -f $(EXE) *.o
