#ifndef GLOBALS_H
#define GLOBALS_H

#include "CGFscene.h"

class Globals {
protected:
	GLenum polygonMode = GL_FILL;
	GLenum shadeModel = GL_SMOOTH;
	float bkgColorR = 0., bkgColorG = 0., bkgColorB = 0., bkgColorA = 0.;

	GLenum cullFace = GL_BACK;
	GLenum frontFace = GL_CCW;

	// http://www.dei.isep.ipp.pt/~matos/cg/docs/manual/glLightModel.3G.html
	bool dblSidedLight = false;
	bool localLight = true;
	bool ambLight = true;
	float ambLightR = .2, ambLightG = .2, ambLightB = .2, ambLightA = 1.;

public:
	Globals(GLenum polygonMode, GLenum shadeModel, float bkgColorR, float bkgColorG, float bkgColorB, float bkgColorA,
		GLenum cullFace, GLenum frontFace,
		bool dblSidedLight, bool localLight, bool ambLight, float ambLightR, float ambLightG, float ambLightB, float ambLightA);
};

#endif
