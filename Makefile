TARGET = program
LIBSRCS	= main.c matrix.c
OBJS	= matrix.o main.o
XOPTS = -xlic_lib=sunperf

OPT = -g -fast
PIC = -fPIC

CC	= suncc
CFLAGS = $(OPT) $(PIC) $(XOPTS)

SOFLAGS = -shared

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJ)


main.o: main.c matrix.h
matrix.o: matrix.c matrix.h

clean:	@/bin/rm -f core core.* $(OBJS) 