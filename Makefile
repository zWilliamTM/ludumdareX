CXX=g++
CPPFLAGS=-std=c++17 -ofast -Wextra

MAIN=src/*.cc \
	 src/graphics/*.cc \
	 src/input/*.cc \
	 src/state/*.cc

INC= -I src \
	 -I src/graphics \
	 -I src/input \
	 -I src/state

PROJECT=ld

CPPFLAGS += $(shell pkg-config --cflags sdl2)
LDLIBS	 += $(shell pkg-config --libs sdl2)

all: build

build:
	$(CXX) $(MAIN) $(CPPFLAGS) $(LDLIBS) $(INC) -o $(PROJECT) 

