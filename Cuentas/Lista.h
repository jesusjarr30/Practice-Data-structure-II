#ifndef LISTA_H
#define LISTA_H
#include "Usuario.h"
#include<iostream>
#include <sstream>
#include <fstream>
using namespace std;
class Nodo
{
	private:
		Nodo *siguiente;
		Nodo *anterior;
		Usuario *Registro;
		
	public:
		Nodo();
		Nodo(Usuario *, Nodo *);
		void set_usuario(Usuario *);
		void set_siguiente(Nodo *);
		Nodo *get_siguiente();
		Nodo *get_anterior();
		Usuario *get_usuario();
		void set_aterior(Nodo *);
		
};
class Lista
{
	private:
		Nodo *primero;
	public:
		Lista();
		void ingresa(Usuario *);
		void ingresaf(Usuario *);
		bool validacion_correo(string);
		bool validacion_usuario(string);
		bool eliminar(Nodo *);
		bool inicio_de_seccion_correo(string,string);
		bool inicio_de_seccion_usuario(string,string);
		void imprimir_todo();
		string busqueda_impre(Nodo*);
		string busqueda_impres(Nodo*);
		void cambio_de_nombre(Nodo *,string);
		void cambio_de_contrasena(Nodo *,string);
		void cambio_de_usuario(Nodo *,string);
		void cambio_de_correo(Nodo *,string);
		Nodo *verficar_correo_usuario(string);
		Nodo *inicio_seccion();
		void toFile();
		void showall();
	
};

#endif
