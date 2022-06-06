#ifndef STATICLIST_H
#define STATICLIST_H
#include "Index.h"
#include "User.h"
#include <iostream>
using namespace std;

class StaticList
{
	private:
		int count;
		Index* l;
		int N;
		
	public:
		StaticList();
		StaticList(int N);
		void insertaordenado(Index d);
		int find(Index d);
		Index& operator [](int i);
		void remove (int index);
		int bynarySerch(Index d,int i,int j);
		int get_count();
		void guardar_indices(Index d);
		void cambio_llave(string aux);
		
		
};

#endif
