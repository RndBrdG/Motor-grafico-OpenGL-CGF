#ifndef DEMOSCENE_H
#define DEMOSCENE_H

#include "CGFscene.h"
#include "CGFshader.h"
#include "Graph.h"
#include "XMLScene.h"

class DemoScene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long t);

	const std::vector<Light*>& getLights();

	DemoScene();
	~DemoScene();
private:
	XMLScene scene;
	Graph desenhar;
	std::vector<Light*> lights;

	CGFobject* obj;
	CGFappearance* materialAppearance;
	CGFappearance* textureAppearance;
	CGFshader* shader;
};

#endif
