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

	const Graph& getGraph();
	const std::vector<Light*>& getLights();

	DemoScene();
	~DemoScene();
private:
	XMLScene scene;
	Graph desenhar;
	std::vector<Light*> lights;
};

#endif
