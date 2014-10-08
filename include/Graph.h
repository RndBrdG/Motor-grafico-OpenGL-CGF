#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <map>
#include <Primitivas.h>

class Node {
	char* id;
	char* appRef;   // appeareance reference
	std::vector<Primitivas> primitivas;
	float matrix[16];
public:
	Node(char* id);
	char* getId();
	char* getAppRef();
	void setMatrix(float matrix[16]);
	std::vector<Primitivas> getPrimitivas();
};

class Graph {

	std::map<char*, Node> grafo;
public:
	Graph(){};
};

#endif