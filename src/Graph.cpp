#include <Graph.h>

std::map<std::string, Node*>& Graph::getGrafo(){
	return this->grafo;
}

Node::Node(std::string id){
	this->id = id;
}

std::string Node::getId(){
	return this->id;
}

std::string Node::getAppRef(){
	return this->appRef;
}

std::map<std::string, Node*>& Node::getDescendencia(){
	return this->descendencia;
}

std::vector<Primitivas*>& Node::getPrimitivas(){
	return primitivas;
}

void Node::setMatrix(float matrix[16]){
	for (int i = 0; i < 16; i++)
		this->matrix[i] = matrix[i];
}

void Node::setId(std::string id){
	this->id = id;
}

void Node::setAppRef(std::string appRef){
	this->appRef = appRef;
}


void Graph::draw(){
	typedef std::map<std::string, Node*>::iterator iterador;
	for (iterador it = grafo.begin(); it != grafo.end(); it++){
		for (int i = 0; i < it->second->getPrimitivas().size(); i++){
			it->second->getPrimitivas().at(i)->draw();
		}
	}
}