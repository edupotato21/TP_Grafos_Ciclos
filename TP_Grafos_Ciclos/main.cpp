#include <iostream>
#include <conio.h>
#include "Vertice.h"

using namespace std;
using namespace System;

struct g
{
	int id;
	double distancia;
};

void lugares() {
	cout << "1.-Cordillera Blanca" << endl;
	cout << "2.-Trujillo Chan Chan" << endl;
	cout << "3.-Senior de sipan" << endl;
	cout << "4.-Vichayito" << endl;
	cout << "5.-Mancora" << endl;
	cout << "6.-Manglares de Tumbes" << endl;
	cout << "7.-Cumbamayo" << endl;
	cout << "8.-Kuelap" << endl;
	cout << "9.-Iquito" << endl;
	cout << "10.-Pacaya Samira" << endl;
	cout << "11.-Tarapoto" << endl;
	cout << "12.-Pucallpa" << endl;
	cout << "13.-Tambopata" << endl;
	cout << "14.-Manu" << endl;
	cout << "15.-Machu Pichu" << endl;
	cout << "16.-Plaza de Armas - Cuzco" << endl;
	cout << "17.-Sillustani" << endl;
	cout << "18.-Plaza de Armas - Tacna" << endl;
	cout << "19.-Canion del Colca" << endl;
	cout << "20.-Pampas Galeras" << endl;
	cout << "21.-Lineas de Nazca" << endl;
	cout << "22.-Oasis Huacachina" << endl;
	cout << "23.-Paracas" << endl;
}

double distancia(Vertice *v, int i, int c) {
	double distancia = 0;
	int* x, * y, *x2, *y2;
	x = new int;
	y = new int;
	x2 = new int;
	y2 = new int;
	*x = v[i].getX();
	*y = v[i].getY();
	*x2 = v[c].getX();
	*y2 = v[c].getY();
	distancia = sqrt(pow(*x2 - *x, 2) + pow(*y2 - *y, 2));
	return distancia;
}

int menor(g *distancias, int num) {
	g *tem = new g;
	for (int i = 0; i < num; i++) {
		for (int c = 0; c < num - 1; c++) {
			if (distancias[c].distancia > distancias[c + 1].distancia) {
				*tem = distancias[c];
				distancias[c] = distancias[c + 1];
				distancias[c + 1] = *tem;
			}
		}
	}
	cout << "====================" << endl;
	cout << "La menor distancia es:" << distancias[0].distancia << " id: " << distancias[0].id << endl;
	cout << "====================" << endl;
	return distancias[0].id;
}

Vertice *borrar(Vertice *v, int id, int &num) {
	Vertice* tem = new Vertice[num];
	for (int i = 0, k = 0; i < num + 1; i++) {
		if (id != v[i].getId()) {
			tem[k] = v[i];
			k++;
		}
	}
	if (v != nullptr)
		delete[]v;
	num -= 1;
	return tem;
}

int main() {
	Console::SetWindowSize(120, 50);
	Vertice* v = new Vertice[24];
	v[0].setValores(310, 541, 0);
	v[1].setValores(285, 437, 1);
	v[2].setValores(243, 374, 2);
	v[3].setValores(172, 303, 3);
	v[4].setValores(138, 245, 4);
	v[5].setValores(122, 205, 5);
	v[6].setValores(135, 192, 6);
	v[7].setValores(213, 280, 7);
	v[8].setValores(269, 293, 8);
	v[9].setValores(449, 174, 9);
	v[10].setValores(454, 215, 10);
	v[11].setValores(314, 345, 11);
	v[12].setValores(410, 375, 12);
	v[13].setValores(584, 525, 13);
	v[14].setValores(622, 538, 14);
	v[15].setValores(498, 573, 15);
	v[16].setValores(544, 617, 16);
	v[17].setValores(597, 696, 17);
	v[18].setValores(593, 802, 18);
	v[19].setValores(499, 723, 19);
	v[20].setValores(421, 656, 20);
	v[21].setValores(378, 674, 21);
	v[22].setValores(358, 651, 22);
	v[23].setValores(346, 617, 23);
	/*for (int i = 0; i < 24; i++) {
		cout << "Posicion del vertice(x, y): (" << v[i].getX() << ", " << v[i].getY() << ")" << " id: " << v[i].getId() << endl;
	}*/
	int* vc;
	int num;
	int id = 0;
	int* arreglo;
	Vertice* v2;
	Vertice* grafo;
	g* distancias;//temporal
	/* Lista de lugares turisticos */
	lugares();
	do
	{
		cout << "Ingrese el numero de lugares que quiere visitar(6-23): ";
		cin >> num;
		cout << endl;
	} while (num < 6 || num > 23);
	vc = new int[num];//se crea un arreglo para dinamico para guardar los id de los lugares
	v2 = new Vertice[num + 1];//Se crea un nuevo arreglo para guardar las classes de las ciudades
	distancias = new g[num];
	grafo = new Vertice[num + 1];
	arreglo = new int[num + 1];
	//Se pide ingresar los id de los lugares para guardarlos en un arreglo
	for (int i = 0; i < num; i++) {
		cout << "Ingrese el numero de la ciudad: " << endl << "->";
		cin >> vc[i];
	}
	for (int i = 0; i < num; i++) {
		cout << vc[i] << " ";
	}
	cout << endl;
	v2[0] = v[0];
	grafo[0] = v[0];
	arreglo[0] = 0;
	for (int i = 0; i < num; i++) {
		for (int c = 0; c < 24; c++) {
			if (vc[i] == v[c].getId()) {
				v2[i + 1] = v[c];
				break;
			}
		}
	}
	for (int i = 0; i < num + 1; i++) {
		cout << "Posicion del vertice(x, y): (" << v2[i].getX() << ", " << v2[i].getY() << ")" << " id: " << v2[i].getId() << endl;
	}
	//Hallando la distancia entre 2 puntos
	int pos  = 0;
	int idtem = NULL;
	for (int i = 0, num2 = num; i < num; i++) {
		if (idtem != NULL) {
			v2 = borrar(v2, idtem, num2);
		}
		cout << "funciona" << endl;
		for (int c = 0, k = 0; c < num2 + 1; c++) {
			if (id != v2[c].getId()) {
				for (int h = 0; h < num2 + 1; h++)
				{
					if (id == v2[h].getId())
						pos = h;
				}
				distancias[k].distancia = distancia(v2, pos, c);
				distancias[k].id = v2[c].getId();
				k++;
			}
		}
		cout << "Distancias de " << id << endl;
		for (int h = 0; h < num2; h++) {
			cout << "Con " << distancias[h].id << ": " << distancias[h].distancia << endl;
		}
		/*nuevo codigo*/
		idtem = id;
		id = menor(distancias, num2);
		arreglo[i + 1] = id;
		if (i == 0) {
			v2 = borrar(v2, 0, num2);
		}
	}
	cout << "==================" << endl;
	for (int i = 0; i < num + 1; i++) {
		cout << arreglo[i];
		if (i != num)
			cout << " -> ";
	}
	cout << "\n==================" << endl;
	_getch();
	return 0;
}