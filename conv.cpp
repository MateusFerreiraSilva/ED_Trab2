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

	FILE *fp = fopen("aux.ppm", "w");
	fprintf(fp, "P6\n%d %d\n255\n", rows, columns);
	fclose(fp); 

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

	fp = fopen("aux.ppm", "ab");
	fwrite(buffer, 1, size, fp);
	fclose(fp);

	free(buffer);

} // binary

int main(int argc, char *agrv[]) {
	binary();
	return 0;
} // main