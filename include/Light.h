#ifndef LIGHT_H
#define LIGHT_H

#include <string>

class Light {
	friend class XMLScene;

protected:
	std::string id;
	bool enabled;
	bool marker;

	float x, y, z;

	float ambR, ambG, ambB, ambA;
	float difR, difG, difB, difA;
	float speR, speG, speB, speA;

public:
	Light();
};

class SpotLight : public Light {
	friend class XMLScene;

protected:
	float targetX, targetY, targetZ;
	float angle;
	float exponent;

public:
	SpotLight();
};

#endif
