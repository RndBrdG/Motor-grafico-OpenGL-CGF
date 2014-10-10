#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <map>
#include <Primitivas.h>
#include <string>

class Graph;

class Node {
	std::string id;
	std::string appRef;   // appeareance reference
	std::vector<Primitivas*> primitivas;
	std::vector<std::string> descendencia;
	GLfloat matrix[16];
	bool root;
public:
	Node(std::string id);
	std::string getId();
	std::string getAppRef();
	std::vector<Primitivas*>& getPrimitivas();
	std::vector<std::string>& getDescendencia();
	bool getRoot();
	void setMatrix(float matrix[16]);
	void setAppRef(std::string appRef);
	void setId(std::string id);
	void setRoot(bool root);
	void draw(std::map<std::string,Node*>& grafo);
};

class Graph {

	std::map<std::string, Node*> grafo;
	std::string root;
public:
	Graph(){};
	std::map<std::string, Node*>& getGrafo();
	std::string getRoot();
	void draw();
	void setRoot(std::string root);
};

#endif