#include <Graph.h>


Textura::Textura(std::string id, std::string file, float texlength_s, float texlength_t){
	this->id = id;
	this->file = file;
	this->texlength_s = texlength_s;
	this->texlength_t = texlength_t;
}

Textura::~Textura(){
	delete(this);
}

string Textura::getId(){
	return this->id;
}

string Textura::getFile(){
	return this->file;
}

float Textura::getTexLenS(){
	return this->texlength_s;
}

float Textura::getTexLenT(){
	return this->texlength_t;
}

Aparencia::Aparencia(std::string id, float shininess, std::string textRef, float ambient[4], float difusa[4], float especular[4]) : CGFappearance(ambient, difusa, especular, shininess){
	this->id = id;
	this->shininess = shininess;
	this->textRef = textRef;
}

Aparencia::~Aparencia(){
	delete(this);
}

string Aparencia::getId(){
	return this->id;
}
string Aparencia::getTextRef(){
	return this->textRef;
}


map<std::string, Node*>& Graph::getGrafo(){
	return this->grafo;
}

Node::Node(std::string id){
	this->id = id;
}

Node::~Node(){
	delete(this);
}

string Node::getId(){
	return this->id;
}

string Node::getAppRef(){
	return this->appRef;
}

vector<std::string>& Node::getDescendencia(){
	return this->descendencia;
}

vector<Primitivas*>& Node::getPrimitivas(){
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

void Node::draw(std::map<std::string, Node*>& grafo, std::map < std::string, Aparencia*>& aparencias, std::string referenciaApp, std::map < std::string, Textura*>& texturas){
	glMultMatrixf(&this->matrix[0]);

	if (this->appRef != "inherit"){
		aparencias[this->appRef]->apply();
	}
	else {
		aparencias[referenciaApp]->apply();
		this->appRef = referenciaApp;
	}
	int size = this->primitivas.size();

	for (unsigned int i = 0; i < size; i++){
		if (aparencias[appRef]->getTextRef() != "null"){
			float texS = texturas[aparencias[appRef]->getTextRef()]->getTexLenS();
			float texT = texturas[aparencias[appRef]->getTextRef()]->getTexLenT();
			primitivas[i]->draw(texS, texT);
		}
		else primitivas[i]->draw();
	}
	typedef std::vector<std::string>::iterator iter;
	
	for (iter it = this->getDescendencia().begin(); it != this->getDescendencia().end(); it ++){
		glPushMatrix();
		grafo[*it]->draw(grafo, aparencias, this->appRef,texturas);
		glPopMatrix();
	
	}
}

string Graph::getRoot(){
	return this->root;
}

map<std::string,Aparencia*>& Graph::getAparencias(){
	return this->aparencias;
}

void Graph::setRoot(std::string root){
	this->root = root;
}

void Graph::draw(){
	
	Node *noActual = this->getGrafo()[this->getRoot()];
	noActual->draw(this->getGrafo(), this->getAparencias(), this->getGrafo()[this->getRoot()]->getAppRef(), this->texturas);
}

map<std::string, Textura*>& Graph::getTexturas(){
	return this->texturas;
}

map < std::string, Camera*>& Graph::getCamaras(){
	return this->camaras;
}

void Graph::setDefaultCamera(std::string cameraDefault){
	this->cameraDefault = cameraDefault;
}

string Graph::getCameraDefault(){
	return this->cameraDefault;
}
