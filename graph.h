#include "img.h"

#ifndef G
#define G

class Graph { 
    int V;    
    set<int> *adj; // adjacency list with set
  
	void addEdge(int v, int w); 
    void DFS(int v, vector<bool> &visited, vector<bool> &points);
    bool isConnected(int v, int w); 
	public:
		IMG *img;
		
	    Graph(int V, IMG &img);
	    ~Graph(); 
	    void connectPixels(int x);
	    void connectedComponents();
};

#endif