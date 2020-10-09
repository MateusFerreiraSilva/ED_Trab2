/**
 * @img.cpp
 * @author Mateus Ferreira Silva
 * @date 08/10/2020
 **/


#include "img.h"

IMG::IMG() {
	this->rows = 0;
	this->columns = 0;
	this->size = 0;
	this->buffer = NULL;
}

IMG::~IMG() { 
    delete buffer;
} 

void IMG::write_img(const char *file, bool flag) {
	FILE *f = fopen(file, "wb");
	if(f == NULL) {
		cout << "Error writing file\n";
		return;
	} else if(flag) { 
		fprintf(f, "P6\n%d %d\n255\n", rows, columns);
  		fwrite(buffer+1, sizeof(unsigned char), size, f); // discart \n
	} // if 
  	else {
  		fprintf(f, "P6\n%d %d\n255", rows, columns);
  		fwrite(buffer, sizeof(unsigned char), size, f);
  	} // else
  	fclose(f);
} // write_file

bool IMG::seg_img(vector<bool> &points) {
	bool flag = false;
	if(points.size() >= 3 && points[0] && points[1] && points[2]) { // in case the first pixel be zero
		flag = true;												// becase the file may interpret as null
	} // if											  
	for(int i = 0; i < size; i++)
		if(points[i])
			buffer[i] = 0;

	return flag;

} // seg_img

void IMG::copy_img(IMG *img) {
	rows = img->rows;
	columns = img->columns;
	size = img->size;
	buffer = (unsigned char*) malloc(sizeof(unsigned char) * size);
	copy(img->buffer, img->buffer+size, buffer);
} // copy_img

void read_img(const char *file, IMG *img) {
	char trash_str[100];

	FILE *f = NULL;
	for(int i = 0; i < 10; i++) {
		cout << "Reading file...\n";
		f = fopen(file, "r");
		if(f != NULL) break;
		else if(i == 9) {
			cout << "Error reading file\n";
			return;
		} // else if
	} // for

	fscanf(f, "%s%d%d%s", trash_str, &img->rows, &img->columns, trash_str); 
	
	img->size = img->rows * img->columns * 3 + 1;
	img->buffer = (unsigned char*) malloc(sizeof(unsigned char) * img->size);

	for(int i = 0; i < 10; i++) {
		if(fread(img->buffer, sizeof(unsigned char), img->size, f) == img->size)
			break;
		else if(i == 9) {
			cout << "Error reading file\n";
			return;
		} // else if
	} // for

	fclose(f);

	cout << "File successful readed\n";

} // read_file