#include "res/parserFunctions.h"


void parserGlobalCulling(){

	TiXmlElement* cullingElement = globElement->FirstChildElement("culling");
	if (cullingElement)
	{
		char *face = NULL, *order = NULL;

		face = (char *) cullingElement->Attribute("face");
		order = (char *) cullingElement->Attribute("order");

		if (face != NULL && order != NULL){
			printf("  culling attributes: %s %s\n", face, order);
		}
		else
			printf("Error parsing culling\n");
	}
	else
		printf("culling not found\n");

}

void parserGlobalLighting(){
	TiXmlElement* lightingElement = globElement->FirstChildElement("lighting");
	if (lightingElement) {
		char *doublesided = NULL, *local = NULL, *enabled = NULL, *ambient = NULL;
		float r, g, b, a;

		doublesided = (char *) lightingElement->Attribute("doublesided");
		local = (char *) lightingElement->Attribute("local");
		enabled = (char *) lightingElement->Attribute("enabled");
		ambient = (char *) lightingElement->Attribute("ambient");

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