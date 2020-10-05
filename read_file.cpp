#include<bits/stdc++.h>
using namespace std;

void read_file(char mode) {
	string str;
	int rows, columns, max;

	cin >> str;	

	if(!(str == "P6" || str == "P3")) {
		cout << "invalid file format" << endl;
		return;
	} // if

	cin >> rows >> columns >> max;

	vector<vector<vector<unsigned char>>> v;
	v.reserve(rows);
	for(int i = 0; i < rows; i++) {
		v[i].reserve(columns);
		for(int j = 0; j < columns; j++) {
			v[i][j].reserve(3);
		} // for
	} // for

	ofstream ofs("aux.ppm", ios_base::out | ios_base::binary);
	ofs << "P6" << endl << rows << ' ' << columns << endl << max;


	unsigned char *buffer;
	int size = rows * columns * 3;
	buffer = (unsigned char*) malloc (sizeof(unsigned char)*size);
	fread(buffer, sizeof(unsigned char), size, stdin);

	if(mode == 'b') {
		int aux = 0;
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < columns; j++) {
				for(int k = 0; k < 3; k++) {
					ofs << buffer[aux++];
				} // for
			} // for
		} // for

	} else {
		int aux = 0;
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				for(int k = 0; k < 3; k++)	
					scanf("%hhu", &buffer[aux++]);

	} // else	
    
	free(buffer);
    ofs.close();

} // read_file

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "invalid input\n";
		return 0;
	} // if

	read_file(argv[1][0]);

	return 0;
} // main