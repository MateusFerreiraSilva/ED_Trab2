#include "img.h"


#ifndef G
#define G

class Graph { 
    int V;    
    list<int> *adj;
  
    void DFSUtil(int v, bool visited[]); 
	public:
		IMG *img;

	    Graph(int V, IMG &img);
	    ~Graph(); 
	    void addEdge(int v, int w); 
	    void connectedComponents(); 
};

#endif