#include "Flag.h"

Flag::Flag(std::string texture) {
	shader = new DemoShader(texture);
	object = new Plane(20);
}

Flag::~Flag() {
	delete object;
	delete shader;
}

void Flag::draw(float textS, float textT) {
	draw();
}

void Flag::draw() {
	shader->bind();
	object->draw();
	shader->unbind();
}
