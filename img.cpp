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

    ofs.close();

	// int aux = 0;
	// for(int i = 0; i < img.rows; i++) {
	// 	for(int j = 0; j < img.columns; j++) {
	// 		for(int k = 0; k < 3; k++) {
	// 			printf("%hhu", img.buffer[aux++]);
	// 			if(k < 2) cout << " ";
	// 		} // for
	// 		cout << '\t';
	// 	} // for
	// 	cout << endl;
	// } // for
	
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

IMG copy_img(IMG &img) {
	int size = img.rows * img.columns * 3;
	unsigned char* buffer = (unsigned char*) malloc (sizeof(unsigned char) * size);

	for(int i = 0; i < size; i++)
		buffer[i] = img.buffer[i];

	IMG copy(img.type, img.rows, img.columns, img.max, buffer);

	return copy;
} // copy_img