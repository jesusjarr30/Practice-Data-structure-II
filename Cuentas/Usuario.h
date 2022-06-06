#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Usuario
{
	private:
		string nombre;
		string usuario;
		string correo;
		string password;
	public:
		Usuario();
		Usuario(string,string,string,string);//costrutor
		Usuario(string);
		string print();
		string toFile();
		void print2();
		void mod_nombre(string);
		void mod_usuario(string);
		void mod_correo(string);
		void mod_password(string);
		string recupera_correo();
		string recupera_usuario();
		string recupera_password();
	
};

#endif
