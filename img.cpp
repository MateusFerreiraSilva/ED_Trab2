#include "img.h"

IMG::IMG(int rows, int columns) {
	this->type = "";
	this->rows = rows;
	this->columns = columns;
	this->max = 0;
	this->size = rows * columns * 3;
	this->buffer = (unsigned char*) malloc(sizeof(unsigned char) * this->size);
}

IMG::~IMG() { 
	// cout << "buffer will dies..\n";
    delete buffer; 
    // cout << "buffer ga shinda\n";
} 

void IMG::write_img(string file) {

	ofstream ofs(file, ios_base::out | ios_base::binary);
	ofs << type << endl << rows << ' ' << columns << endl << max;

	for(int i = 0; i < size; i++)
		ofs << buffer[i];

    ofs.close();

	//fflush(stdout);

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
	for(int i = 0; i < rows * columns; i++) {
		if(!points[i]) {
			for(int j = 0; j < 3; j++) {
				buffer[i+j] = (unsigned char) 0;
			} // for
		} // if
	} // for
} // seg_img

void IMG::copy_img(IMG &img) {
	type = img.type;
	max = img.max;

	for(int i = 0; i < size; i++)
		buffer[i] = img.buffer[i];
} // copy_img