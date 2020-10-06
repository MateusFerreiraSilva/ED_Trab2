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

		IMG();
		~IMG();
		void read_img(char mode);
		void write_img(string filename);
		void seg_img(vector<bool> &points);
		void copy_img(IMG &img);
};

#endif