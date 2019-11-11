default: prog

prog:
	gcc -Wall -std=c99 -o testme testme.c -fpic -coverage -lm
	./testme
	gcov testme.c -b -f

clean:
	rm testme testme.c.gcov testme.gcda testme.gcno