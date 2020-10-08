#include "img.h"
#include "graph.h"

int main(int argc, char *argv[]) {
	if(argc != 3) {
		cout << "invalid input\n";
		return 0;
	} // if

	string str = argv[1];
	int x = stoi(str, nullptr);

	IMG img(63, 63); // pss 99 only works to sign ppm, we have to make a function to preread the image and catch data about the size and type
	img.read_img(argv[2]);

	// img.write_img("blabla.ppm");

	int pixels = img.rows * img.columns; // vertices of my graph
	
	Graph g(pixels, img);
	g.connectPixels(x);
	g.connectedComponents();

	return 0;
} // main