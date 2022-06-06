#ifndef USER_H
#define USER_H
#include <iostream>
#include <sstream>

#include <string.h>
using namespace std;

class User
{
	private:
		
		char nombre[20];
		char usuario[20];
		char correo[20];
		char password[20];
		/*string nombre;
		string usuario;
		string correo;
		string password;*/
		
	public:
		User();
		User(char nombre[20],char usuario[20],char correo[20],char password[20]);
		User(string nombre_,string usuario_,string correo_,string password_);
		string toString();
		string get_usuario();
		string get_password();
		void set_usuario(string aux);
		void set_nombre(string);
		void set_correo(string);
		void set_password(string);
		
		
};

#endif
