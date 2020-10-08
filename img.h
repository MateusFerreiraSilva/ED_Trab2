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
		int size;
		unsigned char* buffer;
		int fail = 0;

		IMG(int rows, int columns);
		~IMG();
		void read_img(char *file);
		void write_img(string file);
		void seg_img(list<int> &points);
		void copy_img(IMG &img);
};

#endif