#include "Lista.h"
Nodo::Nodo(){
	Registro = NULL;
	siguiente = NULL;
	anterior = NULL;
}
Nodo::Nodo(DynamicGraph *a,Nodo *sig){
	Registro = a;
	siguiente = sig;
}
void Nodo::set_graph(DynamicGraph *a){
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
DynamicGraph* Nodo::get_graph(){
	return Registro;
}
Nodo* Nodo::get_anterior(){
	return anterior;
}

Lista::Lista(){
	primero = NULL;
}
void Lista::ingresa(DynamicGraph *e)
{
	primero=new Nodo(e, primero);
}
bool Lista::mapa_repetido(char nombre_){
	int x=0;
	bool bandera;
	Nodo* p=primero;
	while(p!=NULL){
		//	x=strcmp(p->get_graph()->get_nombre(),nombre_);
			if(nombre_==p->get_graph()->get_nombre())
				return false; //retorna falso cuando son iguales
		p=p->get_siguiente();
	}
	return true; //si se puede utilizar el nombre.
	system("pause");
}

void Lista::mostrar_mapa_principal(){
	int x=0;
	bool bandera;
	Nodo* p=primero;
	while(p!=NULL){
		//	if('n'==p->get_graph()->get_nombre())
		//		cout<<""<<p->get_graph()->toString()<<endl;
		p=p->get_siguiente();
	}
	system("pause");
}

void Lista::toFile(){
	Nodo *p = primero;
	ofstream fout("list_graph.txt",ios::trunc);
	while(p!=NULL){
	//	cout<<"entra al while"<<endl;
		fout <<p->get_graph()->toFile()<<endl;
		p=p->get_siguiente();
		//cout<<"p es"<<p<<endl;
		//cout<<"abajo while"<<endl;
	}
	fout.close();
}
void Lista::take_of(){
	int x;
	
	ifstream fin ("list_graph.txt");
		string cadena;
		
		if(!fin.fail()){
			while(getline(fin,cadena)){
				//cout<<"entra la primera vez"<<endl;
				x=cadena.length();
				if(x!=0)  {
					string recortev="";
					string recorte="";
					string co="";
					int x=0;
					char v_1;
					int cont=0;
					int conta=0;
					string vv;
				    DynamicGraph* d=new DynamicGraph(cadena[0]);
				    
					d->addVertex(cadena[2]);
					d->addVertex(cadena[4]);
					d->addVertex(cadena[6]);
					d->addVertex(cadena[8]);
					d->addVertex(cadena[10]);
					d->addVertex(cadena[12]);
					d->addVertex(cadena[14]);
					d->addVertex(cadena[16]);
					d->addVertex(cadena[18]);
					//cout<<"Ingresamos a la funcion"<<endl;
					//cout<<"x es"<<x<<endl;
					//cout<<"cadena tamano es "<<cadena.length()<<endl;
					while(x<=cadena.length()){
						
				//		cout<<"cadena es dentro while "<<cadena[x]<<endl;
						if(cadena[x]=='@'){
							cont++;
							}
						if(cont==2){
							recorte+=cadena[x];	
						 }
						 if(cont==3){
						 	recortev+=cadena[x];
						 }
						 x++;
						}
						int i=1;
						while(i<recorte.length()){
						//cout<<"El pedaso de recorte es"<<recorte[i]<<endl;
						if(recorte[i]=='|'){
						//	cout<<"entra en if"<<endl;
							i++;
							v_1=recorte[i];
							i++;
						 }
						 
						//cout<<" apunta a  "<<v_1<<" ->"<<recorte[i]<<endl;
						d->addEdge2(v_1,recorte[i],2);
						i++;
						//cout<<"Siguiente en la lista"<<recorte[i]<<endl;
						//system("pause");
						}
						//d->set_visitados(recortev);
						//cout<<"recorte v es "<<recortev<<endl;
						//system("pause");
					ingresa(d);	
				//	cout<<"D es "<<d->toString();
				//	system("pause");
				}
			
         }
     }
      //system("pause");
  }


void Lista::find_grafo_principal(){
	Nodo *p=primero;
	while(p!=NULL){
		if(p->get_graph()->get_nombre()=='n')
			cout<<p->get_graph()->toString();
		p=p->get_siguiente();
	}
}
void Lista::quitar_lista(char nombre){	
	Nodo* p= primero;
	Nodo* aux=NULL;
	if(p != NULL){
		while(p!= NULL && p->get_graph()->get_nombre()!=nombre){
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
}
void Lista::find_grafo(char n){
	Menu menu;
	int opc;
	DynamicGraph *d=NULL;
	Nodo *p=primero;
	while(p!=NULL){
		if(p->get_graph()->get_nombre()==n)
			d=p->get_graph();
		p=p->get_siguiente();
	}
	if(d==NULL){
		cout<<"No se encontro el grafo al cual quiere acceder"<<endl;
		system("pause");
		return;
	}
	do{
		system("cls");
		char m;
		opc=menu.menu_show();
		switch (opc){
			case 1:
				cout<<""<<d->toString2()<<endl;
				break;
			case 2:
				cout<<"La posicion actual es "<<d->get_actual()<<endl;
				break;
			case 3:
				cout<<"Lugares a los cuales se puede desplazar son :"<<d->lugares_adyacentes()<<endl;
				break;
			case 4:
				fflush(stdin);
				cout<<"Ingrese el nombre del vertice al que quiere desplazarze"<<endl;
				cin>>m;
				d->despalzarse(m);
				
				break;
		}
		system("pause");
	}while(opc!=5);
	
}
