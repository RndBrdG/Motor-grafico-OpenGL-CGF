#include "Camera.h"

Camera::Camera(char *id, float near, float far): CGFcamera(){
	this->id = id;
	this->near = near;
	this->far = far;
}

char* Camera::getId(){
	return id;
}

float Camera::getNear(){
	return near;
}

float Camera::getFar(){
	return far;
}

CameraPerspective::CameraPerspective(char* id, float near, float far, float angle, float posX, float posY, float posZ, float tarX, float tarY, float tarZ) : Camera(id, near, far){
	this->angle = angle;
	target[0] = tarX;
	target[1] = tarY;
	target[2] = tarZ;
	position[0] = posX;
	position[1] = posY;
	position[2] = posZ;
	setExamineMode();
}

float CameraPerspective::getAngle(){
	return angle;
}


CameraOrtho::CameraOrtho(char* id, char* direction, float near, float far, float left, float right, float top, float bottom) : Camera(id, near, far){
	this->direction = direction;

}

char* CameraOrtho::getDirection(){
	return direction;
}