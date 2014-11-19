#include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include "DemoShader.h"

DemoShader::DemoShader(std::string texture) {
	init("../res/shader.vert", "../res/shader.frag");

	CGFshader::bind();

	GLint feupImageLocation = glGetUniformLocation(id(), "feupImage");
	glUniform1i(feupImageLocation, 0);

	feupTexture = new CGFtexture(texture);

	CGFshader::unbind();
}

DemoShader::~DemoShader() {
	delete feupTexture;
}

void DemoShader::bind() {
	CGFshader::bind();

	glActiveTexture(GL_TEXTURE0);
	feupTexture->apply();
}

void DemoShader::unbind() {
	CGFshader::unbind();
}
