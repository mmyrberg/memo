# -*- Makefile -*-

CC = gcc # define the C compiler to use
CFLAGS = -g -Wall -I. # define compile-time flags, -g adds debugging information, -Wall turns on compiler warnings, -I. gcc will look in the current directory 
DEPS = memo.h # include header file
OBJ = memo.o libmemo.o # include object files
TARGET = memo # the build target

# generate .o files depended on the .c version of the file and the .h files included in the DEPS macro.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

# generate target file from linked .o files
memo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) 

# this command will remove all object files along with TARGET file that is memo (executable)
.PHONY: clean
clean:
	rm *.o $(TARGET)

# this command will remove all csv files generated from program memo.c
cleancsv:
	rm *.csv