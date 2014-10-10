#include "XMLScene.h"

XMLScene::XMLScene(char *filename)
{
	/* Inicializar grafo */
	objetosDaCena = Graph();

	// Read XML from file

	doc = new TiXmlDocument(filename);
	bool loadOkay = doc->LoadFile();

	if (!loadOkay)
	{
		printf("Could not load file '%s'. Error='%s'. Exiting.\n", filename, doc->ErrorDesc());
		exit(1);
	}

	TiXmlElement* dgxElement = doc->FirstChildElement("anf");

	if (dgxElement == NULL)
	{
		printf("Main anf block element not found! Exiting!\n");
		exit(1);
	}

	globElement = dgxElement->FirstChildElement("globals");
	camElement = dgxElement->FirstChildElement("cameras");
	lightsElement = dgxElement->FirstChildElement("lights");
	/* A FAZER
	leavesElement =  dgxElement->FirstChildElement( "textures" );
	nodesElement =  dgxElement->FirstChildElement( "appearances" );
	*/
	graphElement = dgxElement->FirstChildElement("graph");

	parserGlobals();
	parserCameras();
	parserLights();
	parserGraph();
}

XMLScene::~XMLScene()
{
	delete(doc);
}

//-------------------------------------------------------

TiXmlElement *XMLScene::findChildByAttribute(TiXmlElement *parent, const char * attr, const char *val)
// Searches within descendants of a parent for a node that has an attribute _attr_ (e.g. an id) with the value _val_
// A more elaborate version of this would rely on XPath expressions
{
	TiXmlElement *child = parent->FirstChildElement();
	int found = 0;

	while (child && !found)
		if (child->Attribute(attr) && strcmp(child->Attribute(attr), val) == 0)
			found = 1;
		else
			child = child->NextSiblingElement();

	return child;
}
