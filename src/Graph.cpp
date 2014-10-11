#include <Graph.h>

Aparencia::Aparencia(std::string type, float x1, float x2, float x3){
	this->type = type;
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
}

std::string Aparencia::getType(){
	return this->type;
}

float Aparencia::getX1(){
	return x1;
}

float Aparencia::getX2() {
	return x2;
}

float Aparencia::getX3(){
	return x3;
}

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

std::vector<std::string>& Node::getDescendencia(){
	return this->descendencia;
}

std::vector<Primitivas*>& Node::getPrimitivas(){
	return primitivas;
}

bool Node::getRoot(){
	return this->root;
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

void Node::setRoot(bool root){
	this->root = root;
}

void Node::draw(std::map<std::string, Node*>& grafo){
	glMultMatrixf(&this->matrix[0]);

	for (unsigned int i = 0; i < this->primitivas.size(); i++){
		primitivas[i]->draw();
	}
	typedef std::vector<std::string>::iterator iter;
	
	for (iter it = this->getDescendencia().begin(); it != this->getDescendencia().end(); it ++){
		glPushMatrix();
		grafo[*it]->draw(grafo);
		glPopMatrix();
	
	}
}

std::string Graph::getRoot(){
	return this->root;
}

std::map<std::string, Aparencia >& Graph::getAparencias(){
	return this->aparencias;
}

void Graph::setRoot(std::string root){
	this->root = root;
}

void Graph::draw(){

	Node *noActual = this->getGrafo()[this->getRoot()];
	noActual->draw(this->getGrafo());
}