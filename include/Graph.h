#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <map>
#include <Primitivas.h>
#include <string>

class Node {
	std::string id;
	std::string appRef;   // appeareance reference
	std::vector<Primitivas*> primitivas;
	std::map<std::string,Node*> descendencia;
	float matrix[16];
public:
	Node(std::string id);
	std::string getId();
	std::string getAppRef();
	std::vector<Primitivas*>& getPrimitivas();
	std::map<std::string, Node*>& getDescendencia();
	void setMatrix(float matrix[16]);
	void setAppRef(std::string appRef);
	void setId(std::string id);
};

class Graph {

	std::map<std::string, Node*> grafo;
public:
	Graph(){};
	std::map<std::string, Node*>& getGrafo();
	void draw();
};

#endif