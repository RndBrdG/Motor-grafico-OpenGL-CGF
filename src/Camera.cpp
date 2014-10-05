#include "Camera.h"

Camera::Camera(char *id, float near, float far){
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
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->tarX = tarX;
	this->tarY = tarY;
	this->tarZ = tarZ;
}

float CameraPerspective::getAngle(){
	return angle;
}

float CameraPerspective::getPosX(){
	return posX;
}

float CameraPerspective::getPosY(){
	return posY;
}

float CameraPerspective::getPosZ(){
	return posZ;
}

float CameraPerspective::getTarX(){
	return tarX;
}

float CameraPerspective::getTarY(){
	return tarY;
}

float CameraPerspective::getTarZ(){
	return tarZ;
}

CameraOrtho::CameraOrtho(char* id, char* direction, float near, float far, float left, float right, float top, float bottom) : Camera(id, near, far){
	this->direction = direction;
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

char* CameraOrtho::getDirection(){
	return direction;
}

float CameraOrtho::getLeft(){
	return left;
}

float CameraOrtho::getRight(){
	return right;
}

float CameraOrtho::getTop(){
	return top;
}

float CameraOrtho::getBottom(){
	return bottom;
}