OBJS = main.o matrix.o jaco.o gseid.o update.o

Pois: $(OBJS)
	suncc -g -fast $(OBJS) -o Pois -lm

clean: 
	rm -f *.o core

main.o: matrix.h jaco.h gseid.h update.h main.c
matrix.o: matrix.c matrix.h
jaco.o: jaco.c jaco.h update.h
gseid.o: gseid.c gseid.h update.h
update.o: update.c update.h

