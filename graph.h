#include "img.h"

#ifndef G
#define G

class Graph { 
    int V;    
    map<int, set<int>> adj; // adjacency list with set
  
    void DFS(int v, vector<bool> &visited, vector<bool> &points);
    bool is_connected(int v, int w); 
	public:
		IMG img;
		vector< vector< map<string, unsigned char>>> pixel;

	    Graph(int V, IMG &img);
	    ~Graph(); 
	    void addEdge(int v, int w); 
	    void connect_pixels(int x);
	    void connectedComponents();
};

#endif