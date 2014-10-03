#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include "CGFscene.h"

class XMLScene
{
public:
	XMLScene(char *filename);
	~XMLScene();

	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);

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

protected:
	TiXmlDocument* doc;

	TiXmlElement* globElement; 
	TiXmlElement* camElement;
	TiXmlElement* textsElement;
	TiXmlElement* leavesElement;
	TiXmlElement* nodesElement;
	TiXmlElement* graphElement;
};

#endif