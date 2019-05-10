CXX 	:= g++
CXXFLAGS:= -std=c++17 -ofast -Wextra
#Folder
BUILD	:= ./build
APP_DIR	:= $(BUILD)/app
OBJ_DIR	:= $(BUILD)/objects
TARGET	:= ld
SRC	:= $(wildcard src/*.cc) \
	$(wildcard src/graphics/*.cc) \
	$(wildcard src/input/*.cc) \
	$(wildcard src/state/*.cc) \
	$(wildcard src/utils/*.cc) \
	$(wildcard src/event/*.cc) \
	$(wildcard src/entity/*.cc) \
	$(wildcard src/entity/mob/*cc) \
	$(wildcard src/level/*.cc)

INCLUDE := -I src \
	 -I src/graphics \
	 -I src/input \
	 -I src/state \
	 -I src/utils \
	 -I src/event \
	 -I src/entity \
	 -I src/entity/mob \
	 -I src/level

	 
CXXFLAGS += $(shell pkg-config --cflags sdl2)
LDLIBS	 += $(shell pkg-config --libs sdl2)
LDLIBS	 += -lSDL2_image

OBJECTS := $(SRC:%.cc=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LDLIBS) -o $(APP_DIR)/$(TARGET) $(OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -Ofast
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
