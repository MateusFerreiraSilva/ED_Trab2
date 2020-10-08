#include<bits/stdc++.h>
using namespace std;

#ifndef PPM_IMG
#define PPM_IMG

class IMG {
	public:
		int rows;
		int columns;
		int size;
		unsigned char* buffer;
		int fail = 0;

		IMG(int rows, int columns);
		~IMG();
		void read_img(const char *file);
		void write_img(const char *file, bool flag);
		bool seg_img(vector<bool> &points);
		void copy_img(IMG *img);
};

#endif