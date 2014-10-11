#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include "CGFscene.h"
#include "Globals.h"
#include "Graph.h"
#include "Light.h"

class XMLScene
{
public:
	XMLScene(char *filename);
	~XMLScene();

	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);

	Globals globalsData;
	std::vector<Light*> lights;
	Graph objetosDaCena;

private:
	// globals tag
	void parserGlobals();
	void parserGlobalsDrawing();
	void parserGlobalsCulling();
	void parserGlobalsLighting();
	// camera tag
	void parserCameras();
	void parserCamerasPerspective();
	void parserCamerasOrtho();
	// lights tag
	void parserLights();
	// Appearances tag
	void parserAppearance();
	// graph tag
	void parserGraph();
	void parserGraphTransforms(Node* novoNode, TiXmlElement *childs);
	void parserGraphAppearanceref(Node* novoNode, TiXmlElement *childs);
	void parserGraphPrimitives(Node* novoNode, TiXmlElement *childs);
	void parserGraphdescendants(Node* novoNode, TiXmlElement *childs);
	void atualizarInserirNode(std::string id, Node* novoNode);
protected:
	TiXmlDocument* doc;
	TiXmlElement* globElement; 
	TiXmlElement* camElement;
	TiXmlElement* lightsElement;
	TiXmlElement* leavesElement;
	TiXmlElement* appsElement;
	TiXmlElement* graphElement;
};

#endif