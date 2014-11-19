#ifndef FLAG_H
#define FLAG_H

#include <string>
#include "CGFshader.h"
#include "Primitiva.h"

class Flag : public Primitiva {
protected:
	std::string texture;
	CGFshader* shader;
public:
	Flag(std::string);
	~Flag();

	void draw(float, float);
	void draw();
};

#endif
