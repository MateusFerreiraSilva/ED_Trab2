#include"img.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "invalid input\n";
		return 0;
	} // if

	// unsigned char* buffer = NULL;
	// int rows = 1, columns = 1, max = 1;
	// string type = "test";


	// IMG img(type, rows, columns, max, buffer);

	IMG img = read_file(argv[1][0]);
	write_file(img, "aux3.ppm");
	img.free_buffer();

	return 0;
} // main