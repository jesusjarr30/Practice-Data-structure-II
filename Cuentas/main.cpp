#include <iostream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Lista.h"
#include "Usuario.h"

using namespace std;

void nueva_cuenta(Lista &e,Usuario & user);
void acceder_a_cuenta(Lista &e,Nodo *d);
void mostrar_todo(Lista &e);

int main() {
	Lista e;
	e.showall();
	Usuario user;
	string activo;
	int opc;
		do{
			system("cls");
		cout<<"\t\n\n Menu principal "<<endl;
		cout<<"1. Crear una cuenta"<<endl;
		cout<<"2. Acceder a una cuenta"<<endl;
		cout<<"3. Mostrar todo"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>opc;
		system("cls");
		switch (opc){
			case 1:
				nueva_cuenta(e,user);
				break;
			case 2:	
			Nodo *d;
			d=e.inicio_seccion();
			if(d!=NULL)
					acceder_a_cuenta(e,d);
				break;
			case 3:
				mostrar_todo(e);
				break;
				
		}
	}while( opc!= 4);
	
	e.toFile();
	return 0;
}
void nueva_cuenta(Lista &e,Usuario &user){
	string nombre;
	string usuario;
	string password;
	string correo;
	int validacion;
	bool vali=false;
	bool a = false;
	
	cout<<"\t Crear cuenta"<<endl;
		fflush(stdin);
	cout<<"Ingrese correo electronico"<<endl;
	getline(cin,correo);	
	fflush(stdin);
	validacion = correo.length();

	for(int x=1;x<validacion;x++){
		if(correo[x]=='@')	// con esto validamos que el arroba por lo menos no se encutrea al final ni al inicio ya que el ciclo no llega a tal extremo
			a = true;
	}
	if(validacion<=2){
		a=false;
	}
	if(a == true){
		vali=e.validacion_correo(correo);
		if(vali== false){
			cout<<"Ingrese usuario"<<endl;
			getline(cin, usuario);
			fflush(stdin);
			vali=e.validacion_usuario(usuario);
			if(vali == false){
				cout<<"Ingrese nombre"<<endl;
				getline(cin,nombre);
				fflush(stdin);
				
				cout<<"Ingrese contraseña"<<endl;
				getline(cin,password);
				fflush(stdin);
				e.ingresaf(new Usuario(nombre,usuario,correo,password));
			}
		}		
	}

	
}
void acceder_a_cuenta(Lista &e,Nodo *d){
	int opc;
	int opc2;
	string cadena;
	do{	
	system("cls");
	cout<<"1. Mostrar cuenta"<<endl;
	cout<<"2. Modificar informacion"<<endl;
	cout<<"3. Eliminar Cuenta"<<endl;
	cout<<"4. Salir"<<endl;
	cin>>opc;
	system("cls");
	switch (opc){
		case 1:
			cout<<"Mostrar registro"<<endl;
			cadena=e.busqueda_impres(d);
			system("pause");
			break;
		case 2:
			
			do{
			cout<<"Modificar informacion"<<endl;
			cadena=e.busqueda_impre(d);
			//para modificar la contraseña se ocupa pedir la vieja contraseña
			fflush(stdin);
			cout<<"Ingres opcion"<<endl;
			cin>>opc2;
			system("cls");
			switch (opc2){
				case 1:
					fflush(stdin);
					cout<<"Ingrese nuevamente su nombre"<<endl;
					getline(cin,cadena);
					e.cambio_de_nombre(d,cadena);
					break;
				case 2:
					fflush(stdin);
					cout<<"Ingrese nuevamente su usuario"<<endl;
					getline(cin,cadena);
					e.cambio_de_usuario(d,cadena);
					fflush(stdin);
					break;
				case 3:
					fflush(stdin);
					cout<<"Ingrese nuevamente su correo electronico"<<endl;
					getline(cin,cadena);
					e.cambio_de_correo(d,cadena);
					//hacer la validacion de que el correo nuevo no este en uso
					break;
				case 4:
						fflush(stdin);
				cout<<"Ingrese antigua contraseña"<<endl;
				getline(cin,cadena);
				e.cambio_de_contrasena(d,cadena);
				break;						
					
			}
			
			}while(opc2!=5);
			
			break;
		case 3:
			cout<<"Eliminar Cuenta"<<endl;
			if(e.eliminar(d))
				opc=4;
			break;
	}
	
	
	}while(opc!=4);
	
}


void mostrar_todo(Lista &e){
	string cadena;
	system("cls");
	cout<<"Mostar todo"<<endl;
	e.imprimir_todo();
	system("pause");
}

