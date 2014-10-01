#include "XMLScene.h"


void XMLScene::parsingCamera(){
	if (camElement == NULL)
		printf("cameras block not found!\n");
	else
	{
		printf("Processing cameras init:\n");

		char *initial = NULL;
		initial = (char *) camElement->Attribute("initial");

		if (initial != NULL){
			printf("  camera attribute: %s\n", initial);
		}
		else
			printf("Error parsing camera\n");

		// Procurar câmaras.
		TiXmlElement* camInstElement = camElement->FirstChildElement();

		do {
			if (camInstElement->ValueTStr() == "perspective") { // Tag "perspective"
				parsingCameraPerspective();
			}
			else if (camInstElement->ValueTStr() == "ortho") { // Tag "ortho"
				parsingCameraOrtho();
			}
			else {
				printf("Unknown camera tag found\n");
			}
		} while (camInstElement = camInstElement->NextSiblingElement());
	}
}

void XMLScene::parsingCameraPerspective(){
	TiXmlElement* perspElement = camElement->FirstChildElement("perspective");
	if (perspElement)
	{
		char *id = NULL, *position = NULL, *target = NULL;
		float near, far, angle, posX, posY, posZ, targetX, targetY, targetZ;

		id = (char *) perspElement->Attribute("id");
		position = (char *) perspElement->Attribute("pos");
		target = (char *) perspElement->Attribute("target");

		if (id != NULL && (perspElement->QueryFloatAttribute("near", &near) == TIXML_SUCCESS) &&
			(perspElement->QueryFloatAttribute("far", &far) == TIXML_SUCCESS) && (perspElement->QueryFloatAttribute("angle", &angle) == TIXML_SUCCESS)
			&& (position != NULL && sscanf(position, "%f %f %f", &posX, &posY, &posZ) == 3) && (target != NULL && sscanf(target, "%f %f %f", &targetX, &targetY, &targetZ) == 3)){
			printf("\n< - - - Values of perspective - - - - >\n");
			printf(" Id : %s\n", id);
			printf(" Valores >  %f %f %f %f %f %f %f %f\n", near, far, angle, posX, posY, posZ, targetX, targetY, targetZ);
		}
		else
			printf("Error reading perspective tag\n");
	}
}

void XMLScene::parsingCameraOrtho(){
	TiXmlElement* orthElement = camElement->FirstChildElement("ortho");
	if (orthElement)
	{
		char *id = NULL, *dir = NULL;
		float near, far, left, right, top, bottom;

		id = (char *) orthElement->Attribute("id");
		dir = (char *) orthElement->Attribute("direction");

		if (id != NULL && dir != NULL && (orthElement->QueryFloatAttribute("near", &near) == TIXML_SUCCESS) && (orthElement->QueryFloatAttribute("left", &left) == TIXML_SUCCESS)
			&& (orthElement->QueryFloatAttribute("far", &far) == TIXML_SUCCESS) && (orthElement->QueryFloatAttribute("right", &right) == TIXML_SUCCESS)
			&& (orthElement->QueryFloatAttribute("top", &top) == TIXML_SUCCESS) && (orthElement->QueryFloatAttribute("bottom", &bottom) == TIXML_SUCCESS)){
			printf("\n\n< - - - Values of ortho - - - - >\n");
			printf(" Id : %s\n", id);
			printf(" Dir : %s\n", dir);
			printf(" Valores >>  %f - %f - %f - %f - %f - %f\n", near, far, left, right, top, bottom);
		}
		else
			printf("Error reading ortho tag\n");
	}
}