#include "img.h"
#include "graph.h"

int main(int argc, char *argv[]) {
	if(argc != 3) {
		cout << "invalid input\n";
		return 0;
	} // if

	string str = argv[1];
	int x = stoi(str, nullptr);

	IMG img(99, 99);
	img.read_img(argv[2]);
	// img.write_img("./SEG/test.ppm");

	int pixels = img.rows * img.columns; // vertices of my graph
	
	// Graph g(pixels, img);
	// g.connectPixels(x);
	// g.connectedComponents();

	return 0;
} // main