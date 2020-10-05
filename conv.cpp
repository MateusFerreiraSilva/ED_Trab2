#include<bits/stdc++.h>
using namespace std;

void binary() {
	string str;
	int rows, columns, max;

	cin >> str;	

	if(!(str == "P6" || str == "P3")) {
		cout << "invalid file format" << endl;
		return;
	} // if

	cin >> rows >> columns >> max;

	int aux, it = 0;
	unsigned char *buffer;
	int size = rows * columns * 3;
	buffer = (unsigned char*) malloc (sizeof(unsigned char) * size);
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			for(int k = 0; k < 3; k++) {
				cin >> aux;
				buffer[it++] = aux; 
			} // for
		} // for
	} // for

	ostream& operator <<(std::ostream &outputStream, const PPMObject &other) {
    outputStream << "P6"     << "\n"
        << rows       << " "
        << columns      << "\n"
        << max   << "\n";
    outputStream.write(other.m_Ptr, size);
    return outputStream;
	}

	// // fp = fopen("aux.ppm", "ab");
	// outfile.write((char*)buffer, size);
	// outfile.close();
	// // fwrite(buffer, 1, size, fp);
	// // fclose(fp);

	// free(buffer);

} // binary

int main(int argc, char *agrv[]) {
	binary();
	return 0;
} // main