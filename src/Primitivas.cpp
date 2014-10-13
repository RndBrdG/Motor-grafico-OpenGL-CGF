#include <Primitivas.h>
#include <math.h>

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

void Rectangle::draw(){
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
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

	float a = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2) + pow((z1 - z3), 2));
	float b = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
	float c = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2) + pow((z3 - z2), 2));
	float teta = (a*a + b*b - c*c) / (2 * a*b);
	float beta = (a*a - b*b + c*c) / (2 * a*c);
	float alpha = (-a*a + b*b + c*c) / (2 * b*c);
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glScalef(1 / textS, 1 / textT, 1);
	glMatrixMode(GL_MODELVIEW);
	glBegin(GL_TRIANGLES);
		glNormal3f(0, 0, 1);
		glTexCoord2d(0, 0);
		glVertex3f(this->x1, this->y1, this->z1);
		glTexCoord2d(c-a*beta, a*beta);
		glVertex3f(this->x2, this->y2, this->z2);
		glTexCoord2d(c, 0);
		glVertex3f(this->x3, this->y3, this->z3);
	glEnd();
}

void Triangle::draw(){
	glBegin(GL_TRIANGLES);
		glNormal3f(0, 0, 1);
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

void Cylinder::draw(){
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

void Sphere::draw(){
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

void Torus::draw(){
	glutSolidTorus(this->inner, this->outer, this->slices, this->loops);
}