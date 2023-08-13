CFLAGS=-g -I ../../include
a.out: TC170406A.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<

clean:
	rm -f *.o
	rm -f a.out