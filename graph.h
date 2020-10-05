#include "img.h"


#ifndef G
#define G

class Graph { 
    int V;    
    list<int> *adj;
  
    void DFSUtil(int v, bool visited[]);
    bool is_connected(int v, int w); 
	public:
		IMG *img;
		vector< vector< map<string, unsigned char>>> pixel;

	    Graph(int V, IMG &img);
	    ~Graph(); 
	    void addEdge(int v, int w); 
	    void connect(int x);
	    void connectedComponents();
};

#endif