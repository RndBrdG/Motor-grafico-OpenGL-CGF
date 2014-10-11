#include <XMLScene.h>


void XMLScene::parserAppearance(){

	if (appsElement == NULL)
		cout << "Appearance block not found!\n";
	else
	{
		cout << "Processing Appearance init:\n";

		TiXmlElement* readAppearance = appsElement->FirstChildElement("appearance");
		do{
			if (readAppearance != NULL) {
				std::string id = readAppearance->Attribute("id");
				float shininess;
				std::string textRef = readAppearance->Attribute("textureref");
				if (id != "" && textRef != "" && readAppearance->QueryFloatAttribute("shininess", &shininess) == TIXML_SUCCESS){
					TiXmlElement* component = readAppearance->FirstChildElement("component");
					std::string type, values;
					float ambient[4], difusa[4], especular[4];
					do {
						type = component->Attribute("type");
						values = component->Attribute("value");
						if (type == "ambient" && sscanf(values.c_str(), "%f %f %f %f", &ambient[0], &ambient[1], &ambient[2], &ambient[3]))
							continue;
						else if (type == "diffuse" && sscanf(values.c_str(), "%f %f %f %f", &difusa[0], &difusa[1], &difusa[2], &difusa[3]))
							continue;
						else if (type == "specular" && sscanf(values.c_str(), "%f %f %f %f", &especular[0], &especular[1], &especular[2], &especular[3]))
							continue;
					} while (component = component->NextSiblingElement());
					Aparencia* ap = new Aparencia(id, shininess, textRef,ambient,difusa,especular);
					objetosDaCena.getAparencias().insert(std::make_pair(id, ap));
				}
			}
		} while (readAppearance = readAppearance->NextSiblingElement());
	}
}