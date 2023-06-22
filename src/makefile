# Directories
S_DIR = .
B_DIR = ./bin

# Files
S_FILES = $(S_DIR)/main.cpp

# Output
EXEC = $(B_DIR)/sopia.lxe

# Build settings
CC = g++

# SDL options
CC_SDL= -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf


all: build

build:
	$(CC) $(S_FILES) -o $(EXEC) $(CC_SDL)

run: build
	$(EXEC)

clean:
	rm -rf $(B_DIR)/*
