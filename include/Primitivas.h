#ifndef PRIMITIVAS_H
#define PRIMITIVAS_H

class Primitivas {

};

class Rectangle : public Primitivas{
	float x1, x2;
	float y1, y2;
public:
	Rectangle();
};

class Triangle : public Primitivas{
	float x1, x2, x3;
	float y1, y2, y3;
	float z1, z2, z3;
public:
	Triangle();
};

class Cylinder : : public Primitivas{
	float base, top;
	float height, slices, stacks;
public:
	Cylinder();
}

class Sphere : : public Primitivas{
	float radius, slices, loops;
public:
	Sphere();
}

class Torus : : public Primitivas{
	float inner, outer, slices;
	float loops;
public:
	Sphere();
}

#endif