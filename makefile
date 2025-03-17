#------------------------------------------------
# Copyright (C) 2025 杨锦熠 - All Rights Reserved
# Author: 杨锦熠
# Date: Fuburary 2025
#------------------------------------------------
PROG_NAME=Collisions

# Compile settings
CC=gcc
ERR=-Wall
OTM=-O2
DEF=

# Directories settings
INC_DIR=-I include
LIB_DIR=-L lib -L .

# Files settings
OBJS=main.obj
LIBS=-lglew32 -lglfw3 -lopengl32

all: $(PROG_NAME) clean

$(PROG_NAME): main.obj block.obj
	@ $(CC) main.obj block.obj $(LIB_DIR) $(LIBS) $(FUNC_CALL) -o $(PROG_NAME).exe

main.obj:
	@ $(CC) $(DEF) $(ERR) $(OTM) $(INC_DIR) -c src/main.c -o main.obj
	
block.obj:
	@ $(CC) $(DEF) $(ERR) $(OTM) $(INC_DIR) -c src/block.c -o block.obj

clean:
	@ del *.obj