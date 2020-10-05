#include<bits/stdc++.h>
using namespace std;

#ifndef PPM_IMG
#define PPM_IMG

class IMG {
	public:
		string type;
		int rows;
		int columns;
		int max;
		unsigned char* buffer;

		IMG(string type, int rows, int columns, int max, unsigned char* buffer);
		void free_buffer();
};

void write_file(IMG img, string filename);
IMG read_file(char mode);

#endif