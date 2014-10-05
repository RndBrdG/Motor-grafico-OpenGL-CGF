#ifndef GLOBALS_H
#define GLOBALS_H

#include "CGFscene.h"

class Globals {
	friend class XMLScene;

protected:
	GLenum polygonMode;
	GLenum shadeModel;
	float bkgColorR, bkgColorG, bkgColorB, bkgColorA;

	GLenum cullFace;
	GLenum frontFace;

	// http://www.dei.isep.ipp.pt/~matos/cg/docs/manual/glLightModel.3G.html
	bool dblSidedLight;
	bool localLight;
	bool ambLight;
	float ambLightR, ambLightG, ambLightB, ambLightA;

public:
	Globals();
	Globals(GLenum polygonMode, GLenum shadeModel, float bkgColorR, float bkgColorG, float bkgColorB, float bkgColorA, GLenum cullFace, GLenum frontFace, bool dblSidedLight, bool localLight, bool ambLight, float ambLightR, float ambLightG, float ambLightB, float ambLightA);

	GLenum getPolygonMode(), getShadeModel();
	float getBkgColorR(), getBkgColorG(), getBkgColorB(), getBkgColorA();
};

#endif
