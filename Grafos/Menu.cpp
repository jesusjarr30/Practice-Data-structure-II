#include "Menu.h"
int Menu::menu_principal(){
	int opc;
	system("cls");
	cout<<">>>>>>>>>> Menu principal <<<<<<<<"<<endl;
	cout<<"1. Creara grafo"<<endl;
	cout<<"2. Eliminar grafo"<<endl;
	cout<<"3. Mostrar grafo global"<<endl;
	cout<<"4. Acceder"<<endl;
	cout<<"5. Salir"<<endl;
	cin>>opc;
	return opc;
	
}
int Menu::menu_show(){
	int opc;
	cout<<"1. Mostrar grafo"<<endl;
	cout<<"2. Mostrar lugar actual"<<endl;
	cout<<"3. Mostar lugares adyacentes"<<endl,
	cout<<"4. Despazarse"<<endl;
	cout<<"5. Salir"<<endl;
	cin>>opc;
	return opc;
}

