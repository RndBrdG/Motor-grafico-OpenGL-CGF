#ifndef FLAG_H
#define FLAG_H

#include <string>
#include "Primitiva.h"

class Flag : public Primitiva {
protected:
	std::string texture;
public:
	Flag(std::string);

	void draw(float, float);
	void draw();
};

#endif
