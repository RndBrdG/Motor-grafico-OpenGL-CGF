#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <map>
#include <Primitivas.h>
#include <string>
#include <CGFappearance.h>

class Graph;

class Aparencia : public CGFappearance{
	float shininess;
	std::string id;
	std::string textRef;
	float ambient[4];
	float difusa[4];
	float especular[4];
public:
	Aparencia(std::string id, float shininess, std::string textRef, float ambient[4], float difusa[4], float especular[4]);
};

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
	void draw(std::map<std::string, Node*>& grafo, std::map < std::string, Aparencia*>&aparencias, std::string referenciaApp);
};

class Graph {

	std::map<std::string, Node*> grafo;
	std::map < std::string,Aparencia*> aparencias;
	std::string root;
public:
	Graph(){};
	std::map<std::string, Node*>& getGrafo();
	std::map<std::string,Aparencia*>& getAparencias();
	std::string getRoot();
	void draw();
	void setRoot(std::string root);
};

#endif