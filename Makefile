all: prog

prog: main.o img.o graph.o
	g++ -o prog main.o img.o graph.o

graph.o:
	g++ -c graph.cpp

img.o:
	g++ -c img.cpp

main.o:
	g++ -c main.cpp

clean:
	rm -rf *.o
	rm -rf prog
	
reset: clean all

run: prog
	./prog

