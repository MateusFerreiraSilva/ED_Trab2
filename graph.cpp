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
    i *= 3;
    j *= 3;
    for(int k = 0; k < 3; k++)
        if(!similar_color(buffer[i+k], buffer[j+k], x))
            return false;

    return true;

} // similar_pixel

Graph::Graph(int V, const char *file) {
    this->V = V;
    this->img = new IMG(99, 99);
    this->img->read_img(file);
    this->adj = new list<int>[V];
} // Graph

Graph::~Graph() {
    delete img;
    delete[] adj;
} // ~Graph

void Graph::addEdge(int v, int w) { 
    if(v != w) { // self connections are not allowed here
        adj[v].push_back(w); 
        adj[w].push_back(v);
    } // if 
} // addEdge

bool Graph::isConnected(int v) {
    if(adj[v].empty()) return false;
    
    return true;
} // isConnected

void Graph::connectPixels(int x) {
    int pixels = img->rows * img->columns;

    for(int i = 0; i < pixels; i++) {
        for(int j = 0; j < pixels; j++) {
            if(isConnected(j)) // check if exist a vertice connected to j
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
    vector<bool> points(img->size);

    string filename = "./SEG/segfile";
    string filetype = ".ppm";
    int filenum = 1;

    const char aux[] = "auxfile.ppm";

    img->write_img(aux, false);

    for(int v = 0; v < V; v++) { 
        if(!visited[v]) {
            for(auto p : points) p = true;

            DFS(v, visited, points);

            string str = (filename + to_string(filenum) + filetype);
            auto file = str.c_str();

            IMG new_img(img->rows, img->columns);
            if(new_img.fail) {
                cout << "Erro ao criar arquivo " << filename << endl;
                filenum++;
                continue;
            } // if

            new_img.copy_img(img);
            bool flag = new_img.seg_img(points);
            new_img.write_img(file, flag);

            filenum++;
        } // if
    } // for
} // connectedComponents
  
void Graph::DFS(int v, vector<bool> &visited, vector<bool> &points) { 
    visited[v] = true;
    for(int i = v*3; i < v*3+3; i++)
        points[i] = false;

    for(auto i = adj[v].begin(); i != adj[v].end(); i++) 
        if(!visited[*i]) 
            DFS(*i, visited, points); 
} // DFS