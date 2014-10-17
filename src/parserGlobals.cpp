#include "XMLScene.h"
#include "Globals.h"

void XMLScene::parserGlobals() {
	if (globElement == NULL)
		printf("globals block not found!\n");
	else {
		cout << "\n----------------------- \n" << " Processing Globals \n" << "-----------------------" << endl;

		parserGlobalsDrawing();
		parserGlobalsCulling();
		parserGlobalsLighting();
	}
}

void XMLScene::parserGlobalsDrawing() {
	TiXmlElement* drawingElement = globElement->FirstChildElement("drawing");

	if (drawingElement) {
		char *mode = NULL, *shading = NULL, *bkgValues = NULL;
		float r, g, b, a;

		mode = (char *)drawingElement->Attribute("mode");
		shading = (char *)drawingElement->Attribute("shading");
		bkgValues = (char *)drawingElement->Attribute("background");

		if (mode != NULL && shading != NULL && bkgValues != NULL && sscanf(bkgValues, "%f %f %f %f", &r, &g, &b, &a) == 4){
			cout << "Shading and mode checked!" << endl;
			if (!strcmp(mode, "fill"))
				globalsData.polygonMode = GL_FILL;
			else if (!strcmp(mode, "line"))
				globalsData.polygonMode = GL_LINE;
			else if (!strcmp(mode, "point"))
				globalsData.polygonMode = GL_POINT;

			if (!strcmp(shading, "gouraud"))
				globalsData.shadeModel = GL_SMOOTH;
			else if (!strcmp(shading, "flat"))
				globalsData.shadeModel = GL_FLAT;
			
			globalsData.bkgColorR = r;
			globalsData.bkgColorG = g;
			globalsData.bkgColorB = b;
			globalsData.bkgColorA = a;

			cout << "Background colors checked!" << endl;
		}
		else
			printf("Error parsing drawing\n");
	}
	else
		printf("drawing not found\n");
}

void XMLScene::parserGlobalsCulling() {
	TiXmlElement* cullingElement = globElement->FirstChildElement("culling");

	if (cullingElement) {
		char *face = NULL, *order = NULL;

		face = (char *)cullingElement->Attribute("face");
		order = (char *)cullingElement->Attribute("order");

		if (face != NULL && order != NULL) {
			cout << "Culling checked!" << endl;

			if (!strcmp(face, "none"))
				globalsData.cullFace = NULL;
			else if (!strcmp(face, "back"))
				globalsData.cullFace = GL_BACK;
			else if (!strcmp(face, "front"))
				globalsData.cullFace = GL_FRONT;
			else if (!strcmp(face, "both"))
				globalsData.cullFace = GL_FRONT_AND_BACK;

			if (!strcmp(order, "ccw"))
				globalsData.frontFace = GL_CCW;
			else if (!strcmp(order, "cw"))
				globalsData.frontFace = GL_CW;
		}
		else
			printf("Error parsing culling\n");
	}
	else
		printf("culling not found\n");
}

void XMLScene::parserGlobalsLighting() {
	TiXmlElement* lightingElement = globElement->FirstChildElement("lighting");

	if (lightingElement) {
		char *doubleSided = NULL, *local = NULL, *enabled = NULL, *ambient = NULL;
		float r, g, b, a;

		doubleSided = (char *)lightingElement->Attribute("doublesided");
		local = (char *)lightingElement->Attribute("local");
		enabled = (char *)lightingElement->Attribute("enabled");
		ambient = (char *)lightingElement->Attribute("ambient");

		if (doubleSided != NULL && local != NULL && enabled != NULL && ambient != NULL && sscanf(ambient, "%f %f %f %f", &r, &g, &b, &a) == 4) {
			cout << "Lighting checked!" << endl;
			
			if (!strcmp(doubleSided, "true"))
				globalsData.dblSidedLight = true;
			else if (!strcmp(doubleSided, "false"))
				globalsData.dblSidedLight = false;

			if (!strcmp(local, "true"))
				globalsData.localLight = true;
			else if (!strcmp(local, "false"))
				globalsData.localLight = false;

			if (!strcmp(enabled, "true"))
				globalsData.lightEnabled = true;
			else if (!strcmp(enabled, "false"))
				globalsData.lightEnabled = false;

			cout << "Background values checked!\n" << endl;

			float ambLight[4] = { r, g, b, a };
			memcpy(CGFlight::background_ambient, ambLight, sizeof(ambLight));
		}
		else
			printf("Error parsing lighting\n");
	}
	else
		printf("lighting not found\n");
}
