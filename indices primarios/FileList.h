#ifndef FILELIST_H
#define FILELIST_H
#include <iostream>
#include <fstream>
#include "User.h"
#include "StaticList.h"
#include "Index.h"

using namespace std;

class FileList
{
	private:
		StaticList indexList;
		string filename;
		
	public:
		FileList(string filename);
		void add(User obj);
		void showall();
		void showallindex();
		void showallorder();
		int showIndexList();
		bool validacion_user(char[20]);
		void guardar_indices();
		void carga_indices();
		bool inicio_seccion(string,string);
		void mostrar_uno(string);
		string modificar(string,int,string);
		void borrar_arch();
		void block_temporal(string);
		void block_perma(string);
		void recupera_u(string);
		
};

#endif
