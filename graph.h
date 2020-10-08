#include "img.h"

#ifndef G
#define G

class Graph { 
    int V;    
    list<int> *adj; // adjacency list with set
  
	void addEdge(int v, int w); 
    void DFS(int v, vector<bool> &visited, list<int> &points);
    bool isConnected(int v); 
	public:
		IMG *img;
		
	    Graph(int V, IMG &img);
	    ~Graph(); 
	    void connectPixels(int x);
	    void connectedComponents();
};

#endif