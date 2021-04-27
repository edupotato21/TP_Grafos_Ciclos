#pragma once

class Arista
{
public:
	Arista();
	Arista(double* peso);
	~Arista();

private:
	double* peso;
};

Arista::Arista()
{
	*this->peso = 0;
}

Arista::Arista(double *peso)
{
	*this->peso = *peso;
}

Arista::~Arista()
{
}