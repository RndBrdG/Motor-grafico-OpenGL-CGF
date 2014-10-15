#ifndef CAMERA_H
#define CAMERA_H

#include "CGFcamera.h"

class Camera {
	char* id;
	char *type;
	char *direction;
	float near, far;
	float angle;
	float tarX,tarY,tarZ;
	float posX,posY,posZ;
	float left, right, top, bottom;
public:
	Camera(char *id, char *type, float near, float far, float angle, float tarX, float tarY, float tarZ, float posX, float posY, float posZ);
	Camera(char *id, char *type, char* direction, float left, float right, float top, float bottom);
	char* getId();
	float getNear();
	float getFar();
	float getAngle();
	char* getDirection();
	float getPosX();
	float getPosY();
	float getPosZ();
	float getTarX();
	float getTarY();
	float getTarZ();
	~Camera(){
		delete(this);
	}
};

#endif
