#include"img.h"
#include"graph.h"

int main(int argc, char *argv[]) {
	if(argc != 3) {
		cout << "invalid input\n";
		return 0;
	} // if

	string str = argv[1];
	int x = stoi(str, nullptr);

	char mode = argv[2][0];

	IMG img;
	img.read_img(mode);

	// cout << img.rows << endl;
	// cout << img.columns << endl;

	int pixels_size = img.rows * img.columns;
	
	cout << pixels_size << endl;

	Graph g(pixels_size, img);
	cout << "bbbbbbb\n";
	// g.connect_pixels(x);
	// g.connectedComponents();

	return 0;
} // main