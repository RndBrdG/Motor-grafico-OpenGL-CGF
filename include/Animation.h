#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include <vector>

using namespace std;

class Ponto {
public:
	float x, y, z;
	Ponto(float x, float y, float z);
	bool Ponto::operator >=(const Ponto &b) const;
	bool isGreater(const Ponto &b) const;
};


class Animation {
protected:
	string id;
	float span;
	vector<Ponto*> pontosDeControlo;
	vector<unsigned int> distancias;
public:
	Animation(string id, float span, const vector<Ponto*> pontosDeControlo);
	unsigned int calculateDistance(Ponto* partida, Ponto* chegada);
	virtual void init(unsigned long t) = 0;
	virtual void reset() = 0;
	virtual void update(unsigned long t) = 0;
};

class LinearAnimation :public Animation {
	unsigned int indicePontoControlo;
	float speed;
	unsigned long initialStart;
	bool doReset;
	Ponto* PontoActual;
public:
	LinearAnimation(string id, float span, const vector<Ponto*> pontosDeControlo);
	void init(unsigned long t);
	void reset();
	void update(unsigned long t);
	void draw();
};


#endif