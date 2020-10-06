#include"img.h"

IMG::IMG(string type, int rows, int columns, int max, unsigned char* buffer) {
	this->type = type;
	this->rows = rows;
	this->columns = columns;
	this->max = max;
	this->buffer = buffer;
}

void IMG::free_buffer() {
	free(buffer);
}

void write_file(IMG &img, string filename) {
	int size = img.rows * img.columns * 3;
	
	ofstream ofs(filename, ios_base::out | ios_base::binary);
	ofs << img.type << endl << img.rows << ' ' << img.columns << endl << img.max;

	for(int i = 0; i < size; i++)
		ofs << img.buffer[i];

	ofs << flush;

    ofs.close();

} // write_file

IMG read_file(char mode) {
	string type;
	int rows, columns, max;

	cin >> type;	
	cin >> rows >> columns >> max;

	int size = rows * columns * 3;
	unsigned char *buffer;
	buffer = (unsigned char*) malloc (sizeof(unsigned char)*size);
	
	if(mode == 'b')
		fread(buffer, sizeof(unsigned char), size, stdin);
	else {
		for(int i = 0; i < size; i++)
			scanf("%hhu", &buffer[i]);		
	} // else

	return IMG(type, rows, columns, max, buffer);
    
} // read_file

IMG seg_img(IMG *img, list<int> &points) {
	int size = img->rows * img->columns * 3;
	unsigned char* buffer;

	buffer = (unsigned char*) calloc (sizeof(unsigned char), size);
	for(auto p : points) {
		p *= 3;
		for(int i = p; i < p+3; i++)
			buffer[i] = img->buffer[i];
	} // for

	IMG segmented_img(img->type, img->rows, img->columns, img->max, buffer);

	return segmented_img;
} // seg_img