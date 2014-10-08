#include "CGFappearance.h"
#include "CGFapplication.h"
#include "CGFaxis.h"
#include "DemoScene.h"
#include "ExampleObject.h"
#include "XMLscene.h"
#include "Primitivas.h"
#include <math.h>

void DemoScene::init()
{
	XMLScene scene("../res/scene.xml"); // Read config data from XML

	// Sets drawing settings
	glPolygonMode(GL_FRONT_AND_BACK, scene.globalsData.getPolygonMode());
	glShadeModel(scene.globalsData.getShadeModel());
	glClearColor(scene.globalsData.getBkgColorR(), scene.globalsData.getBkgColorG(), scene.globalsData.getBkgColorB(), scene.globalsData.getBkgColorA());
	glClear(GL_COLOR_BUFFER_BIT);

	// Sets culliing settings
	if (scene.globalsData.getCullFace() != NULL) {
		glCullFace(scene.globalsData.getCullFace());
		glFrontFace(scene.globalsData.getFrontFace());
	}

	// Sets lighting settings
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, scene.globalsData.getDblSidedLight());
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, scene.globalsData.getLocalLight());
	if (scene.globalsData.getLightEnabled()) glEnable(GL_LIGHTING); else glDisable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, CGFlight::background_ambient);

	// Declares and enables a light
	float light0_pos[4] = { 4.0, 6.0, 5.0, 1.0 };
	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->enable();

	// Defines a default normal
	glNormal3f(0, 0, 1);

	obj = new ExampleObject();
	materialAppearance = new CGFappearance();
	textureAppearance = new CGFappearance("../res/pyramid.jpg", GL_REPEAT, GL_REPEAT);
	shader = new CGFshader("../res/texshader.vert", "../res/texshader.frag");
	desenhar = scene.objetosDaCena;
	setUpdatePeriod(30);
}

void DemoScene::update(unsigned long t)
{
	shader->bind();
	shader->update(t / 400.0);
	shader->unbind();

}

void DemoScene::display()
{

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	// Draw (and update) light
	light0->draw();

	// Draw axis
	axis.draw();


	// ---- END Background, camera and axis setup


	// ---- BEGIN feature demos

	desenhar.draw();

	// Simple object
	materialAppearance->apply();
	obj->draw();

	
	// textured object

	glTranslatef(0, 4, 0);
	textureAppearance->apply();
	obj->draw();

	// shader object

	glTranslatef(0, 4, 0);
	shader->bind();
	obj->draw();
	shader->unbind();


	// ---- END feature demos

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

DemoScene::~DemoScene()
{
	delete(shader);
	delete(textureAppearance);
	delete(materialAppearance);
	delete(obj);
	delete(light0);
}
