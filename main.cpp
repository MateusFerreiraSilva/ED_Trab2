#include "img.h"
#include "graph.h"

int main(int argc, const char *argv[]) {
	if(argc != 3) {
		cout << "invalid input\n";
		return 0;
	} // if

	string str = argv[1];
	int x = stoi(str, nullptr);

	Graph g(argv[2]);
	g.connectPixels(x);
	g.connectedComponents();

	return 0;
} // main