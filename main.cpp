#include"img.h"
#include"graph.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "invalid input\n";
		return 0;
	} // if

	IMG img = read_file(argv[1][0]);
	write_file(img, "aux3.ppm");
	IMG copy = copy_img(img);
	Graph g(5, img);

	img.free_buffer();
	copy.free_buffer();

	return 0;
} // main