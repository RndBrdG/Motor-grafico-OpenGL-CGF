#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <map>
#include <Primitivas.h>

typedef struct
{
	char* type, *axis;
	float toX, toY, toZ;
	float factorX, factorY, factorZ;
	float angle;
} transform;


class Graph {

	std::map<char*, Node> grafo;
public:

};

class Node {
	char* id;
	char* appRef;   // appeareance reference
	std::vector<transform> transformacoes;
	std::vector<Primitivas> primitivas;
public:

};


#endif