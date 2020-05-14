all: test_esercizio_2

test_esercizio_2: test_esercizio_2.o esercizio_2.o correttore.o
	g++ -o test_esercizio_2 test_esercizio_2.o esercizio_2.o correttore.o

test_esercizio_2.o: test_esercizio_2.c esercizio_2.h 
	g++ -c test_esercizio_2.c
	
esercizio_2.o: esercizio_2.c esercizio_2.h 
	g++ -c esercizio_2.c
	
clean:
	rm -rf test_esercizio_2.o esercizio_2.o *~ test_esercizio_2
