CC = gcc
CFLAGS = -Wall --std=c99 -g
OBJECTS = main.o my_string.o

all: evil_hangman unit_test
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
evil_hangman: generic_vector.o associative_array.o $(OBJECTS)
	$(CC) $(CFLAGS) -o evil_hangman generic_vector.o associative_array.o $(OBJECTS)
my_string.o: my_string.c 
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
unit_test: my_string.o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o
unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
generic_vector.o: generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
associative_array.o: associative_array.c
	$(CC) $(CFLAGS) -c associative_array.c -o associative_array.o
clean:  
	rm unit_test unit_test.o test_def.o associative_array.o generic_vector.o evil_hangman $(OBJECTS)


