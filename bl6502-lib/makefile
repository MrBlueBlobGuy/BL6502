CC = gcc
CXX = g++
CFLAGS = -Wall -g -Isrc/include
LDFLAGS = 

# Path: src/
SRC = $(wildcard src/*.cpp)

# Path: obj/
OBJ = $(SRC:.cpp=.o)

# Path: bin/
BIN = ../bin/libbl6502.a

# Path: lib/
.PHONY: all clean

all: build

build: $(OBJ)
	ar -rc $(BIN) $(OBJ)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

