#ifndef DEMOSHADER_H
#define DEMOSHADER_H

#include "CGFshader.h"
#include "CGFtexture.h"

class DemoShader : public CGFshader {
protected:
	CGFtexture* feupTexture;
public:
	DemoShader(std::string);
	~DemoShader();

	void bind();
	void unbind();
};

#endif
