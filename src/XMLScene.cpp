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
	camElement = dgxElement->FirstChildElement( "cameras" );
	/* A FAZER
	textsElement =  dgxElement->FirstChildElement( "lights" );
	leavesElement =  dgxElement->FirstChildElement( "textures" );
	nodesElement =  dgxElement->FirstChildElement( "appearances" );
	graphElement =  dgxElement->FirstChildElement( "graph" );

	*/


	// Init
	// An example of well-known, required nodes

	if (globElement == NULL)
		printf("Global block not found!\n");
	else
	{
		printf("Processing globals init:\n");
		// tag drawing
		TiXmlElement* drawingElement = globElement->FirstChildElement("drawing");
		if (drawingElement)
		{
			char *mode = NULL, *shading = NULL, *bkgValues = NULL;
			float r, g, b, a;

			mode = (char *)drawingElement->Attribute("mode");
			shading = (char *)drawingElement->Attribute("shading");
			bkgValues = (char *)drawingElement->Attribute("background");

			if (mode != NULL && shading != NULL && bkgValues != NULL && sscanf(bkgValues, "%f %f %f %f", &r, &g, &b, &a) == 4){
				printf("  drawing attributes: %s %s\n", mode, shading);
				printf("  background values (RGBA): %f %f %f %f\n", r, g, b, a);
			}
			else
				printf("Error parsing drawing\n");
		}
		else
			printf("drawing not found\n");

		// Tag culling
		TiXmlElement* cullingElement = globElement->FirstChildElement("culling");
		if (cullingElement)
		{
			char *face = NULL, *order = NULL;

			face = (char *)cullingElement->Attribute("face");
			order = (char *)cullingElement->Attribute("order");

			if (face != NULL && order != NULL){
				printf("  culling attributes: %s %s\n", face, order);
			}
			else
				printf("Error parsing culling\n");
		}
		else
			printf("culling not found\n");

	// Tag lighting
	TiXmlElement* lightingElement = globElement->FirstChildElement("lighting");
	if (lightingElement)
	{
		char *doublesided = NULL, *local = NULL, *enabled = NULL, *ambient = NULL;
		float r, g, b, a;

		doublesided = (char *)lightingElement->Attribute("doublesided");
		local = (char *)lightingElement->Attribute("local");
		enabled = (char *)lightingElement->Attribute("enabled");
		ambient = (char *)lightingElement->Attribute("ambient");

		if (doublesided != NULL && local != NULL && enabled != NULL && ambient != NULL && sscanf(ambient, "%f %f %f %f", &r, &g, &b, &a) == 4){
			printf("  lighting attributes: %s %s %s\n", doublesided, local, enabled);
			printf("  background values (RGBA): %f %f %f %f\n", r, g, b, a);
		}
		else
			printf("Error parsing lighting\n");
	}
	else
		printf("lighting not found\n");
	}

	// cam element

	if (camElement == NULL)
		printf("camElement block not found!\n");
	else
	{
		printf("Processing cameras init:\n");

		char *initial = NULL;
		initial = (char *)camElement->Attribute("initial");

		if (initial != NULL){
			printf("  camera attribute: %s\n", initial);
		}
		else
			printf("Error parsing camera\n");

		// tag perspective
		TiXmlElement* perspElement = camElement->FirstChildElement("perspective");
		if (perspElement)
		{
			char *id = NULL, *position = NULL, *target = NULL;
			float near, far, angle, posX, posY, posZ, targetX, targetY, targetZ;

			id = (char *)perspElement->Attribute("id");
			position = (char *)perspElement->Attribute("pos");
			target = (char *)perspElement->Attribute("target");

			if (id != NULL && (perspElement->QueryFloatAttribute("near",&near) == TIXML_SUCCESS) &&
					(perspElement->QueryFloatAttribute("far", &far) == TIXML_SUCCESS) && (perspElement->QueryFloatAttribute("angle", &angle) == TIXML_SUCCESS)
					&& (position != NULL && sscanf(position, "%f %f %f", &posX, &posY, &posZ) == 3) && (target != NULL && sscanf(target, "%f %f %f", &targetX, &targetY, &targetZ) == 3) ){
						printf("\n\n< - - - Values of perspective - - - - >\n");
						printf(" Id : %s", id);
						printf(" Valores >  %f %f %f %f %f %f %f %f", near, far, angle, posX, posY, posZ, targetX, targetY, targetZ );
			}
			else
				printf ( "There was an error reading perspective tag ");
		}

		// tag perspective
		TiXmlElement* orthElement = camElement->FirstChildElement("ortho");
		if (orthElement)
		{
			char *id = NULL, *dir = NULL;
			float near, far, left, right, top, bottom;

			id = (char *)orthElement->Attribute("id");
			dir = (char *)orthElement->Attribute("direction");

			if ( id != NULL && dir != NULL && (orthElement->QueryFloatAttribute("near",&near) == TIXML_SUCCESS) && (orthElement->QueryFloatAttribute("left",&left) == TIXML_SUCCESS)
				&& (orthElement->QueryFloatAttribute("far",&far) == TIXML_SUCCESS) && (orthElement->QueryFloatAttribute("right",&right) == TIXML_SUCCESS)
				 && (orthElement->QueryFloatAttribute("top",&top) == TIXML_SUCCESS) && (orthElement->QueryFloatAttribute("bottom",&bottom) == TIXML_SUCCESS)){
					 printf("\n\n< - - - Values of ortho - - - - >\n");
					 printf(" Id : %s \n", id);
					 printf(" Dir : %s \n", dir);
					 printf(" Valores >>  %f - %f - %f - %f - %f - %f \n", near, far, left, right, top, bottom);
			}
			else
				printf ( " - - -  -> There was an error reading perspective tag ");
		}
	}

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


