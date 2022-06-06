#include "Usuario.h"
Usuario::Usuario(){
	nombre="";
	usuario="";
	correo="";
	password="";
}
Usuario::Usuario(string nombre_,string usuario_,string correo_,string password_){
	this ->nombre = nombre_;
	this ->usuario = usuario_;
	this ->correo = correo_;
	this ->password = password_;
}

Usuario::Usuario(string row){
	int i=0;
	
	nombre="";
	usuario="";
	correo="";
	password="";
	while(row[i] != '|'){
        nombre += row[i];
        i++;
    }
    i++;
    while(row[i] != '|'){
        usuario += row[i];
        i++;
    }
    i++;
    while(row[i] != '|'){
        correo += row[i];
        i++;
    }
    i++;
    while(row[i] != '|'){
        password += row[i];
        i++;
    }
    i++;
	
}
string Usuario::print(){
	stringstream s;
	s<<"Nombre 	---->	"<<nombre<<endl;
	s<<"Usuario	---->	"<<usuario<<endl;
	s<<"correo	---->	"<<correo<<endl;
	s<<"password ---->	"<<password<<endl;
	s<<"--------------------------"<<endl;
	return s.str();
	
}
string Usuario::toFile(){
	stringstream s;
	s<<nombre<<"|"<<usuario<<"|"<<correo<<"|"<<password<<"|";
	return s.str();
	
}
void Usuario::print2(){
	cout<<"1. Nombre 	---->	"<<nombre<<endl;
	cout<<"2. Usuario	---->	"<<usuario<<endl;
	cout<<"3. correo	---->	"<<correo<<endl;
	cout<<"4. password     ---->	"<<password<<endl;
	cout<<"5. Salir"<<endl;
	cout<<"--------------------------"<<endl;
}
void Usuario::mod_nombre(string cadena){
	nombre = cadena;
}
void Usuario::mod_usuario(string cadena){
	usuario = cadena;
}
void Usuario::mod_correo(string cadena){
	correo = cadena;
}
void Usuario::mod_password(string cadena){
	password = cadena;
}
string Usuario::recupera_correo(){
	return correo;
}
string Usuario::recupera_usuario(){
	return usuario;
}
string Usuario::recupera_password(){
	return password;
}

