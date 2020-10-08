#include "img.h"

IMG::IMG(int rows, int columns) {
	this->type = "";
	this->rows = rows;
	this->columns = columns;
	this->max = 0;
	this->size = rows * columns * 3;
	this->buffer = (unsigned char*) malloc(sizeof(unsigned char) * this->size);
	if(this->buffer == NULL)
		this->fail = 1;
}

IMG::~IMG() { 
    delete buffer;
} 

void IMG::write_img(string file) {
	string r = to_string(rows);
	string c = to_string(columns);
	string m = to_string(max);

	ofstream ofs(file, ios_base::out | ios_base::binary);
	if(ofs.good()) {
		ofs << type << '\n' << r << ' ' << c << '\n' << m;
		// ofs.flush();
	} else { 
		ofs.close();
		cout << "Error writing file " << file << endl;
		return;
	} // else

	for(int i = 0; i < size; i++) {
		if(ofs.good()) {
			ofs << buffer[i];
			// ofs.flush();
		} else { 
    		ofs.close();
			cout << "Error writing file " << file << endl;
			return;
		} // else
	} // for

    ofs.close();

} // write_file

void IMG::read_img(char *file) {
	char t[3], trash[10], m[4];

	FILE *f = NULL;
	while(true) {
		cout << "reading file...\n";
		if(f != NULL) break;
		f = fopen(file, "r");
	} // while

	fscanf(f, "%s%s%s%s", t, trash, trash, m);

	type = t;
	string str = m;
	max = stoi(str, nullptr); 
	
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
	for(int i = 0; i < points.size(); i++)
		if(points[i])
			buffer[i] = 0;
} // seg_img

void IMG::copy_img(IMG &img) {
	type = img.type;
	max = img.max;

	memcpy(buffer, img.buffer, size);
} // copy_img