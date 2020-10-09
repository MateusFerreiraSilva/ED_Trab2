/**
 * @main.cpp
 * @brief image segmentation with graphs.
 * @author Mateus Ferreira Silva
 * @date 08/10/2020
 **/

#include "graph.h"

int main(int argc, const char *argv[]) {
	
	cout << endl;

	if(argc != 3) {
		cout << "Invalid input\n";
		return 0;
	} // if

	string str = argv[1];
	int x = stoi(str, nullptr);

	Graph g(argv[2]);
	g.connectPixels(x);
	g.connectedComponents();
	cout << "\nExecution successful!\n\n";

	return 0;
} // main