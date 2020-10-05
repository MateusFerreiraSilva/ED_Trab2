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


	if(mode == 'b') {
		unsigned char *buffer;
		int size = rows * columns * 3;
		buffer = (unsigned char*) malloc (sizeof(unsigned char)*size);
		fread(buffer, 1, size, stdin);

		int aux = 0;
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				for(int k = 0; k < 3; k++)
					v[i][j][k] = buffer[aux++];

		free(buffer);

	} else {
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				for(int k = 0; k < 3; k++)	
					scanf("%hhu", &v[i][j][k]);

	} // else
		
	//print
	cout << str << endl;
	cout << rows << " " << columns << endl;
	cout << max << endl;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			for(int k = 0; k < 3; k++) {
				printf("%hhu", v[i][j][k]);
				if(k != 2) cout << ' '; 
			} // for
			if(j != columns-1)
				cout << ' ';
			else if(i != rows-1)
				cout << '\n';
		} // for
	} // for

} // read_file

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "invalid input\n";
		return 0;
	} // if

	read_file(argv[1][0]);

	return 0;
} // main