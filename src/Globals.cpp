#include "Globals.h"

Globals::Globals() {
	polygonMode = GL_FILL;
	shadeModel = GL_SMOOTH;
	bkgColorR = 0., bkgColorG = 0., bkgColorB = 0., bkgColorA = 0.;

	cullFace = GL_BACK;
	frontFace = GL_CCW;

	dblSidedLight = false;
	localLight = true;
	ambLight = true;
	ambLightR = .2, ambLightG = .2, ambLightB = .2, ambLightA = 1.;
}

Globals::Globals(GLenum polygonMode, GLenum shadeModel, float bkgColorR, float bkgColorG, float bkgColorB, float bkgColorA, GLenum cullFace, GLenum frontFace, bool dblSidedLight, bool localLight, bool ambLight, float ambLightR, float ambLightG, float ambLightB, float ambLightA) : polygonMode(polygonMode) {
	this->shadeModel = shadeModel;
	this->bkgColorR = bkgColorR;
	this->bkgColorG = bkgColorG;
	this->bkgColorB = bkgColorB;
	this->bkgColorA = bkgColorA;
	this->cullFace = cullFace;
	this->frontFace = frontFace;
	this->dblSidedLight = dblSidedLight;
	this->localLight = localLight;
	this->ambLight = ambLight;
	this->ambLightR = ambLightR;
	this->ambLightG = ambLightG;
	this->ambLightB = ambLightB;
	this->ambLightA = ambLightA;
}
