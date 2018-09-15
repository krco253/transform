#Project 1 Makefile
# Executable: transform

EXE=transform
OBJ=transform.o
CFLAGS=-g
SOURCE=transform.c 

$(EXE): $(OBJ)
	gcc $(CFLAGS) -o $(EXE) $(OBJ)
$(OBJ): $(SOURCE)
	gcc $(CFLAGS) -c $(SOURCE)
