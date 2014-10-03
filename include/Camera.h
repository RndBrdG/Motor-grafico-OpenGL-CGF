#ifndef CAMERA_H
#define CAMERA_H

#include "CGFcamera.h"

class Camera : public CGFcamera{
	char* id;
	float near, far;

public:
	Camera(char *id, float near, float far);
	char* getId();
	float getNear();
	float getFar();
};

class CameraPerspective : public Camera {

	float angle;
	float posX, posY, posZ;
	float tarX, tarY, tarZ;

public:
	CameraPerspective(char* id, float near, float far, float angle, float posX, float posY, float posZ, float tarX, float tarY, float tarZ);
	float getAngle();
	float getPosX();
	float getPosY();
	float getPosZ();
	float getTarX();
	float getTarY();
	float getTarZ();
};

class CameraOrtho : public Camera {
	char *direction;
	float left, right, top, bottom;
public:
	CameraOrtho(char* id, char* direction, float near, float far, float left, float right, float top, float bottom);
	char* getDirection();
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();
};
#endif
