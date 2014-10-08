#include <Primitivas.h>

Rectangle::Rectangle(float x1, float x2, float y1, float y2){
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

void Rectangle::draw(){
	glRectf(this->x1, this->y1, this->x2, this->y2);
}

Triangle::Triangle(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3){
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
	this->z1 = z1;
	this->z2 = z2;
	this->z3 = z3;
}

void Triangle::draw(){
	glBegin(GL_TRIANGLES);
		glVertex3f(this->x1, this->y1, this->z1);
		glVertex3f(this->x2, this->y2, this->z2);
		glVertex3f(this->x3, this->y3, this->z3);
	glEnd();
}

Cylinder::Cylinder(float base, float top, float height, float slices, float stacks){
	this->base = base;
	this->top = top;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
	this->cylin = gluNewQuadric();
}

void Cylinder::draw(){
	gluCylinder(this->cylin, this->base, this->top, this->height, this->slices, this->stacks);
};

Sphere::Sphere(float radius, float slices, float loops){
	this->radius = radius;
	this->slices = slices;
	this->loops = loops;
	this->sph = gluNewQuadric();
}

void Sphere::draw(){
	gluSphere(this->sph,this->radius, this->slices,this->loops);
}

Torus::Torus(float inner, float outer, float slices, float loops){
	this->inner = inner;
	this->outer = outer;
	this->slices = slices;
	this->loops = loops;
}

void Torus::draw(){
	glutSolidTorus(this->inner,this->outer,this->slices,this->loops); 
}