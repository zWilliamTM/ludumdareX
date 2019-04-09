CXX=g++
CPPFLAGS=-std=c++17 -ofast -Wextra

MAIN=src/*.cc \
	 src/graphics/*.cc \
	 src/input/*.cc \
	 src/state/*.cc \
	 src/utils/*.cc \
	 src/event/*.cc

INC= -I src \
	 -I src/graphics \
	 -I src/input \
	 -I src/state \
	 -I src/utils \
	 -I src/event

PROJECT=ld

CPPFLAGS += $(shell pkg-config --cflags sdl2)
LDLIBS	 += $(shell pkg-config --libs sdl2)
LDLIBS 	 += -lSDL2_image

all: build

build:
	$(CXX) $(MAIN) $(CPPFLAGS) $(LDLIBS) $(INC) -o $(PROJECT) 

