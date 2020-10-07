#include "graph.h"

bool similar_color(unsigned char a, unsigned char b, int x) {
    if(a == b) return true;
    
    unsigned char min, max;
    if(a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    } // else

    int aux = max - min;

    if(aux >= 0 && aux <= x)
        return true;

    return false;

} // similar_color

bool similar_pixel(unsigned char* buffer, int i, int j, int x) {
    for(int k = 0; k < 3; k++)
        if(!similar_color(buffer[i+k], buffer[j+k], x))
            return false;

    return true;

} // similar_pixel

Graph::Graph(int V, IMG &img) {
    this->V = V;
    this->img = new IMG(img.rows, img.columns);
    this->img->copy_img(img);
    this->adj = new set<int>[V];
} // Graph

Graph::~Graph() {
    delete img;
    delete[] adj;
} // ~Graph

void Graph::addEdge(int v, int w) { 
    adj[v].insert(w); 
    adj[w].insert(v); 
} // addEdge

bool Graph::isConnected(int v, int w) {
    if(adj[v].find(w) != adj[v].end()) return true;
    
    return false;
} // isConnected

void Graph::connectPixels(int x) {
    int pixels = img->rows * img->columns;

    for(int i = 0; i < pixels; i++) {
        for(int j = 0; j < pixels; j++) {
            
            for(int k = 0; k <= i; k++) // check if exist a vertice connected to j
                if(isConnected(k, j))
                    continue;
            
            if(similar_pixel(img->buffer, i, j, x))
                addEdge(i, j);
        } // for
    } // for

} // connectPixels

void Graph::connectedComponents() {
    cout << "making files..." << endl;
    vector<bool> visited(V);
    fill(visited.begin(), visited.end(), false);
    vector<bool> points(V);

    string filename = "./SEG/segfile";
    string filetype = ".ppm";
    int filenum = 1;

    for(int v = 0; v < V; v++) { 
        if(visited[v] == false) {
            fill(points.begin(), points.end(), false); // reset points

            DFS(v, visited, points);

            string file = filename + to_string(filenum) + filetype;

            IMG new_img(img->rows, img->columns);
            new_img.copy_img(*img);
            new_img.seg_img(points);
            new_img.write_img(file);

            filenum++;
        } // if
    } // for
} // connectedComponents
  
void Graph::DFS(int v, vector<bool> &visited, vector<bool> &points) { 
    visited[v] = true;
    points[v] = true;

    for(auto i = adj[v].begin(); i != adj[v].end(); i++) 
        if(!visited[*i]) 
            DFS(*i, visited, points); 
} // DFS