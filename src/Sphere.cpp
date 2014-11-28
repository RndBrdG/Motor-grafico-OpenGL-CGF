#include "Sphere.h"

Sphere::Sphere(float radius, int slices, int stacks) {
	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
	GLUquadric* esfera = gluNewQuadric();
	this->sph = esfera;
}

void Sphere::draw(float textS, float textT) {
	gluQuadricTexture(this->sph, true);
	draw();
}

void Sphere::draw() {
	gluSphere(this->sph, this->radius, this->slices, this->stacks);
}
