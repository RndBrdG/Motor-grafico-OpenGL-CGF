#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Camera.h"
#include "CGFappearance.h"
#include "Luz.h"
#include "Primitivas.h"

class Textura {
	std::string id;
	std::string file;
	float texlength_s;
	float texlength_t;
public:
	Textura(std::string id, std::string file, float texlength_s, float texlength_t);
	~Textura();
	std::string getId();
	std::string getFile();
	float getTexLenS();
	float getTexLenT();
};

class Aparencia : public CGFappearance {
	float shininess;
	std::string id;
	std::string textRef;
	float ambient[4];
	float difusa[4];
	float especular[4];
public:
	Aparencia(std::string id, float shininess,string textRef, float ambient[4], float difusa[4], float especular[4]);
	~Aparencia();
	string getId();
	string getTextRef();
};

class Node {
	string id;
	string appRef;   // appeareance reference
	vector<Primitivas*> primitivas;
	vector<string> descendencia;
	GLfloat matrix[16];
	bool root;
public:
	Node(std::string id);
	~Node();
	string getId();
	string getAppRef();
	vector<Primitivas*>& getPrimitivas();
	vector<std::string>& getDescendencia();
	bool getRoot();
	void setMatrix(float matrix[16]);
	void setAppRef(std::string appRef);
	void setId(std::string id);
	void setRoot(bool root);
	void draw(map<string, Node*>& grafo, map<string, Aparencia*>& aparencias, string referenciaApp, map<string, Textura*>& texturas);
};

class Graph {
	map<string, Node*> grafo;
	map<string, Luz*> luzes;
	map<string, Aparencia*> aparencias;
	map<string, Textura*> texturas;
	map<string, Camera*> camaras;
	string root;
	string cameraDefault;
public:
	Graph(){};
	map<string, Node*>& getGrafo();
	map<string, Luz*>& getLuzes();
	map<string, Aparencia*>& getAparencias();
	map<string, Textura*>& getTexturas();
	map<string, Camera*>& getCamaras();
	string getRoot();
	string getCameraDefault();
	void draw();
	void setRoot(string root);
	void setDefaultCamera(string cameraDefault);
};

#endif