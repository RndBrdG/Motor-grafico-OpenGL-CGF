#include "CGFappearance.h"
#include "CGFapplication.h"
#include "CGFaxis.h"
#include "DemoScene.h"
#include "Primitivas.h"
#include "TPinterface.h"
#include <math.h>

DemoScene::DemoScene() : scene(XMLScene("../res/scene.anf")) {
	lights = scene.lights;
}

const Graph& DemoScene::getGraph() {
	return desenhar;
}

const std::vector<Light*>& DemoScene::getLights() {
	return lights;
}

void DemoScene::activateCamera(int id){
	this->desenhar.setDefaultCamera(this->getCameras()[id]->getId());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (strcmp(this->getCameras()[id]->getType(),"ortho")==0){
		glOrtho(this->getCameras()[id]->getLeft(), this->getCameras()[id]->getRight(), this->getCameras()[id]->getBottom(), this->getCameras()[id]->getTop(), this->getCameras()[id]->getNear(), this->getCameras()[id]->getFar());
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		if ( strcmp(this->getCameras()[id]->getDirection(), "x") == 0){
			cout << "Entrou X" << endl;
			gluLookAt(1, 0, 0, this->getCameras()[id]->getTarX(), this->getCameras()[id]->getTarY(), this->getCameras()[id]->getTarZ(), 0, 1, 0);
		}
		else if (strcmp(this->getCameras()[id]->getDirection(),"y") == 0){
			cout << "Entrou y" << endl;
			gluLookAt(0, 1, 0, this->getCameras()[id]->getTarX(), this->getCameras()[id]->getTarY(), this->getCameras()[id]->getTarZ(), 1, 0, 1);
		}
		else {
			cout << "Entrou z" << endl;
			gluLookAt(0, 0, 1, this->getCameras()[id]->getTarX(), this->getCameras()[id]->getTarY(), this->getCameras()[id]->getTarZ(), 0, 1, 0);
		}
		}
	else {
		gluPerspective(this->getCameras()[id]->getAngle(), CGFapplication::xy_aspect, this->getCameras()[id]->getNear(), this->getCameras()[id]->getFar());
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(this->getCameras()[id]->getPosX(), this->getCameras()[id]->getPosY(), this->getCameras()[id]->getPosZ(), this->getCameras()[id]->getTarX(), this->getCameras()[id]->getTarY(), this->getCameras()[id]->getTarZ(),0,1,0);
	}
}

vector<Camera*>& DemoScene::getCameras() {
	return cameras;
}

void DemoScene::init() {
	// Sets drawing settings
	glShadeModel(scene.globalsData.getShadeModel());
	glClearColor(scene.globalsData.getBkgColorR(), scene.globalsData.getBkgColorG(), scene.globalsData.getBkgColorB(), scene.globalsData.getBkgColorA());

	// Sets culling settings
	if (scene.globalsData.getCullFace() != NULL) {
		glCullFace(scene.globalsData.getCullFace());
		glFrontFace(scene.globalsData.getFrontFace());
	}
	else glDisable(GL_CULL_FACE);

	// Sets lighting settings
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, scene.globalsData.getDblSidedLight());
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, scene.globalsData.getLocalLight());
	if (scene.globalsData.getLightEnabled()) glEnable(GL_LIGHTING); else glDisable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);

	// Sets lights
	for (auto it = scene.lights.cbegin(); it != scene.lights.cend(); it++) {
		glLightf(GL_LIGHT0 + (*it)->getLightNum(), GL_SPOT_CUTOFF, (*it)->getAngle());
		glLightf(GL_LIGHT0 + (*it)->getLightNum(), GL_SPOT_EXPONENT, (*it)->getExponent());
		if ((*it)->getEnabled()) glEnable(GL_LIGHT0 + (*it)->getLightNum());
		else glDisable(GL_LIGHT0 + (*it)->getLightNum());
	}

	// Defines a default normal
	glNormal3f(0, 0, 1);

	desenhar = scene.objetosDaCena;

	for (auto it = this->desenhar.getCameras().begin(); it != this->desenhar.getCameras().end(); it++){
		this->cameras.push_back(it->second);
	}

	setUpdatePeriod(30);
}

void DemoScene::update(unsigned long t) {
}

void DemoScene::display() {
	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// Apply transformations corresponding to the camera position relative to the origin
	//CGFscene::activeCamera->applyView();
	int id = 0;

	for (int i = 0; i < cameras.size(); i++){
		if (cameras[i]->getId() == this->desenhar.getCameraDefault())
			id = i;

	}
	
	activateCamera(id);

	// Draw (and update) lights
	for (auto it = scene.lights.cbegin(); it != scene.lights.cend(); it++) {
		if ((*it)->onOff) (*it)->enable();
		else (*it)->disable();

		if ((*it)->getMarker()) (*it)->draw();
		else (*it)->update();
	}

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN feature demos

	glPolygonMode(GL_FRONT_AND_BACK, scene.globalsData.getPolygonMode()); // Sets (variable) drawing mode.
	desenhar.draw();

	// ---- END feature demos

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

DemoScene::~DemoScene() {
	delete(&scene);
	delete(&desenhar);
	delete(&lights);
}
