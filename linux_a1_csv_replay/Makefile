# This Makefile assumes that you have GLFW libraries and headers installed on,
# which is commonly available through your distro's package manager.
# On Debian and Ubuntu, GLFW can be installed via `apt install libglfw3-dev`.

COMMON=-O2 -I/include -L/lib -std=c++17 -pthread -Wl,-no-as-needed -Wl,-rpath,'$$ORIGIN'/lib
COMMON_DEBUG=-O0 -g -I/include -L/lib -std=c++17 -pthread -Wl,-no-as-needed -Wl,-rpath,'$$ORIGIN'/lib

all:
	g++ slider_size_program.cc                               -o slider_size_program
	$(CC) -c -O2 -I/include uitools.c
	$(CXX) $(COMMON) uitools.o simulate.cc -lmujoco -lglfw   -o simulate

debug:
	$(CC) -c -O0 -g -I/include uitools.c
	$(CXX) $(COMMON_DEBUG) uitools.o simulate.cc -lmujoco -lglfw -o simulate_debug
	rm *.o

clean:
	rm -f slider_size_program simulate *.o

