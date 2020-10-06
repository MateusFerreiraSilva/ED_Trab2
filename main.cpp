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

	IMG img = read_file(mode);
	// write_file(img, "aux1.ppm");
	// write_file(img, "aux2.ppm");
	// write_file(img, "aux3.ppm");

	// vector<int> v;
	// seg_img(img, v);
	
	int pixels_size = img.rows * img.columns;
	Graph g(pixels_size, img);
	g.connect_pixels(x);
	g.connectedComponents();

	img.free_buffer();

	return 0;
} // main