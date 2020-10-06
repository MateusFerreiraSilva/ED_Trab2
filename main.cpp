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
	// write_file(img, "aux3.ppm");
	// IMG copy = copy_img(img);
	int pixels_size = img.rows * img.columns;
	Graph g(pixels_size, img);
	g.connect_pixels(x);
	g.connectedComponents();

	img.free_buffer();
	// copy.free_buffer();

	return 0;
} // main