CFLAGS = -ansi -pedantic -Wall
all: partA 

partA: demo

demo: cs457_crypto.o demo.o
	gcc $(CFLAGS) demo.o cs457_crypto.o;
	./a.out tests/a.txt
cs457_crypto.o: cs457_crypto.h cs457_crypto.c
	gcc $(CFLAGS) -c cs457_crypto.c;

demo.o: cs457_crypto.h demo.c
	gcc $(CFLAGS) -c demo.c;

clean:
	rm *.o
	rm a.out
