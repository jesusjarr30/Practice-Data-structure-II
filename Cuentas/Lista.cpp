#include "Lista.h"
Nodo::Nodo(){
	Registro = NULL;
	siguiente = NULL;
	anterior = NULL;
}
Nodo::Nodo(Usuario *a,Nodo *sig){
	Registro = a;
	siguiente = sig;
}
void Nodo::set_usuario(Usuario *a){
	Registro = a;
}
void Nodo::set_siguiente(Nodo *sig){
		siguiente = sig;
}
void Nodo::set_aterior(Nodo *ant){
	anterior = ant;
}
Nodo* Nodo::get_siguiente(){
	return siguiente;
}
Usuario* Nodo::get_usuario(){
	return Registro;
}
Nodo* Nodo::get_anterior(){
	return anterior;
}

Lista::Lista(){
	primero = NULL;
}
void Lista::ingresa(Usuario *e)
{
	primero=new Nodo(e, primero);
}

void Lista::ingresaf(Usuario *e){
	Nodo *p = primero;
	Nodo *nuevo;
	if(p==NULL)
	{
		ingresa(e);
			}
	else{
		while(p->get_siguiente() !=NULL){
			p=p->get_siguiente();
		}
		
		nuevo=new Nodo(e,NULL);
		p->set_siguiente(nuevo);
		nuevo->set_aterior(p);
	}
}
bool Lista::validacion_correo(string cadena){
	Nodo *p= primero;
	if(p == NULL)
		return	false;
		while(p!= NULL){
		
			if(p->get_usuario()->recupera_correo() == cadena){
				return true;//retorna verdadero si se encuntra en uso
			}
			p=p->get_siguiente();
		}
		return false;//retorna falso si el correo no esta en uso
}
bool Lista::validacion_usuario(string cadena){
	Nodo *p= primero;
	if(p == NULL)
		return false;
	while(p!= NULL){
		if(p->get_usuario()->recupera_usuario()== cadena)
			return true;//Si ya se encuntra en uso regresa true
		p=p->get_siguiente();
	}	
	return false;	//Si esta disponible false
}
bool Lista::eliminar(Nodo *d){
	bool eliminacion=false;
	string pass;
	string aux_correo;
	Nodo *p = primero;
	Nodo *aux=NULL;
	Nodo *anterior=NULL;	
	fflush(stdin);
	cout<<"Ingrese contraseña para poder eliminar la cuenta"<<endl;
	getline(cin,pass);
	if(d->get_usuario()->recupera_password()== pass){
		aux_correo=d->get_usuario()->recupera_correo();
		if(p != NULL){
		while(p!= NULL && p->get_usuario()->recupera_correo()!=aux_correo){
			aux=p;
			p=p->get_siguiente();
			cout<<"Registro eliminado con exito"<<endl;
			system("pause");
		}
	}
			if(aux==NULL){
					primero=p->get_siguiente();
					p->set_aterior(NULL);
				}
				else{
					aux->set_siguiente(p->get_siguiente());	
					aux->set_aterior(p->get_anterior());
				}
				delete p;
				eliminacion=true;	
	}
	else{
		cout<<"Contraseña incorrecta, no se puede eliminar el registro"<<endl;
	}
	return eliminacion;
	
}

void Lista::imprimir_todo(){
	Nodo *p = primero;
	string h;
	while(p!=NULL){
		//cout<<"Dirrecion de memoria"<<p<<endl;
		h=p->get_usuario()->print();
		cout<<h<<endl;
		p=p->get_siguiente();
					
	}

}
string Lista::busqueda_impre(Nodo *d){

	d->get_usuario()->print2();
	return".";
}
string Lista::busqueda_impres(Nodo *d){
	string h;
	h=d->get_usuario()->print();
	cout<<h;
	return".";
}
void Lista::cambio_de_nombre(Nodo *d,string cadena){
	//cadena es el remplazo y activo el usaurio o correo
	d->get_usuario()->mod_nombre(cadena);
}
void Lista::cambio_de_contrasena(Nodo *d,string cadena){
	Nodo *p=primero;
	string nueva;
	bool validacion =false;
		
	while(p!=NULL){
		if(p->get_usuario()->recupera_password() == cadena){
			validacion = true;
			
			}
		p=p->get_siguiente();
	}
	if(validacion== false){
		cout<<"Contraseña incorrecta"<<endl;
			system("pause");
			system("cls");
		}
	if(validacion){
		fflush(stdin);
		cout<<"Ingresa su nueva contraseña"<<endl;
		getline(cin,nueva);
		d->get_usuario()->mod_password(nueva);
		}

}
void Lista::cambio_de_usuario(Nodo *d,string cadena){
	Nodo *p=primero;
	bool validacion =true;
	while(p!=NULL){
		if(p->get_usuario()->recupera_usuario() == cadena){
		
			validacion = false;
			cout<<"Usuario repetido"<<endl;
			system("pause");
			system("cls");
			}
		p=p->get_siguiente();
	}
	if(validacion)
		d->get_usuario()->mod_usuario(cadena);
}
void Lista::cambio_de_correo(Nodo *d,string cadena){
	//activo es el usuario y cadena el remplazo
	Nodo *p=primero;
	bool validacion =true;
	while(p!=NULL){
		if(p->get_usuario()->recupera_correo() == cadena){
		
			validacion = false;
			cout<<"correo repetido"<<endl;
			system("pause");
			system("cls");
			}
		p=p->get_siguiente();
	}
	if(validacion)
		d->get_usuario()->mod_correo(cadena);
}
Nodo* Lista::verficar_correo_usuario(string cadena){
	Nodo *p=primero;
	Nodo *dirrecion= NULL;
	int largo;
	bool def=false;
	largo=cadena.length();
	for(int x=0;x<=largo;x++){
		if(cadena[x]=='@')
			def = true;
	}
	if(def == true){
		while(p!= NULL){
			if(p->get_usuario()->recupera_correo()==cadena){
				dirrecion=p;
			}
			p=p->get_siguiente();
		}
	}
	if(def ==false){
		while(p!= NULL){
			if(p->get_usuario()->recupera_usuario()==cadena){
				dirrecion=p;
			}
			p=p->get_siguiente();
		}
	}
	return dirrecion;
}
Nodo* Lista::inicio_seccion(){
	string activo;
	string pass;
	Nodo *dirrecion=NULL;
	Nodo *error=NULL;
	fflush(stdin);
	cout<<"Ingresa el correo o usuario para iniciar seccio"<<endl;
	getline(cin,activo);
	dirrecion=verficar_correo_usuario(activo);
	if(dirrecion!=NULL){
	cout<<"Ingresa contraseña"<<endl;
	getline(cin,pass);
	if(dirrecion->get_usuario()->recupera_password() == pass)
		return dirrecion;
	}
	else
		return error;
} 
void Lista::toFile(){
	Nodo *p = primero;
	ofstream fout("Accounts.txt",ios::trunc);//

	while(p!=NULL){
		fout << p->get_usuario() ->toFile() <<endl;
		p=p->get_siguiente();			
	}
	fout.close();
}
void Lista::showall(){
	int x;
    ifstream fin("Accounts.txt");
		string cadena;
	if(!fin.fail()){
		while(getline(fin,cadena)){
			x=cadena.length();
			if(x!= 0)
			ingresaf(new Usuario(cadena));
		}
	}
}


