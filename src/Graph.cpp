#include <Graph.h>


Aparencia::Aparencia(std::string id, float shininess, std::string textRef, float ambient[4], float difusa[4], float especular[4]) : CGFappearance(ambient, difusa, especular, shininess){
	this->id = id;
	this->shininess = shininess;
	this->textRef = textRef;
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

void Node::draw(std::map<std::string, Node*>& grafo, std::map < std::string, Aparencia*>& aparencias,std::string referenciaApp){
	glMultMatrixf(&this->matrix[0]);

	if (this->appRef != "inherit" && aparencias[this->appRef] != NULL){
		aparencias[this->appRef]->apply();
	}
	else aparencias[referenciaApp]->apply();

	int size = this->primitivas.size()
	for (unsigned int i = 0; i < size; i++){
		primitivas[i]->draw();
	}
	typedef std::vector<std::string>::iterator iter;
	
	for (iter it = this->getDescendencia().begin(); it != this->getDescendencia().end(); it ++){
		glPushMatrix();
		grafo[*it]->draw(grafo,aparencias,this->appRef);
		glPopMatrix();
	
	}
}

std::string Graph::getRoot(){
	return this->root;
}

std::map<std::string,Aparencia*>& Graph::getAparencias(){
	return this->aparencias;
}

void Graph::setRoot(std::string root){
	this->root = root;
}

void Graph::draw(){

	Node *noActual = this->getGrafo()[this->getRoot()];
	noActual->draw(this->getGrafo(),this->getAparencias(),noActual->getAppRef());
}