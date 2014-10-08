#include "Light.h"

Light::Light() {
	enabled = true;
	marker = true;

	x = 0., y = 0., z = 0.;

	ambR = 1., ambG = 1., ambA = 1.;
	difR = 1., difG = 1., difA = 1.;
	speR = 1., speG = 1., speA = 1.;
}

SpotLight::SpotLight() {
	Light();

	targetX = 1., targetY = 1., targetZ = 1.;
	angle = 0.;
	exponent = 0.;
}
