#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	set<int>* adj;

	public:
		Graph(int V);
		~Graph();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new set<int>[V];
}

Graph::~Graph() {
	delete[] adj;
}

int main() {
	int v = 10;
	// cout << "aaaaa\n";
	// Graph g(10);
	// cout << "bbbbbb\n";

	auto aux = new set<int>[v];

}
