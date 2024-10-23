GLFWROOT?=$(shell brew --prefix)
MUJOCOPATH?=$(PWD)

CFLAGS=-O2 -I$(MUJOCOPATH)/include -I$(GLFWROOT)/include -pthread
CXXFLAGS=$(CFLAGS) -std=c++17

# Set rpath to look for libraries relative to the executable
ALLFLAGS=$(CXXFLAGS) -L$(MUJOCOPATH)/lib -L$(GLFWROOT)/lib -Wl,-rpath,@loader_path/lib

# Specify the full path to the MuJoCo library
MUJOCO_LIB=$(MUJOCOPATH)/lib/libmujoco.2.2.1.dylib

all:
	clang++ slider_size_program.cc -o slider_size_program
	clang   -c $(CFLAGS) uitools.c
	clang++ -c $(CXXFLAGS) macos_save.mm
	clang++ $(ALLFLAGS) simulate.cc uitools.o macos_save.o $(MUJOCO_LIB) -framework Cocoa -lglfw -o simulate
	rm *.o

clean:
	rm -f slider_size_program simulate *.o