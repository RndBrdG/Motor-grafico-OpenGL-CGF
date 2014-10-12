#ifndef LIGHT_H
#define LIGHT_H

#include "CGFlight.h"

#include <string>

class Light : public CGFlight {
	friend class XMLScene;

protected:
	static int num;

	int lightNum;
	std::string id;
	bool marker;
	float exponent;

public:
	Light(unsigned int lightid, float* pos, float *dir = NULL, float angle = 180., float exponent = 0.);

	int getLightNum();
	float getAngle();
	bool getEnabled();
	bool getMarker();
	float getExponent();
	~Light(){
		delete(this);
	}
	int onOff;
};

#endif
