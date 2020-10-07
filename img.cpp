#include "img.h"

IMG::IMG(int rows, int columns) {
	this->type = "";
	this->rows = rows;
	this->columns = columns;
	this->max = 0;
	this->size = rows * columns * 3;
	this->buffer = (unsigned char*) malloc(sizeof(unsigned char) * this->size);
	if(this->buffer == NULL)
		fail = 1;
}

IMG::~IMG() { 
    delete buffer; 
} 

void IMG::write_img(string file) {

	ofstream ofs(file, ios_base::out | ios_base::binary);
	ofs << type << endl << rows << ' ' << columns << endl << max;

	for(int i = 0; i < size; i++)
		ofs << buffer[i];

    ofs.close();

	fflush(stdout);

} // write_file

void IMG::read_img(char *file) {
	char t[5]; // type
	int m, trash; // max

	FILE *f = NULL;
	while(true) {
		cout << "reading file...\n";
		if(f != NULL) break;
		f = fopen(file, "r");
	} // while

	fscanf(f, "%s%d%d%d", t, &trash, &trash, &m);

	type = t;
	max = m;
	
	int i = 0;
	while(true) {
		cout << "reading file...\n";
		if(fread(buffer, sizeof(unsigned char), size, f) == size)
			break;
	} // while

	fclose(f);

	cout << "file successful readed\n";

} // read_file

void IMG::seg_img(vector<bool> &points) {
	unsigned char* b = (unsigned char*) calloc(sizeof(unsigned char), size);

	for(int i = 0; i < size; i++)
		if(points[i])
			b[i] = buffer[i];

	memcpy(buffer, b, size);

	free(b);

} // seg_img

void IMG::copy_img(IMG &img) {
	type = img.type;
	max = img.max;

	memcpy(buffer, img.buffer, size);
} // copy_img