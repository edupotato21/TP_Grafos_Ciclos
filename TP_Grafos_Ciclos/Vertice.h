#pragma once
class Vertice
{
public:
	Vertice();
	Vertice(int* x, int* y, int *id);
	~Vertice();
	int getX();
	int getY();
	int getId();
	void setValores(int x, int y, int id);
private:
	int* x = new int;
	int* y = new int;
	int* id = new int;
};

Vertice::Vertice()
{
	*this->x = 0;
	*this->y = 0;
	*this->id = 0;
}

Vertice::Vertice(int* x, int* y, int *id)
{
	*this->x = *x;
	*this->y = *y;
	*this->id = *id;
}

Vertice::~Vertice()
{
}

int Vertice::getX() {
	return *this->x;
}

int Vertice::getY() {
	return *this->y;
}

int Vertice::getId() {
	return *this->id;
}

void Vertice::setValores(int x, int y, int id) {
	*this->x = x;
	*this->y = y;
	*this->id = id;
}