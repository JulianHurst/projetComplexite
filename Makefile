CC=gcc
CFLAGS=-W -Wall -pedantic -g -std=c99
EXEC=graph

all: $(EXEC)

graph: graph.o graph_m.o graph_l.o util.o struct.h
	$(CC) -o graph graph_m.o graph_l.o util.o graph.o $(CFLAGS)

graph.o: graph.c graph_m.o graph_l.o
	$(CC) -o graph.o -c graph.c $(CFLAGS)

graph_m.o: graph_m.c
	$(CC) -o graph_m.o -c graph_m.c $(CFLAGS)

graph_l.o: graph_l.c
	$(CC) -o graph_l.o -c graph_l.c $(CFLAGS)

util.o: util.c
	$(CC) -o util.o -c util.c $(CFLAGS)

clean:
	rm -rf *.o

cleanall: clean
	rm -rf graph
