#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"

class XMLScene
{
public:
	XMLScene(char *filename);
	~XMLScene();

	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);
	// globals tag
	void parsingGlobal();
	void parsingGlobalCulling();
	void parsingGloballighting();
	void parsingGlobalGlobals();
	// camera tag
	void parsingCamera();
	void parsingCameraPerspective();
	void parsingCameraOrtho();
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