#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <map>
#include <Primitivas.h>
#include <string>

class Graph;

class Componente  {
	std::string type;
	float x1, x2, x3,x4;
public:
	Componente(std::string type, float x1, float x2, float x3,float x4);
	std::string getType();
	float getX1(), getX2(), getX3();
};

class Aparencia {
	float shininess;
	std::string id;
	std::string textRef;
	std::vector<Componente> componentes;
public:
	Aparencia(std::string id, float shininess, std::string textRef);
	std::vector<Componente>& getComponentes();
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
	void draw(std::map<std::string,Node*>& grafo);
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