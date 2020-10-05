all: prog

prog: main.o img.o
	g++ -o prog main.o img.o

img.o:
	g++ -c img.cpp

main.o:
	g++ -c main.cpp

clean:
	rm -rf *.o
	rm -rf prog

run: prog
	./prog

