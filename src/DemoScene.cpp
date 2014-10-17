#include "CGFappearance.h"
#include "CGFapplication.h"
#include "CGFaxis.h"
#include "DemoScene.h"
#include "Primitivas.h"
#include "TPinterface.h"
#include <math.h>

DemoScene::DemoScene() : parser(XMLScene("../res/scene.anf")) {
}

const Graph& DemoScene::getElementos() {
	return elementos;
}

void DemoScene::activateCamera(int id){
	elementos.setDefaultCamera(camaras[id]->getId());

	glMatrixMode(GL_PROJECTION);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (strcmp(camaras[id]->getType(), "ortho") == 0) {
		glOrtho(camaras[id]->getLeft(), camaras[id]->getRight(), camaras[id]->getBottom(), camaras[id]->getTop(), camaras[id]->getNear(), camaras[id]->getFar());

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		if (strcmp(camaras[id]->getDirection(), "x") == 0)
			gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);
		else if (strcmp(camaras[id]->getDirection(), "y") == 0)
			gluLookAt(0, 1, 0, 0, 0, 0, 0, 0, -1);
		else
			gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
	}
	else {
		gluPerspective(camaras[id]->getAngle(), CGFapplication::xy_aspect, camaras[id]->getNear(), camaras[id]->getFar());
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(camaras[id]->getPosX(), camaras[id]->getPosY(), camaras[id]->getPosZ(), camaras[id]->getTarX(), camaras[id]->getTarY(), camaras[id]->getTarZ(), 0, 1, 0);
	}
}

vector<Camera*>& DemoScene::getCamaras() {
	return camaras;
}

void DemoScene::init() {
	elementos = parser.objetosDaCena;

	// Sets drawing settings
	glShadeModel(parser.globalsData.getShadeModel());
	glClearColor(parser.globalsData.getBkgColorR(), parser.globalsData.getBkgColorG(), parser.globalsData.getBkgColorB(), parser.globalsData.getBkgColorA());

	// Sets culling settings
	if (parser.globalsData.getCullFace() != NULL) {
		glCullFace(parser.globalsData.getCullFace());
		glFrontFace(parser.globalsData.getFrontFace());
	}
	else glDisable(GL_CULL_FACE);

	// Sets lighting settings
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, parser.globalsData.getDblSidedLight());
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, parser.globalsData.getLocalLight());
	if (parser.globalsData.getLightEnabled()) glEnable(GL_LIGHTING); else glDisable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);

	// Sets lights
	for (auto it = elementos.getLuzes().cbegin(); it != elementos.getLuzes().cend(); it++) {
		glLightf(GL_LIGHT0 + it->second->getLightNum(), GL_SPOT_CUTOFF, it->second->getAngle());
		glLightf(GL_LIGHT0 + it->second->getLightNum(), GL_SPOT_EXPONENT, it->second->getExponent());
		if (it->second->getEnabled()) glEnable(GL_LIGHT0 + it->second->getLightNum());
		else glDisable(GL_LIGHT0 + it->second->getLightNum());
	}

	// Defines a default normal
	glNormal3f(0, 0, 1);

	for (auto it = elementos.getCamaras().begin(); it != elementos.getCamaras().end(); it++){
		camaras.push_back(it->second);
	}

	setUpdatePeriod(30);
}

void DemoScene::update(unsigned long t) {
}

void DemoScene::display() {
	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformations)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	int id = 0;
	for (int i = 0; i < camaras.size(); i++){
		if (camaras[i]->getId() == elementos.getCameraDefault()) {
			id = i;
			break;
		}
	}

	// Trocar coment�rios das 2 linhas seguintes para aceder �s c�maras da cena vs. c�mara predefinida
	activateCamera(id);
	//CGFscene::activeCamera->applyView();

	// Draw (and update) lights
	for (auto it = elementos.getLuzes().cbegin(); it != elementos.getLuzes().cend(); it++) {
		if (it->second->onOff) it->second->enable();
		else it->second->disable();

		if (it->second->getMarker()) it->second->draw();
		else it->second->update();
	}

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN feature demos

	glPolygonMode(GL_FRONT_AND_BACK, parser.globalsData.getPolygonMode()); // Sets (variable) drawing mode.
	elementos.draw();

	// ---- END feature demos

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

DemoScene::~DemoScene() {
	delete(&parser);
	delete(&elementos);
}
