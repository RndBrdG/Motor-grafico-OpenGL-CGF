#ifndef PRIMITIVAS_H
#define PRIMITIVAS_H

#include <CGFobject.h>

class Primitivas {

};

class Rectangle : public Primitivas{
	float x1, x2;
	float y1, y2;
public:
	Rectangle(float x1, float x2, float y1, float y2);
	void draw();
};

class Triangle : public Primitivas{
	float x1, x2, x3;
	float y1, y2, y3;
	float z1, z2, z3;
public:
	Triangle(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3);
	void draw();
};

class Cylinder : public Primitivas{
	GLUquadric *cylin;
	float base, top;
	float height, slices, stacks;
public:
	Cylinder(float base, float top, float height, float slices, float stacks);
	void draw();
};

class Sphere : public Primitivas{
	GLUquadric *sph;
	float radius, slices, loops;
public:
	Sphere(float radius, float slices, float loops);
	void draw();
};

class Torus : public Primitivas{
	float inner, outer, slices;
	float loops;
public:
	Torus(float inner, float outer, float slices,float loops);
	void draw();
};

#endif