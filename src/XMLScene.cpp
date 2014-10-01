#include "XMLScene.h"

XMLScene::XMLScene(char *filename)
{

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
	/* A FAZER
	textsElement =  dgxElement->FirstChildElement( "lights" );
	leavesElement =  dgxElement->FirstChildElement( "textures" );
	nodesElement =  dgxElement->FirstChildElement( "appearances" );
	graphElement =  dgxElement->FirstChildElement( "graph" );
	*/

	// TAG GLOBAL
	parsingGlobal();

	// TAG CAMERAS
	parsingCamera();

	/*
	// Other blocks could be validated/processed here


	// graph section
	if (graphElement == NULL)
	printf("Graph block not found!\n");
	else
	{
	char *prefix="  -";
	TiXmlElement *node=graphElement->FirstChildElement();

	while (node)
	{
	printf("Node id '%s' - Descendants:\n",node->Attribute("id"));
	TiXmlElement *child=node->FirstChildElement();
	while (child)
	{
	if (strcmp(child->Value(),"Node")==0)
	{
	// access node data by searching for its id in the nodes section

	TiXmlElement *noderef=findChildByAttribute(nodesElement,"id",child->Attribute("id"));

	if (noderef)
	{
	// print id
	printf("  - Node id: '%s'\n", child->Attribute("id"));

	// prints some of the data
	printf("    - Material id: '%s' \n", noderef->FirstChildElement("material")->Attribute("id"));
	printf("    - Texture id: '%s' \n", noderef->FirstChildElement("texture")->Attribute("id"));

	// repeat for other leaf details
	}
	else
	printf("  - Node id: '%s': NOT FOUND IN THE NODES SECTION\n", child->Attribute("id"));

	}
	if (strcmp(child->Value(),"Leaf")==0)
	{
	// access leaf data by searching for its id in the leaves section
	TiXmlElement *leaf=findChildByAttribute(leavesElement,"id",child->Attribute("id"));

	if (leaf)
	{
	// it is a leaf and it is present in the leaves section
	printf("  - Leaf id: '%s' ; type: '%s'\n", child->Attribute("id"), leaf->Attribute("type"));

	// repeat for other leaf details
	}
	else
	printf("  - Leaf id: '%s' - NOT FOUND IN THE LEAVES SECTION\n",child->Attribute("id"));
	}

	child=child->NextSiblingElement();
	}
	node=node->NextSiblingElement();
	}

	}
	*/

	printf("\n\n");
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
