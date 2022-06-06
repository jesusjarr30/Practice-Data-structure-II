#include <iostream>
#include <iostream>
#include "Menu.h"
#include "Graph.h"
#include "Lista.h"

using namespace std;

void create(Lista& e);
void remove(Lista& e);
void to_show(Lista& e);
void to_access(Lista& e);


int main() {
	Lista e;
	e.take_of();
	Menu menu;
	int opc;
	do{
		
		opc=menu.menu_principal();
		system("cls");
		switch(opc){
			case 1:
				create(e);
				break;
			case 2:
				remove(e);
				break;
			case 3:
				to_show(e);
				break;
			case 4:
				to_access(e);
				break;
		}
		
		
	}while(opc!=5);
	e.toFile();
	return 0;
}

void create(Lista& e){
	//no se si ponerlo tipo string
	char cadena;
	fflush(stdin);
	cout<<"Ingrese id del grafico que desa crear"<<endl;
	cin>>cadena;
	if(e.mapa_repetido(cadena)){
		DynamicGraph *d=new DynamicGraph(cadena);
		e.ingresa(d);
	d->addVertex('A');//agregar vertice principal
	d->addVertex('B');
	d->addVertex('C');
	d->addVertex('D');
	d->addVertex('E');
	d->addVertex('F');
	d->addVertex('G');
	d->addVertex('H');
	d->addVertex('Z');
	
	d->addEdge('A','B',2);//agregar arista
	d->addEdge('A','C',2);
	d->addEdge('B','D',2);
	d->addEdge('C','F',2);
	d->addEdge('F','E',2);
	d->addEdge('D','E',2);
	d->addEdge('E','Z',2);
	d->addEdge('D','G',2);
	d->addEdge('F','H',2);
	d->addEdge('G','Z',2);
	d->addEdge('H','Z',2);
		
		cout<<"Grafo creado correctamente"<<endl;
	}
	else
	cout<<"El grafo ya esta registrado"<<endl;
	system("pause");
	//solicitar id del grafo (unico), vertice inicial
}
void remove(Lista& e){
	char cadena;
	cout<<"Ingrese id del grafico que desa borrar"<<endl;
	cin>>cadena;
	fflush(stdin);
	e.quitar_lista(cadena);
}
void to_show(Lista& e){
	system("cls");
	DynamicGraph* d;
	e.find_grafo_principal();
	system("pause");
}
void to_access(Lista& e){
	Menu menu;
	char cadena;
	cout<<"Ingrese id del grafo al que desea ingresar"<<endl;
	cin>>cadena;
	e.find_grafo(cadena);
	
}
