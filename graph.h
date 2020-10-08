#include "img.h"

#ifndef G
#define G

class Graph { 
    int V;    
    list<int> *adj;
  
	void addEdge(int v, int w); 
    void DFS(int v, vector<bool> &visited, vector<bool> &points);
    bool isConnected(int v); 
	public:
		IMG *img;
		
	    Graph(const char *file);
	    ~Graph(); 
	    void connectPixels(int x);
	    void connectedComponents();
};

#endif