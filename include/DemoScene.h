#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "CGFscene.h"
#include "CGFshader.h"
#include "Graph.h"
#include "XMLScene.h"

class DemoScene : public CGFscene {
	friend class TPinterface;
public:
	void init();
	void display();
	void update(unsigned long t);
	void activateCamera(int id);
	const Graph& getElementos();
	vector<Camera*>& getCamaras();

	DemoScene(char* filename);
	~DemoScene();
private:
	XMLScene parser;
	Graph elementos;
	vector<Camera*> camaras;
};

#endif
