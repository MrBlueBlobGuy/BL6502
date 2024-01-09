CC = gcc
CXX = g++
CFLAGS = -Wall -g -Isrc -I../bl6502-lib/src/include -Idependencies/gtest/include
LDFLAGS = ../bin/libbl6502.a ../dependencies/gtest/lib/libgtest.a

# Path: src/
SRC = $(wildcard src/*.cpp)

# Path: obj/
OBJ = $(SRC:.cpp=.o)

# Path: bin/
BIN = ../bin/bl6502

# Path: lib/
.PHONY: all clean

all: libs build

libs:
	
	cd ../bl6502-lib && mingw32-make

build: $(OBJ)
	$(CXX) -o $(BIN) $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

