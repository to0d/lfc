CFLAGS=-I ../../include/ -g

a.out: TC161029A.o
	gcc -o $@ $^  -std=c99
..c.o:
	gcc -c $<

clean:
	rm -f *.o
	rm -f a.out