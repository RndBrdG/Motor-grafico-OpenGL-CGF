#include <Graph.h>

Node::Node(char* id){
	this->id = id;
}

char* Node::getId(){
	return this->id;
}

char* Node::getAppRef(){
	return this->appRef;
}

void Node::setMatrix(float matrix[16]){
	for (int i = 0; i < 16; i++)
		this->matrix[i] = matrix[i];
}

std::vector<Primitivas> Node::getPrimitivas(){
	return primitivas;
}