CXX = g++
FLAG = -Wall -fPIC

LIBFLAG = -shared

LIB_RECONST = libreconst_track.so
LIB_SIM = libsim_particles.so

all: test_program

$(LIB_RECONST): reconst_track.cpp reconst_track.h
	$(CXX) $(FLAG) $(LIBFLAG) -o $(LIB_RECONST) reconst_track.cpp

$(LIB_SIM): sim_particles.cpp sim_particles.h $(LIB_RECONST)
	$(CXX) $(FLAG) $(LIBFLAG) -o $(LIB_SIM) sim_particles.cpp -L. -lreconst_track -Wl,-rpath,.

test_program: test_program.cpp $(LIB_RECONST) $(LIB_SIM)
	$(CXX) $(FLAG) -o test_program test_program.cpp -L. -lsim_particles -lreconst_track -Wl,-rpath,.

clean:
	rm -f *.o *.so test_program
