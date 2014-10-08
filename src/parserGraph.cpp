#include <XMLScene.h>

void XMLScene::parserGraph(){

	if (graphElement == NULL)
		printf("Graph block not found!\n");
	else
	{
		printf("\n\n-----------------------\n Processing Nodes -> XML \n------------------------\n");
		char *rootId = NULL;
		rootId = (char *) graphElement->Attribute("rootid");
		printf("Root id: %s", rootId);
		if (rootId != NULL){
			TiXmlElement *node = graphElement->FirstChildElement();
			char *id = NULL;

			while (node) {
				id = (char *) node->Attribute("id");
				Node novoNode = Node(id);
				printf("\nLeaf ID: %s", id);

				TiXmlElement *childs = node->FirstChildElement();

				while (childs){
					if (childs->ValueTStr() == "transforms"){
						parserGraphTransforms(novoNode, childs);
					}
					else if (childs->ValueTStr() == "appearanceref"){
						parserGraphAppearanceref(novoNode, childs);
					}
					else if (childs->ValueTStr() == "primitives"){
						parserGraphPrimitives(novoNode, childs);
					}
					else if (childs->ValueTStr() == "descendants"){
						parserGraphdescendants(novoNode, childs);
					}
					childs = childs->NextSiblingElement();
				} // end of child while
				node = node->NextSiblingElement();
			} // end of node while
		} // end if ( verification )
	}

	printf("\n\n");
}

void XMLScene::parserGraphTransforms(Node &novoNode, TiXmlElement *childs){
	TiXmlElement* elem = childs->FirstChildElement();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	char* type = NULL;
	while (elem){
		type = (char*) elem->Attribute("type");
		printf("\nType: %s", type);

		if (strcmp(type, "translate") == 0){
			char* to = NULL;
			to = (char*) elem->Attribute("to");
			float x1, y1, z1;

			if (to != NULL && sscanf(to, "%f %f %f", &x1, &y1, &z1) == 3){
				printf("\n |Node %s values - - - - >\n", novoNode.getId());
				printf(" Valores >  %f %f %f\n", x1, y1, z1);
				glTranslated(x1, y1, z1);
			}
			else
				printf("Error reading perspective tag\n");
		}
		else if (strcmp(type, "rotate") == 0){
			char* axis = NULL;
			axis = (char*) elem->Attribute("axis");
			float angle;

			if (axis != NULL && (elem->QueryFloatAttribute("angle", &angle) == TIXML_SUCCESS)){
				printf("\n |Node %s values - - - - >\n", novoNode.getId());
				printf(" Valores >  Axis: %s | angle %f \n", axis, angle);
				if (axis == "xx")
					glRotated(angle, 1, 0, 0);
				else if (axis == "yy")
					glRotated(angle, 1, 0, 0);
				else if (axis == "zz")
					glRotated(angle, 0, 0, 1);
			}
			else
				printf("Error reading perspective tag\n");
		}
		else if (strcmp(type, "scale") == 0){
			float fac1,fac2,fac3;
			char* fac = NULL;
			fac = (char*) elem->Attribute("factor");

			if (fac != NULL && sscanf(fac, "%f %f %f", &fac1, &fac2, &fac3) == 3){
				printf("\n |Node %s values - - - - >\n", novoNode.getId());
				printf(" Valores >  Factor: %s %s %s \n", fac1, fac2,fac3);
				glScaled(fac1, fac2, fac3);
			}
			else
				printf("Error reading perspective tag\n");
		}
		elem=elem->NextSiblingElement();
	}
	float m[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, &m[0]);
	novoNode.setMatrix(m);
	for (int i = 0; i < 16; i++)
		printf("%f - ", m[i]);
}
void XMLScene::parserGraphAppearanceref(Node &novoNode, TiXmlElement *childs){
}
void XMLScene::parserGraphPrimitives(Node &novoNode, TiXmlElement *childs){};

void XMLScene::parserGraphdescendants(Node &novoNode, TiXmlElement *childs){};