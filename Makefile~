TARGET = program
LIBSRCS	= main.c matrix.c jacobi.c
OBJS	= main.o matrix.o jacobi.o
#XOPTS = -xlic_lib=sunperf

OPT = -g -fast
#PIC = -fPIC

CC	= suncc
CFLAGS = $(OPT)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

clean:	rm -f core core.* $(OBJS) 

main.o: main.c matrix.h jacobi.h
matrix.o: matrix.c matrix.h
jacobi.o: jacobi.c matrix.h jacobi.h

