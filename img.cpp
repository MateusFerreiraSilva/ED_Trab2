#include"img.h"

IMG::IMG() {
	this->type = "";
	this->rows = 0;
	this->columns = 0;
	this->max = 0;
	this->buffer = (unsigned char*) calloc(sizeof(unsigned char), rows*columns*3);
}

IMG::~IMG() { 
	cout << "buffer will dies..\n";
    delete buffer; 
    cout << "buffer ga shinda\n";
} 

void IMG::write_img(string filename) {
	int size = rows * columns * 3;
	
	ofstream ofs(filename, ios_base::out | ios_base::binary);
	ofs << type << endl << rows << ' ' << columns << endl << max;

	for(int i = 0; i < size; i++)
		ofs << buffer[i];

    ofs.close();

	//fflush(stdout);

} // write_file

void IMG::read_img(char mode) {
	string t; // type
	int r, c, m; // rows, columns, max

	cin >> t;	
	cin >> r >> c >> m;

	type = t;
	rows = r;
	columns = c;
	max = m;
	int size = rows * columns * 3;	
	
	if(mode == 'b')
		fread(buffer, sizeof(unsigned char), size, stdin);	
	else
		for(int i = 0; i < size; i++)
			scanf("%hhu", &buffer[i]);		

} // read_file

void IMG::seg_img(vector<bool> &points) {
	int size = rows * columns * 3;

	for(int i = 0; i < size; i++)
		if(points[i])
			buffer[i] = 0;

} // seg_img

void IMG::copy_img(IMG &img) {
	type = img.type;
	rows = img.rows;
	columns = img.columns;
	max = img.max;

	int size = rows * columns * 3;

	// for(int i = 0; i < size; i++)
	// 	buffer[i] = img.buffer[i];

	// printf("%hhu %hhu", img.buffer[0], img.buffer[9]);

} // copy_img