#include "XMLScene.h"

void XMLScene::parserLights() {
	if (lightsElement == NULL)
		printf("lights block not found!\n");
	else {
		printf("Processing lights init:\n");

		TiXmlElement* lightElement = lightsElement->FirstChildElement("light");

		if (lightElement != NULL) {
			do {
				std::string type = lightElement->Attribute("type");

				Light* newLight = NULL;

				if (type == "omni")
					newLight = new Light();
				else if (type == "spot") {
					newLight = new SpotLight();
					sscanf(lightElement->Attribute("target"), "%f %f %f", &((SpotLight*)newLight)->targetX, &((SpotLight*)newLight)->targetY, &((SpotLight*)newLight)->targetZ);
					sscanf(lightElement->Attribute("angle"), "%f", &((SpotLight*)newLight)->angle);
					sscanf(lightElement->Attribute("exponent"), "%f", &((SpotLight*)newLight)->exponent);
				}
				else continue;

				newLight->id = lightElement->Attribute("id");

				std::string enabled = lightElement->Attribute("enabled");
				if (enabled == "true")
					newLight->enabled = true;
				else if (enabled == "false")
					newLight->enabled = false;

				std::string marker = lightElement->Attribute("marker");
				if (marker == "true")
					newLight->marker = true;
				else if (marker == "false")
					newLight->marker = false;

				sscanf(lightElement->Attribute("pos"), "%f %f %f", &((SpotLight*)newLight)->x, &((SpotLight*)newLight)->y, &((SpotLight*)newLight)->z);

				TiXmlElement* component = lightElement->FirstChildElement("component");

				do {
					std::string type = component->Attribute("type");

					if (type == "ambient")
						sscanf(component->Attribute("value"), "%f %f %f %f", &newLight->ambR, &newLight->ambG, &newLight->ambB, &newLight->ambA);
					else if (type == "diffuse")
						sscanf(component->Attribute("value"), "%f %f %f %f", &newLight->difR, &newLight->difG, &newLight->difB, &newLight->difA);
					else if (type == "specular")
						sscanf(component->Attribute("value"), "%f %f %f %f", &newLight->speR, &newLight->speG, &newLight->speB, &newLight->speA);
				} while (component = component->NextSiblingElement());

				lights.push_back(newLight);
			} while (lightElement = lightElement->NextSiblingElement());
		}
		else printf("light not found\n");
	}
}
