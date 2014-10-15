#include "XMLScene.h"
#include "Camera.h"

void XMLScene::parserCameras() {
	if (camElement == NULL)
		printf("cameras block not found!\n");
	else
	{
		cout << "Processing cameras init:\n";

		char *initial = NULL;
		initial = (char *) camElement->Attribute("initial");
		this->objetosDaCena.setDefaultCamera(initial);
		if (initial != NULL){
			printf("  camera attribute: %s\n", initial);
		}
		else
			printf("Error parsing camera\n");

		// Procurar câmaras.
		camElement = camElement->FirstChildElement();

		do {
			if (camElement->ValueTStr() == "perspective") { // Tag "perspective"
					char *id = NULL, *position = NULL, *target = NULL;
					float near, far, angle, posX, posY, posZ, targetX, targetY, targetZ;

					id = (char *) camElement->Attribute("id");
					position = (char *) camElement->Attribute("pos");
					target = (char *) camElement->Attribute("target");

					if (id != NULL && (camElement->QueryFloatAttribute("near", &near) == TIXML_SUCCESS) &&
						(camElement->QueryFloatAttribute("far", &far) == TIXML_SUCCESS) && (camElement->QueryFloatAttribute("angle", &angle) == TIXML_SUCCESS)
						&& (position != NULL && sscanf(position, "%f %f %f", &posX, &posY, &posZ) == 3) && (target != NULL && sscanf(target, "%f %f %f", &targetX, &targetY, &targetZ) == 3)){
						printf("\n< - - - Values of perspective - - - - >\n");
						printf(" Id : %s\n", id);
						printf(" Valores >  %f %f %f %f %f %f %f %f\n", near, far, angle, posX, posY, posZ, targetX, targetY, targetZ);
						Camera* a1 = new Camera(id, "perspective", near, far, angle, targetX, targetY, targetZ, posX, posY, posZ);
						this->objetosDaCena.getCameras().insert(std::make_pair(a1->getId(), a1));
					}
					else
						printf("Error reading perspective tag\n");
			}
			else if (camElement->ValueTStr() == "ortho") { // Tag "ortho"

					char *id = NULL, *dir = NULL;
					float near, far, left, right, top, bottom;

					id = (char *) camElement->Attribute("id");
					dir = (char *) camElement->Attribute("direction");

					if (id != NULL && dir != NULL && (camElement->QueryFloatAttribute("near", &near) == TIXML_SUCCESS) && (camElement->QueryFloatAttribute("left", &left) == TIXML_SUCCESS)
						&& (camElement->QueryFloatAttribute("far", &far) == TIXML_SUCCESS) && (camElement->QueryFloatAttribute("right", &right) == TIXML_SUCCESS)
						&& (camElement->QueryFloatAttribute("top", &top) == TIXML_SUCCESS) && (camElement->QueryFloatAttribute("bottom", &bottom) == TIXML_SUCCESS)){
						printf("\n\n< - - - Values of ortho - - - - >\n");
						printf(" Id : %s\n", id);
						printf(" Dir : %s\n", dir);
						printf(" Valores >>  %f - %f - %f - %f - %f - %f\n", near, far, left, right, top, bottom);
						Camera* a1 = new Camera(id, "ortho", dir, left, right, top, bottom);
						this->objetosDaCena.getCameras().insert(std::make_pair(a1->getId(), a1));
					}
					else
						printf("Error reading ortho tag\n");
			}
			else {
				printf("Unknown camera tag found\n");
			}
		} while (camElement = camElement->NextSiblingElement());
	}
}
