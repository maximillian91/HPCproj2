TARGET = program
LIBSRCS	= main.c matrix.c jacobi.c
OBJS	= matrix.o main.o jacobi.o
XOPTS = -xlic_lib=sunperf

OPT = -g -fast
PIC = -fPIC

CC	= suncc
CFLAGS = $(OPT) $(PIC) $(XOPTS)

SOFLAGS = -shared

$(TARGET): $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(SOFLAGS) $(OBJS)

clean:	@/bin/rm -f core core.* $(OBJS) 

main.o: main.c matrix.h jacobi.h
matrix.o: matrix.c matrix.h
jacobi.o: jacobi.c matrix.h jacobi.h
