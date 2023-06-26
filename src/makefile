# Directories
S_DIR = .
B_DIR = ./bin

# Files
S_FILES = $(S_DIR)/main.cpp
D_FILES = $(S_DIR)/lib/*

# Output
EXEC = $(B_DIR)/sopia.lxe

# Build settings
CC = g++
CC_FLAGS = -Wall --std=c++11

# SDL options
CC_SDL= -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf


all: build

build: ./include/*
	$(CC) $(CC_FLAGS) $(S_FILES) $(D_FILES) -o $(EXEC) $(CC_SDL)

run: build
	$(EXEC)

clean:
	rm -rf $(B_DIR)/*
