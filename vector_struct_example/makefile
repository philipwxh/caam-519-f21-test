# set the compiler
CC = gcc

# targets defined below:
# for the executable
main: main_vector_struct.o
$(CC) main_vector_struct.o -o main

# for the object file
main_vector_struct.o: main_vector_struct.c
$(CC) -c main_vector_struct.c

# remove executable and object file
clean:
rm -f main main_vector_struct.o




