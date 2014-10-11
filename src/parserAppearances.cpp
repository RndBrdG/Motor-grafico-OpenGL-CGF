#include <XMLScene.h>


void XMLScene::parserAppearance(){
	if (appsElement == NULL)
		cout << "Appearance block not found!\n";
	else
	{
		cout << "Processing Appearance init:\n";

		TiXmlElement* readAppearance = appsElement->FirstChildElement();


	}
}