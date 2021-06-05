CC = gcc

OBJS = ./src/main.c ./src/calendar.c
INCS = -Iinclude
COMP_FLAGS = -lm -Wall

OBJ_NAME = main

all : $(OBJS)
	$(CC) $(OBJS) $(INCS) $(COMP_FLAGS) -o $(OBJ_NAME) 

clean :
	rm $(OBJ_NAME)
