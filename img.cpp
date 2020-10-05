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

void write_file(IMG img, string filename) {
	
	ofstream ofs(filename, ios_base::out | ios_base::binary);
	ofs << img.type << endl << img.rows << ' ' << img.columns << endl << img.max;

	int aux = 0;
	for(int i = 0; i < img.rows; i++)
		for(int j = 0; j < img.columns; j++)
			for(int k = 0; k < 3; k++)
				ofs << img.buffer[aux++];

    ofs.close();
} // write_file

IMG read_file(char mode) {
	string type;
	int rows, columns, max;

	cin >> type;	
	cin >> rows >> columns >> max;

	unsigned char *buffer;
	int size = rows * columns * 3;
	buffer = (unsigned char*) malloc (sizeof(unsigned char)*size);
	
	if(mode == 'b')
		fread(buffer, sizeof(unsigned char), size, stdin);
	else {
		int aux = 0;
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				for(int k = 0; k < 3; k++)	
					scanf("%hhu", &buffer[aux++]);
	} // else

	return IMG(type, rows, columns, max, buffer);
    
} // read_file