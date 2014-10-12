#include <XMLScene.h>

void XMLScene::parserTextures(){
	if (texElement == NULL)
		printf("Textures block not found!\n");
	else
	{
		TiXmlElement* textureElement = texElement->FirstChildElement("texture");
		std::string id;
		std::string file;
		float texlength_s;
		float texlength_t;
		do{
			id = textureElement->Attribute("id");
			file = textureElement->Attribute("file");
			textureElement->QueryFloatAttribute("texlength_s", &texlength_s);
			textureElement->QueryFloatAttribute("texlength_t", &texlength_t);
			Textura* a1 = new Textura(id, file, texlength_s, texlength_t);
			objetosDaCena.getTexturas().insert(std::make_pair(id, a1));
		} while (textureElement = textureElement->NextSiblingElement());
	}
}