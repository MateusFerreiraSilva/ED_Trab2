#include"graph.h"

int similar_color(unsigned char a, unsigned char b, int x) {
    if(a == b) return 1;
    
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
        return 1;

    return 0;

} // similar_color

bool similar_pixel(map<string, unsigned char> &a, map<string, unsigned char> &b, int x) {
    auto colors = {"red", "green", "blue"};

    int cont = 0;
    for(auto c : colors)
        cont += similar_color(a[c], b[c], x);

    if(cont == 3) return true;
    return false;

} // similar_pixel

Graph::Graph(int V, IMG &img) {
    this->V = V; 
    adj = new list<int>[V];
    this->img = new IMG(img.type, img.rows, img.columns, img.max, img.buffer);

    vector<string> colors = {"red", "green", "blue"}; 

    int aux = 0;
    this->pixel.reserve(img.rows);
    for(int i = 0; i < img.rows; i++) {
        this->pixel[i].reserve(img.columns);
        for(int j = 0; j < img.columns; j++) {
            this->pixel[i][j] = {
                {colors[0], img.buffer[aux++]},
                {colors[1], img.buffer[aux++]},
                {colors[2], img.buffer[aux++]},
            };
        } // for
    } // for
} 
  
Graph::~Graph() { 
    delete[] adj;
    delete img; 
} 

void Graph::addEdge(int v, int w) { 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}

bool Graph::is_connected(int v, int w) {
    for(auto it = adj[v].begin(); it != adj[v].end(); it++)
        if(*it == w) return true;
    return false;
} // is_connected

void Graph::connect(int x) {
    int v1 = 0, v2;
    for(int i = 0; i < img->rows; i++) {
        for(int j = 0; j < img->columns; j++) {
            v2 = 0;
            for(int l = 0; l < img->rows; l++) {
                for(int m = 0; m < img->columns; m++) {
                    if(i != l || j != m) { // check if are the same pixel
                        if(is_connected(v1, v2) && similar_pixel(pixel[i][j], pixel[l][m], x)) {
                            this->addEdge(v1, v2);
                        } // if
                    } // if
                    v2++;
                } // for
            } // for
        v1++;
        } // for
    } // for                       
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