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

Globals::Globals(GLenum polygonMode, GLenum shadeModel, float bkgColorR, float bkgColorG, float bkgColorB, float bkgColorA, GLenum cullFace, GLenum frontFace, bool dblSidedLight, bool localLight, bool ambLight, float ambLightR, float ambLightG, float ambLightB, float ambLightA)
	: polygonMode(polygonMode), shadeModel(shadeModel), bkgColorR(bkgColorR), bkgColorG(bkgColorG), bkgColorB(bkgColorB), bkgColorA(bkgColorA),
	cullFace(cullFace), frontFace(frontFace),
	dblSidedLight(dblSidedLight), localLight(localLight), ambLight(ambLight), ambLightR(ambLightR), ambLightG(ambLightG), ambLightB(ambLightB), ambLightA(ambLightA) {
}

GLenum Globals::getPolygonMode() {
	return polygonMode;
}

GLenum Globals::getShadeModel() {
	return shadeModel;
}

float Globals::getBkgColorR() {
	return bkgColorR;
}

float Globals::getBkgColorG() {
	return bkgColorG;
}

float Globals::getBkgColorB() {
	return bkgColorB;
}

float Globals::getBkgColorA() {
	return bkgColorA;
}
