#include "Menu.h"
int Menu::menu_principal(){
	system("cls");
	int opc;
	cout<<"Menu"<<endl;
	cout<<"1. Registrar nuevo usuario"<<endl;
	cout<<"2. Acceder"<<endl;
	cout<<"3. Recuperacion de cuenta"<<endl;
	cout<<"4. Administracion"<<endl;
	cout<<"5 Salir"<<endl;
	cin>>opc;
	return opc;
}
int Menu::menu_a(){
	system("cls");
	int opc;
	cout<<"Acceder a una cuenta"<<endl;
	cout<<"1. Mostrar"<<endl;
	cout<<"2. Modificar"<<endl;
	cout<<"3. Eliminar"<<endl;
	cout<<"4. salir"<<endl;
	cin>>opc;
	return opc;
}
int Menu::menu_admi(){
	system("cls");
	int opc;
	cout<<"Administracion"<<endl;
	cout<<"1. Mostrar todos por indice (llave primaria y direccion en archivo)."<<endl;
	cout<<"2. Mostrar todos en archivo"<<endl;
	cout<<"3. Generación automática de cuentas"<<endl;
	cin>>opc;
	return opc;
}
int Menu::eliminacion(){
	system("cls");
	int opc;
	cout<<"Elimicacion"<<endl;
	cout<<"1. Bloqueo temporal"<<endl;
	cout<<"2. Elimicacion permanente"<<endl;
	cin>>opc;
	return opc;
}
