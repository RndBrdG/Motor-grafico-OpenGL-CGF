#include "Animation.h"
#include "Primitiva.h"
#include <iostream>

Ponto::Ponto(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z; 
}

bool Ponto::operator >=(const Ponto &b) const{
	if (this->x >= b.x && this->y >= b.y && this->z >= b.z) return true;
	else return false;
}

bool Ponto::isGreater(const Ponto &b) const{
	return *this >= b;
}

Animation::Animation(string id, float span, const vector<Ponto*> pontosDeControlo){
	this->id = id;
	this->span = span;
	this->pontosDeControlo = pontosDeControlo;
}

unsigned int Animation::calculateDistance(Ponto* partida, Ponto* chegada){
	return sqrt((partida->x - chegada->x)*(partida->x - chegada->x) + (partida->y - chegada->y)*(partida->y - chegada->y) + (partida->z - chegada->z)*(partida->z - chegada->z));
}

LinearAnimation::LinearAnimation(string id, float span, const vector<Ponto*> pontosDeControlo) : Animation(id, span, pontosDeControlo){
	this->doReset = false;
	this->indicePontoControlo = 0;
	this->PontoActual = new Ponto(this->pontosDeControlo[0]->x, this->pontosDeControlo[0]->y, this->pontosDeControlo[0]->z);
	for (int i = 0; i < pontosDeControlo.size() - 1; i++){
		this->distancias.push_back(this->calculateDistance(pontosDeControlo[i], pontosDeControlo[i + 1]));
	}
	this->speed = 0.030 * this->distancias[0] / (this->span / this->pontosDeControlo.size());
}

void LinearAnimation::init(unsigned long t){
	this->initialStart = t;
	this->doReset = false;
	this->indicePontoControlo = 0;
	this->PontoActual->x = this->pontosDeControlo[0]->x;
	this->PontoActual->y = this->pontosDeControlo[0]->y;
	this->PontoActual->z = this->pontosDeControlo[0]->z;
	this->speed = 0.030 * this->distancias[0] / (this->span / this->pontosDeControlo.size());
}
void LinearAnimation::reset(){
	this->doReset = true;
}
void LinearAnimation::update(unsigned long t){
	if (doReset){
		init(t);
	}
	else {
		if (this->indicePontoControlo + 1 < this->pontosDeControlo.size()){
			if (this->PontoActual->isGreater(*this->pontosDeControlo[this->indicePontoControlo + 1])){
				this->indicePontoControlo += 1;
				this->speed = 0.030 * this->distancias[this->indicePontoControlo -1] / (this->span / this->pontosDeControlo.size());
				
			}
			if (this->indicePontoControlo + 1 < this->pontosDeControlo.size()){
				if (this->pontosDeControlo[this->indicePontoControlo]->x != this->pontosDeControlo[this->indicePontoControlo + 1]->x)
					this->PontoActual->x += this->speed;
				else if (this->pontosDeControlo[this->indicePontoControlo]->y != this->pontosDeControlo[this->indicePontoControlo + 1]->y)
					this->PontoActual->y += this->speed;
				else this->PontoActual->z += this->speed;
			}
			else this->reset();
		}
		else this->reset();
	}
}

void LinearAnimation::draw(){
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex2f(this->PontoActual->x, this->PontoActual->y);
	glVertex2f(this->PontoActual->x + 4, this->PontoActual->y);
	glVertex2f(this->PontoActual->x + 4, this->PontoActual->y  + 4);
	glVertex2f(this->PontoActual->x, this->PontoActual->y + 4);
	glEnd();
}