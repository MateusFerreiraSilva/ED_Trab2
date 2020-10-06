#include"graph.h"

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

bool similar_pixel(map<string, unsigned char> &a, map<string, unsigned char> &b, int x) {
    auto colors = {"red", "green", "blue"};

    int cont = 0;
    for(auto c : colors)
        if(!similar_color(a[c], b[c], x))
            return false;

    return true;

} // similar_pixel

Graph::Graph(int V, IMG &img) {
    this->V = V;
    this->img.copy_img(img);

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
    // adjacency_list_free(adj);
}

void Graph::addEdge(int v, int w) { 
    adj[v].insert(w); 
    adj[w].insert(v); 
}

bool Graph::is_connected(int v, int w) {
    if(adj[v].find(w) != adj[v].end()) return true;
    
    return false;
} // is_connected

void Graph::connect_pixels(int x) {
    // cout << "segmenting file..." << endl;
    int v1 = 0, v2;
    for(int i = 0; i < img.rows; i++) {
        for(int j = 0; j < img.columns; j++) {
            v2 = 0;
            for(int l = 0; l < img.rows; l++) {
                for(int m = 0; m < img.columns; m++) {
                    if(i != l || j != m) { // check if are the same pixel
                        if(is_connected(v1, v2)) {
                            v2++;
                            continue;
                        } else if(similar_pixel(pixel[i][j], pixel[l][m], x)) {
                            addEdge(v1, v2);
                        } // else if
                    } // if
                    v2++;
                } // for
            } // for
        v1++;
        } // for
        // cout << "\twait...\n";
    } // for                       
}  

void Graph::connectedComponents() {
    // cout << "making files..." << endl;
    vector<bool> visited(V);
    fill(visited.begin(), visited.end(), false);
    vector<bool> points(V*3);
    fill(points.begin(), points.end(), true);

    string filename = "./SEG/segfile";
    string filetype = ".ppm";
    int filenum = 1;

    for(int v = 0; v < V; v++) { 
        if(visited[v] == false) {
            DFS(v, visited, points);

            string file = filename + to_string(filenum) + filetype;

            IMG new_img;
            new_img.copy_img(img);
            new_img.seg_img(points);
            new_img.write_img(filename); 

            fill(points.begin(), points.end(), true); // reset points
            filenum++;

        } // if
    } // for
} 
  
void Graph::DFS(int v, vector<bool> &visited, vector<bool> &points) { 
    visited[v] = true;
    for(int i = v; i < 3; i++)
        points[i] = false;

    for(auto i = adj[v].begin(); i != adj[v].end(); i++) 
        if(!visited[*i]) 
            DFS(*i, visited, points); 
}