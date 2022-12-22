# Macros ------------------------------------------------

CC=gcc # for c
AR=ar # for static libraries 
MAIN=main.o
FLAGS=-Wall

# Targets -----------------------------------------------

all: isort txtfind

isort: $(MAIN) isort.a # the main file. using the static liabrary
	$(CC) $(FLAGS) -o isort $(MAIN) my_mat.a -lm

isort.a: isort.o # makes the static liabrary from the object file
	$(AR) -rcs isort.a isort.o

$(MAIN): main.c isort.h # the main object file
	$(CC) $(FLAGS) -fPIC -c main.c -lm

isort.o: isort.c isort.h # makes the object file from the source file
	$(CC) $(FLAGS) -fPIC -c isort.c isort.h -lm

.PHONY: clean all

clean:
	rm -f *.a *.o  isort txtfind