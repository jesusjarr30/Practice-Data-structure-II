#ifndef LISTA_H
#define LISTA_H
#include "Graph.h"
#include<iostream>
#include <sstream>
#include <fstream>
#include "Graph.h"
#include "Menu.h"
using namespace std;
class Nodo
{
	private:
		Nodo *siguiente;
		Nodo *anterior;
		DynamicGraph *Registro;
		
	public:
		Nodo();
		Nodo(DynamicGraph *, Nodo *);
		void set_graph(DynamicGraph *);
		void set_siguiente(Nodo *);
		Nodo *get_siguiente();
		Nodo *get_anterior();
		DynamicGraph *get_graph();
		void set_aterior(Nodo *);
		
};
class Lista
{
	private:
		Nodo *primero;
	public:
		Lista();
		void ingresa(DynamicGraph *);
		void toFile();
		void take_of();
		bool mapa_repetido(char);
		void mostrar_mapa_principal();
		void find_grafo_principal();
		void quitar_lista(char);
		void find_grafo(char);
	
};
#endif
