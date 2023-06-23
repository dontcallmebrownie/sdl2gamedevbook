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

# SDL options
CC_SDL= -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf


all: build

build: ./include/*
	$(CC) $(S_FILES) $(D_FILES) -o $(EXEC) $(CC_SDL)

run: build
	$(EXEC)

clean:
	rm -rf $(B_DIR)/*
