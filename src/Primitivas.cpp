#include <Primitivas.h>

Rectangle::Rectangle(float x1, float x2, float y1, float y2){
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

void Rectangle::draw(float textS, float textT){
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glScalef((x2 - x1) / textS, (y2-y1) / textT, 1);
	glMatrixMode(GL_MODELVIEW);
	glBegin(GL_QUADS);
		glNormal3f(0, 0, 1);
		glTexCoord2d(0, 0);
		glVertex2f(x1, y1);
		glTexCoord2d(1, 0);
		glVertex2f(x2, y1);
		glTexCoord2d(1, 1);
		glVertex2f(x2, y2);
		glTexCoord2d(0, 1);
		glVertex2f(x1, y2);
	glEnd();
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

void Triangle::draw(float textS, float textT){
	glBegin(GL_TRIANGLES);
		glVertex3f(this->x1, this->y1, this->z1);
		glVertex3f(this->x2, this->y2, this->z2);
		glVertex3f(this->x3, this->y3, this->z3);
	glEnd();
}

Cylinder::Cylinder(float base, float top, float height, int slices, int stacks){
	this->base = base;
	this->top = top;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
	GLUquadric* cilindro = gluNewQuadric();
	this->cylin = cilindro;
}

void Cylinder::draw(float textS, float textT){
	gluQuadricTexture(this->cylin, true);
	gluCylinder(this->cylin, this->base, this->top, this->height, this->slices, this->stacks);
};

Sphere::Sphere(float radius, int slices, int stacks){
	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
	GLUquadric* esfera = gluNewQuadric();
	this->sph = esfera;
}

void Sphere::draw(float textS, float textT){
	gluQuadricTexture(this->sph, true);
	gluSphere(this->sph, this->radius, this->slices, this->stacks);
}

Torus::Torus(float inner, float outer, float slices, float loops){
	this->inner = inner;
	this->outer = outer;
	this->slices = slices;
	this->loops = loops;
}

void Torus::draw(float textS, float textT){
	glutSolidTorus(this->inner,this->outer,this->slices,this->loops); 
}