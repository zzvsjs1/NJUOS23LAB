CFLAGS = -std=c17 -Wall -O0 -g


.DEFAULT_GOAL := pstree

pstree.o: pstree.c
	gcc $(CFLAGS) -c pstree.c -o pstree.o

pstree: pstree.o
	gcc $(CFLAGS) pstree.o -o pstree

clean:
	rm -rf *.o pstree