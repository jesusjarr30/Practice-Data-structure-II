#include "StaticList.h"
StaticList::StaticList(){
	N=50;
	l=new Index[N];
	count=-1;
}

StaticList::StaticList(int N){
		this -> N=N;
		l= new Index[N];
}
void StaticList::insertaordenado(Index d){
	//cout<<"llegamos a ordenamietno"<<endl;
	//cout<<"count es"<<count<<endl;
	//cout<<"la n es "<<N<<endl;
	count++;
	l[count] = d;
		int j,i;
	
	// Ordenación
	for(i=0; i<count; i++){
		// Comparaciones
		for(j=0; j<count-i; j++){
		// Intercambiar los elementos
		if(l[j] > l[j+1]){
			d=l[j];
			l[j]=l[j+1];
			l[j+1]=d;
			}
		}
	}
}
void StaticList::remplazo(string usuario,string aux_usuario){
	string actual;

	for(int i=0; i<count; i++){
		actual = l[i].get_primarykey();
		if(actual==usuario)
			l[i].set_primaryKey(aux_usuario);
		
	}
	
}
 
int StaticList::find(Index d){
	
	return bynarySerch(d, 0, count-1);
}
Index& StaticList::operator [](int Index){
	if(Index>=0);
		if(Index<=count)
	return l[Index];
	throw("el contador debe de estar entre 0 y con-1");
}

void StaticList::remove (int index){
	if(index>=0);
		if(index<count){
			for(int i=index;i<count;i++)
				l[i]=l[i+1];
			count--;
			return;
			}
	throw("el contador debe de estar entre 0 y con-1");
	
	
}
int StaticList::bynarySerch(Index d,int i,int j){
	if(i > j)
		return -1;
	int p=(i+j)/2;
	if(l[p] == d)
		return p;
	if(l[p] > d)
		return bynarySerch(d,i,p-1);
	else 
		return bynarySerch(d,p+1,j);
}
int StaticList::get_count(){
	return count;
}
void StaticList::guardar_indices(Index d){
//	cout<<"inicion indices"<<endl;
	count++;
	l[count] = d;
	
}
void cambio_llave(string aux){
	
}
