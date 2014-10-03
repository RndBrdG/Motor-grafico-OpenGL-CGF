#include "Globals.h"

Globals::Globals(GLenum polygonMode, GLenum shadeModel, float bkgColorR, float bkgColorG, float bkgColorB, float bkgColorA, GLenum cullFace, GLenum frontFace, bool dblSidedLight, bool localLight, bool ambLight, float ambLightR, float ambLightG, float ambLightB, float ambLightA) {
	this->polygonMode = polygonMode;
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
