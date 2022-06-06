#include <iostream>
#include "Menu.h"
#include "User.h"
#include "FileList.h"

using namespace std;

void registrar(FileList& lista);
void acceder(Menu& menu_p, FileList& lista);
void recupera(FileList& lista);
void admi(Menu& menu_p,FileList& lista);


int main(int argc, char** argv) {
	
	Menu menu_p;
	FileList lista("Fichero.bin");
	lista.carga_indices();
	lista.borrar_arch();
	int opc;
	do{
		opc=menu_p.menu_principal();
		switch (opc){
			case 1:
				registrar(lista);
				break;
			case 2:
				acceder(menu_p, lista);
				break;
			case 3:
				recupera(lista);
				break;
			case 4:
				admi(menu_p,lista);
				break;
		}
	}while(opc!=5);
	lista.guardar_indices();
	cout<<"Exito"<<endl;
	return 0;
}
void registrar(FileList& lista){
	///datos para igresar una cuenta
	char nombre[20];
	char usuario[20];
	char correo[20];
	char password[20];
	fflush(stdin);
	cout<<"Ingresa usuario"<<endl;
	cin.getline(usuario,20,'\n');
	//getline(cin,usuario);
	fflush(stdin);
	if(!lista.validacion_user(usuario)){
		cout<<"Este usuario ya esta ocupado"<<endl;
		system("pause");
	}
	else{
	cout<<"Ingresa su nombre"<<endl;
	cin.getline(nombre,20,'\n');
	//getline(cin,nombre);
	fflush(stdin);
	cout<<"Ingrese correo"<<endl;
	cin.getline(correo,20,'\n');
	//getline(cin,correo);
	fflush(stdin);
	cout<<"Ingrese password"<<endl;
	cin.getline(password,20,'\n');
	//getline(cin,password);
	fflush(stdin);
	User obj(nombre,usuario,correo,password);
	cout<<"El objeto es "<<obj.toString()<<endl;
	//system("pause");
	lista.add(obj);
	}
}
void acceder(Menu& menu_p, FileList& lista){
	
	string usuario;
	string password;
	cout<<"Ingrese usuario para poder iniciar secion"<<endl;
	fflush(stdin);
	getline(cin,usuario);
	cout<<"Ingrese contraseña del usuario"<<endl;
	fflush(stdin);
	getline(cin,password);
	if(lista.inicio_seccion(usuario,password)){
		int opc;
		int opc2;
		int opc3;
		string aux_cadena;
		do{
			
			opc=menu_p.menu_a();
			switch(opc){
				case 1:
					lista.mostrar_uno(usuario);
					system("pause");
					break;			
				case 2:
					cout<<"Modificar "<<endl;
					lista.mostrar_uno(usuario);
					cout<<"Que desea modificar "<<endl;
					cout<<"1. Usuario"<<endl;
					cout<<"2. nombre"<<endl;
					cout<<"3. correo"<<endl;
					cout<<"4. Password"<<endl;
					cout<<"5.salir"<<endl;
					cin>>opc2;
					if(opc2<5){
						//quiere decir que quiere modificar algo
						cout<<"Ingrese la palabra de remplazo"<<endl;
						fflush(stdin);
						getline(cin,aux_cadena);
						fflush(stdin);
						usuario=lista.modificar(usuario,opc2,aux_cadena);
					}
					break;
				case 3:
					opc3=menu_p.eliminacion();
					if(opc3==1){
						
						lista.block_temporal(usuario);
						return;
					}
					if(opc3==2){
						lista.block_perma(usuario);
						return;
					}
					
					break;
			}
		}while(opc!=4);
	}
	else{
		cout<<"Usaurio o contraseña incorrectos"<<endl;
		system("pause");
	}
}
void recupera(FileList&lista){
	string aux;
	cout<<"Ingrese nombre del usuario a restaurar"<<endl;
	fflush(stdin);
	getline(cin,aux);
	lista.recupera_u(aux);
}
void admi(Menu& menu_p,FileList& lista){
	int opc=menu_p.menu_admi();
	bool band=true;
	switch(opc){
		case 1:
			lista.showallindex();
			break;
		case 2:
			
			lista.showallorder();
			break;
		case 3:
			if(band){
			User obj("jjj","zzz","a@a","zzz");
			lista.add(obj);
			User obj1("max","ccc","c@c","www");
			lista.add(obj1);
			User obj2("antonio","ddd","d@d","ddd");
			lista.add(obj2);
			User obj3("juarez","eee","z@z","eee");
			lista.add(obj3);
			User obj4("jorge","fff","f@f","fff");
			lista.add(obj4);
			User obj5("ivan","ggg","g@g","ggg");
			lista.add(obj5);
			User obj6("adrian","hhh","h@h","hhh");
			lista.add(obj6);
			User obj7("toromax","iii","k@k","iii");
			lista.add(obj7);
			User obj8("tomas","jjj","k@k","jjj");
			lista.add(obj8);
			User obj9("omar","kkk","k@k","kkk");
			lista.add(obj9);
			User obj10("jesus","lll","k@k","lll");
			lista.add(obj10);
			cout<<"Se agregaron diez elemntos a la lista "<<endl;
			system("pause");
			band=false;
		}
			break;
	}
	
}

