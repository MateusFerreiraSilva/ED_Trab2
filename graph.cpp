#include"graph.h"

void segmentation(IMG &img, vector<bool> points) {
    int size = img.rows * img.columns;

    int aux = 0;
    for(int i = 0; i < size; i++) {
        if(!points[i])
            for(int j = 0; j < 3; j++) {
                img.buffer[aux++] = 0;        
        } // for
        else
            aux += 3;
    } // for
}

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
    adj = new set<int>[V];
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
    adj[v].insert(w); 
    adj[w].insert(v); 
}

bool Graph::is_connected(int v, int w) {
    if(adj[v].find(w) != adj[v].end()) return true;
    
    return false;
} // is_connected

void Graph::connect_pixels(int x) {
    cout << "segmenting file..." << endl;
    int v1 = 0, v2;
    for(int i = 0; i < img->rows; i++) {
        for(int j = 0; j < img->columns; j++) {
            v2 = 0;
            for(int l = 0; l < img->rows; l++) {
                for(int m = 0; m < img->columns; m++) {
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
        cout << "\twait...\n";
    } // for                       
}  

void Graph::connectedComponents() {
    cout << "making files..." << endl;
    vector<bool> visited(V);
    fill(visited.begin(), visited.end(), false);
    vector<bool> points(V);
    fill(points.begin(), points.end(), false);
  
    string filename = "segfile";
    string filetype = ".ppm";
    int filenum = 1;

    int cont = 0;
    for (int v=0; v < V; v++) { 
        if (visited[v] == false) {
            DFS(v, visited, points);


            IMG copy = copy_img(*img); 
            segmentation(copy, points);

            string file = filename + to_string(filenum) + filetype;

            // cout << "Case " << cont + 1 << ":\n";

            // cout << img->type << endl;
            // cout << img->rows << endl;
            // cout << img->columns << endl;
            // cout << img->max << endl;
            // cout << "buffer: \n";
            // printf("%hhu\n", img->buffer[0]);
            // printf("%hhu\n", img->buffer[5]);

            // cout << endl << "Copy\n";
            // cout << copy.type << endl;
            // cout << copy.rows << endl;
            // cout << copy.columns << endl;
            // cout << copy.max << endl;
            // cout << "buffer: \n";
            // printf("%hhu\n", copy.buffer[0]);
            // printf("%hhu\n", copy.buffer[5]);

            write_file(copy, file);

            copy.free_buffer();

            filenum++;

        } // if

        // cont++;
        fill(points.begin(), points.end(), false);

    } // for
} 
  
void Graph::DFS(int v, vector<bool> &visited, vector<bool> &points) { 
    visited[v] = true;
    points[v] = true;

    for(auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFS(*i, visited, points); 
}