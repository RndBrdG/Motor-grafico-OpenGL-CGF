#include "XMLScene.h"
#include "Globals.h"

void XMLScene::parserGlobals() {
	if (globElement == NULL)
		printf("globals block not found!\n");
	else {
		printf("Processing globals init:\n");

		parserGlobalsDrawing(globalsData);
		parserGlobalsCulling(globalsData);
		parserGlobalsLighting(globalsData);
	}
}

void XMLScene::parserGlobalsDrawing(Globals& globalsData) {	// Tag "drawing"
	TiXmlElement* drawingElement = globElement->FirstChildElement("drawing");
	if (drawingElement) {
		char *mode = NULL, *shading = NULL, *bkgValues = NULL;
		float r, g, b, a;

		mode = (char *)drawingElement->Attribute("mode");

		shading = (char *)drawingElement->Attribute("shading");
		bkgValues = (char *)drawingElement->Attribute("background");

		if (mode != NULL && shading != NULL && bkgValues != NULL && sscanf(bkgValues, "%f %f %f %f", &r, &g, &b, &a) == 4){
			printf("  drawing attributes: %s %s\n", mode, shading);

			if (mode == "fill")
				globalsData.polygonMode = GL_FILL;
			else if (mode == "line")
				globalsData.polygonMode = GL_LINE;
			else if (mode == "point")
				globalsData.polygonMode = GL_POINT;

			if (shading == "gouraud")
				globalsData.shadeModel = GL_SMOOTH;
			else if (shading == "flat")
				globalsData.shadeModel = GL_FLAT;
			
			globalsData.bkgColorR = r;
			globalsData.bkgColorG = g;
			globalsData.bkgColorB = b;
			globalsData.bkgColorA = a;

			printf("  background values (RGBA): %f %f %f %f\n", r, g, b, a);
		}
		else
			printf("Error parsing drawing\n");
	}
	else
		printf("drawing not found\n");
}

void XMLScene::parserGlobalsCulling(Globals& globalsData) {
	TiXmlElement* cullingElement = globElement->FirstChildElement("culling");
	if (cullingElement) {
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
}

void XMLScene::parserGlobalsLighting(Globals& globalsData) {
	TiXmlElement* lightingElement = globElement->FirstChildElement("lighting");
	if (lightingElement) {
		char *doublesided = NULL, *local = NULL, *enabled = NULL, *ambient = NULL;
		float r, g, b, a;

		doublesided = (char *)lightingElement->Attribute("doublesided");
		local = (char *)lightingElement->Attribute("local");
		enabled = (char *)lightingElement->Attribute("enabled");
		ambient = (char *)lightingElement->Attribute("ambient");

		if (doublesided != NULL && local != NULL && enabled != NULL && ambient != NULL && sscanf(ambient, "%f %f %f %f", &r, &g, &b, &a) == 4) {
			printf("  lighting attributes: %s %s %s\n", doublesided, local, enabled);
			printf("  background values (RGBA): %f %f %f %f\n", r, g, b, a);
		}
		else
			printf("Error parsing lighting\n");
	}
	else
		printf("lighting not found\n");
}
