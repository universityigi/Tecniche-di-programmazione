all: test_esercizio_1

test_esercizio_1: test_esercizio_1.o esercizio_1.o correttore.o
	g++ -o test_esercizio_1 test_esercizio_1.o esercizio_1.o correttore.o

test_esercizio_1.o: test_esercizio_1.c esercizio_1.h 
	g++ -c test_esercizio_1.c
	
esercizio_1.o: esercizio_1.c esercizio_1.h 
	g++ -c esercizio_1.c


clean:
	rm -rf test_esercizio_1.o esercizio_1.o *~ test_esercizio_1
