#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Camera.h"
#include "CGFappearance.h"
#include "Globals.h"
#include "Light.h"
#include "Primitiva.h"

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
	vector<Primitiva*> primitivas;
	vector<string> descendencia;
	GLfloat matrix[16];
	GLuint index;
	bool displayList;
	bool root;
	static bool firstTime;
	static bool controlList; // false se ainda n�o existir lista, true se j� existir.
	bool insideList;
public:
	Node(std::string id);
	~Node();
	string getId();
	string getAppRef();
	vector<Primitiva*>& getPrimitivas();
	vector<std::string>& getDescendencia();
	bool getRoot();
	bool getDisplayList();
	void setDisplayList(bool displayList);
	void setMatrix(float matrix[16]);
	void setAppRef(std::string appRef);
	void setId(std::string id);
	void setRoot(bool root);
	void setIndex(GLuint index);
	void createDisplayList(map<string, Node*>& grafo, map<string, Aparencia*>& aparencias, string referenciaApp, map<string, Textura*>& texturas);
	void draw(map<string, Node*>& grafo, map<string, Aparencia*>& aparencias, string referenciaApp, map<string, Textura*>& texturas);
};

class Graph {
	Globals* globalsData;
	map<string, Camera*> camaras;
	map<string, Light*> luzes;
	map<string, Textura*> texturas;
	map<string, Aparencia*> aparencias;
	map<string, Node*> grafo;
	string root;
	string cameraDefault;
public:
	Graph(){ globalsData = new Globals(); }
	Globals* getGlobalsData();
	map<string, Camera*>& getCamaras();
	map<string, Light*>& getLuzes();
	map<string, Textura*>& getTexturas();
	map<string, Aparencia*>& getAparencias();
	map<string, Node*>& getGrafo();
	string getRoot();
	string getCameraDefault();
	void draw();
	void preencherListas();
	void setRoot(string root);
	void setDefaultCamera(string cameraDefault);
};

#endif
