#include "Index.h"
Index::Index(){
}
Index::Index(int index,string primaryKey){
	this -> index = index;
	this ->primaryKey = primaryKey;
}
string Index::toString(){
	stringstream ss;
	ss<<"Index   "<< index <<"  Llave primaria  "<<primaryKey<<endl;
	return ss.str();
}
//gets
int Index::getIndex(){
	return index;
}
string Index::get_primarykey(){
	return primaryKey;
}
bool Index::operator >(Index right){
	return  this ->primaryKey > right.primaryKey;
}
bool Index::operator ==(Index right){
	return this->primaryKey == right.primaryKey;
}
string Index::guardar(){
	stringstream ss;
		ss<<index<<'|'<<primaryKey<<endl;//para verdadero
	return ss.str();
} 
void Index::set_primaryKey(string aux){
	this -> primaryKey=aux;
}

