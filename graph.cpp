#include"graph.h"

Graph::Graph(int V, IMG &img) {
    this->V = V; 
    adj = new list<int>[V];
    this->img = new IMG(img.type, img.rows, img.columns, img.max, img.buffer);
} 
  
Graph::~Graph() { 
    delete[] adj;
    delete img; 
} 

void Graph::addEdge(int v, int w) { 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 

void Graph::connectedComponents() { 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) { 
        if (visited[v] == false) { 
            DFSUtil(v, visited); 
  
            cout << "\n"; 
        } // if
    } // for
    delete[] visited; 
} 
  
void Graph::DFSUtil(int v, bool visited[]) { 
    visited[v] = true; 
    cout << v << " "; 
  
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
}