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
					Aparencia* ap = new Aparencia(id, shininess, textRef);
					this->objetosDaCena.getAparencias().insert(std::make_pair(id, ap));
					TiXmlElement* component = readAppearance->FirstChildElement("component");
					std::string type, values;
					float v1, v2, v3, v4;
					do {
						type = component->Attribute("type");
						values = component->Attribute("value");

						if (type != "" && values != "" && sscanf(values.c_str(), "%f %f %f %f", &v1, &v2, &v3, &v4)){
							Componente a1(type, v1, v2, v3, v4);
							this->objetosDaCena.getAparencias()[id]->getComponentes().push_back(a1);
						}
					} while (component = component->NextSiblingElement());
				}
			}
		} while (readAppearance = readAppearance->NextSiblingElement());
	}
}