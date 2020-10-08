#include "img.h"
#include "graph.h"

int main(int argc, const char *argv[]) {
	if(argc != 3) {
		cout << "invalid input\n";
		return 0;
	} // if

	string str = argv[1];
	int x = stoi(str, nullptr);

	IMG img(99, 99); // pss 99 only works to sign ppm, we have to make a function to preread the image and catch data about the size and type
	
	Graph g(99*99, argv[2]);
	g.connectPixels(x);
	g.connectedComponents();

	return 0;
} // main