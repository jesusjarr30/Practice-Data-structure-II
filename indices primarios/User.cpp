#include "User.h"
User::User(char nombre[20],char usuario[20],char correo[20],char password[20]){
	int i;
	for( i=0; i<=20;i++)
	
		this ->nombre[i]=nombre[i];
	for( i=0; i<=20;i++)
		this ->usuario[i]=usuario[i];
	for( i=0; i<=20;i++)
		this ->correo[i]=correo[i];
	for( i=0; i<=20;i++)
		this ->password[i]=password[i];	

}
User::User(string nombre_,string usuario_,string correo_,string password_){
	char nuevo_nombre[20];
	char nuevo_usuario[20];
	char nuevo_correo[20];
	char nuevo_password[20];
	int x=0;
	int longitud=0;
	//while para nombre
	longitud=nombre_.length();
	while(x<longitud){
		nuevo_nombre[x]=nombre_[x];
		x++;
	}
	x=0;
	while(x<20){
		this -> nombre[x]=nuevo_nombre[x];
		x++;
	}
	//while para usuario
	x=0;
	longitud=usuario_.length();
	while(x<longitud){
		nuevo_usuario[x]=usuario_[x];
		x++;
	}
	x=0;
	while(x<20){
		this -> usuario[x]=nuevo_usuario[x];
		x++;
	}
	//while para correo
	x=0;
	longitud=correo_.length();
	while(x<longitud){
		nuevo_correo[x]=correo_[x];
		x++;
	}
	x=0;
	while(x<20){
		this -> correo[x]=nuevo_correo[x];
		x++;
	}
	//while para password

	x=0;
	longitud=password_.length();
	while(x<longitud){
		nuevo_password[x]=password_[x];
		x++;
	}
	x=0;
	while(x<20){
		this -> password[x]=nuevo_password[x];
		x++;
	}
}
	

User::User(){
	
}

/*User::User(string nombre, string usuario, string correo, string password){
	this -> nombre= nombre;
	this -> usuario=usuario;
	this -> correo=correo;
	this -> password=password;
}*/
string User::get_usuario(){
	int longitud=strlen(usuario);
	string aux;
	for(int i=0;i<longitud;i++)
		aux+=usuario[i];

	return aux;
}
string User::get_password(){
	int longitud=strlen(password);
	string aux;
	for(int i=0;i<longitud;i++)
		aux+=password[i];
	return aux;
}
string User::toString(){
	stringstream ss;
	ss<<"Nombre: "<<nombre<<", Usuario: "<<usuario<<", Correo: "<<correo<<", Password: "<<password<<endl;
	return ss.str();
}
void User::set_usuario(string aux){
	char nuevo[20];
	int longitud;
	int x=0;
	longitud=aux.length();
	while(x<longitud){
		nuevo[x]=aux[x];
		x++;
	}
	x=0;
	while(x<20){
		usuario[x]=nuevo[x];
		x++;
	}
	//cout<<"el nuevo user temp es"<<usuario<<endl;
	//system("pause");
}
void User::set_nombre(string aux){
	char nuevo[20];
	int longitud;
	int x=0;
	longitud=aux.length();
	while(x<longitud){
		nuevo[x]=aux[x];
		x++;
	}
	x=0;
	while(x<20){
		nombre[x]=nuevo[x];
		x++;
	}
}
void User::set_correo(string aux){
	char nuevo[20];
	int longitud;
	int x=0;
	longitud=aux.length();
	while(x<longitud){
		nuevo[x]=aux[x];
		x++;
	}
	x=0;
	while(x<20){
		correo[x]=nuevo[x];
		x++;
	}
	
}
void User::set_password(string aux){
	char nuevo[20];
	int longitud;
	int x=0;
	longitud=aux.length();
	while(x<longitud){
		nuevo[x]=aux[x];
		x++;
	}
	x=0;
	while(x<20){
		password[x]=nuevo[x];
		x++;
	}
}
