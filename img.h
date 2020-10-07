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

		IMG(int rows, int columns);
		~IMG();
		void read_img(char *file);
		void write_img(string file);
		void seg_img(vector<bool> &points);
		void copy_img(IMG &img);
};

#endif