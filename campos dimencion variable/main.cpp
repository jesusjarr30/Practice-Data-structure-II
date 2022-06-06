#include <iostream>
#include "Personaje.h"
#include "FileList.h"

using namespace std;

//funciones
void agregar(FileList& lista);
void acceder(FileList& lista);
void eliminar(FileList& lista);


int main() {

    FileList lista("Archivo1.bin");
	int opc;
	do{
		system("cls");
        cout<<"\t\t<<<<<<<<< Menu >>>>>>>>>>>>>>>"<<endl;
        cout<<"\t\t1. Agregar nuevo personaje"<<endl;
        cout<<"\t\t2. Acceder a personaje"<<endl;
        cout<<"\t\t3. Eliminar personaje"<<endl;
       // cout<<"\t\t4. Mostrar todo"<<endl;
        cout<<"\t\t4. Salir"<<endl;
        cout<<"\t\tIngrese opcion"<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                agregar(lista);
                break;
            case 2:
                acceder(lista);
                break;
            case 3:
                eliminar(lista);
                break;
            //case 4:
            //	lista.showall();
            //	break;
        }
	} while(opc!=4);

	return 0;
}

void agregar(FileList& lista){
	Personaje* p;
    int cate;
    int cate2;
    string nombre;
    string clase;
    string bando;
    string historial_misiones;
    string inventario;
    int nivel = 0;
    int experiencia = 0;
    fflush(stdin);
    cout<<"Agregar un personaje"<<endl;
    cout<<"Ingrese nombre del soldado"<<endl;
    getline(cin,nombre);
    fflush(stdin);
    if(lista.find_nombre(nombre)== false){
	
	    cout<<"ingrese categoria a la que quiera pertenecer"<<endl;
	    cout<<"Opciones"<<endl;
	    cout<<"\t1. Unidad de Infanteria \n\t2. Unidad Blindada(tanques)"<<endl;
	    cout<<"selecione numero"<<endl;
	    cin>>cate;
	    if(cate == 1)
	        clase = "Unidad de infanteria";
	    else
	        if(cate == 2)
	            clase ="Unidad blindada";
	    cout<<"bando a escojer"<<endl;
	    cout<<"\t 1. Estados Unidos \n\t 2. Reino Unido \n\t 3. Imperio japones \n\t 4. Union sovietica \n\t 5. Alemania \n\t 6. Italia"<<endl;
	    cin>> cate2;
	    if(cate2 == 1){
	        bando="Estados unidos";
	        if(cate == 1)
	        	inventario= "Fusil semiautomatico M1 Garand 7.62 x63 mm |";
	        else
	        	inventario= "Tanque M4 sherman |";
			
			}
	    else
	        if(cate2 == 2){
	            bando= "Reino unido";
	            if (cate==1)
	            	inventario ="Subfusil Sten calibre 9 x 19 mm |";
	            else
	            	inventario="Tanque Churchill Mk I |";
	        }
	        else
	            if(cate2 == 3) {
	                	bando="Japon";
	                	if(cate == 1)
						
	                		inventario = "Rifle de cerrojo Arisaka Tipo 30 |";
	                	else
	                		inventario = "Tanque  Tipo 97 Chi-Ha |";
					}
	            else
	                if(cate2 == 4){
	                	bando = "Union sovietica";
	                	if(cate == 1)
	                		inventario="Sub ametralladora kalashnikov 1942 (AK42) |";
	                	else
	                		inventario ="Tanque KV-1 |";
					}       
	                else
	                    if(cate2 == 5){
	                    	bando="Alemania";
	                    	if(cate==1)
							
	                    		inventario="Fusil de asalto MP44 calibre 7,92 x calibre 7,92 x 33 mm Kurz |";
	           				else
							   
							   inventario="Tanque Panzer IV |";  
	
						
						}
	                        
	                    else
	                        if(cate2 == 6){
	                        	 bando="Italia";
	                        	 if(cate==1)
	                        	 	inventario="Subfusil Beretta MAB 38 calibre 9 x 19 mm parabellum |";
	                        	else
	                        	inventario="Tanque M15/42 |";
							}
	                           
	    p= new Personaje(nombre,clase,bando,historial_misiones,inventario,nivel,experiencia);
		lista.add(*p);
	}
	else {
		cout<<"El nombre del soldado ya se encuntra enlistado en las fuerzas armadas, intente de nuevo"<<endl;
	}

    system("pause");
}
void acceder(FileList& lista){
	Personaje *p;
    string nombre_a;
    string aux_nombre;
    int opc;
    int opc2;
    int aux_experiencia;
    int cont;
    int residuo;
   cout<<"Acceder a una cuenta"<<endl;
   cout<<"ingrese el nombre del personaje al cuan desea ingresar"<<endl;
   fflush(stdin);
   getline(cin,nombre_a);

   if(lista.find_nombre(nombre_a)== true){
		p =lista.find(nombre_a);
		do
		{
		   system("cls");
		   cout<<"1. Modificar Atributos"<<endl;
		   cout<<"2. Ver"<<endl;
		   cout<<"3. Realizar mision"<<endl;
		   cout<<"4. Abandonar"<<endl;
		   cout<<"Ingrese opcion"<<endl;
		   cin>>opc;
		   switch (opc){
		        case 1:
		            system("cls");
		            cout<<"Modificar atribtos "<<endl;
		            cout<<"1. Nombre"<<endl;
		            cout<<"2. Experiencia"<<endl;
		            cout<<"Ingrese opcion"<<endl;
		            cin>>opc;
		           	if(opc == 1){
		           		fflush(stdin);
		           		cout<<"Ingrese nuevamente el nombre de su soldado"<<endl;
		           		getline(cin,aux_nombre);
		           		fflush(stdin);
		           		if(lista.find_nombre(aux_nombre)== false){
		           			p->set_nombre(aux_nombre);
					   		}
					   }
					   if(opc == 2){
					   	cout<<"La experiencia se clasifica del 0 a el numero 10 (una vez llegado al 10 se reinicia y se agrega un nivel"<<endl;
					   	cin>>aux_experiencia;
					   	if(aux_experiencia >=0)
					   		cont=aux_experiencia/10; 	//resulado de la divicon
					   		residuo=aux_experiencia % 10;//residuo que se modifica en aux experiencia
					   		if(cont>0){
					   			p->set_nivel(cont);
					   			p->set_experiencia(residuo);
					   		}
					   		else
					   			p->set_experiencia(aux_experiencia);	
					   }
		            break;
		        case 2:
		        	system("cls");
		            cout<<"Ver"<<endl;
		            cout<<"1. Personaje"<<endl;
		            cout<<"2. Inventario"<<endl;
		            cout<<"3. Historial de misiones"<<endl;
		            cout<<"Ingrese opcion"<<endl;
		            cin>>opc2;
		            switch(opc2){
		            	case 1:
		            		cout<<p->toString()<<endl;
		            		break;
		            	case 2:
		            		cout<<"\tModificar inventario"<<endl;
		            		cout<<"objetos "<<endl;
		            		p->mod_inventario();
							break;
		            	case 3:
		            		cout<<p->imprime_historial()<<endl;
		            		break;
					}
		            break;
		        case 3:
		            p->mision();
		            break;
		   }
		    system("pause");
		}while(opc!=4);
	   
	   
	  lista.remove(nombre_a);
	  lista.add(*p);
	}
   
}
void eliminar(FileList& lista){
	string cadena;
	 fflush(stdin);
    cout<<"eliminar"<<endl;
    cout<<"Ingres nombre del usuario que desea eliminar"<<endl;
    getline(cin,cadena);
    fflush(stdin);
    lista.remove(cadena);
    cout<<"El soldad fue dado de baja de las filas"<<endl;
    
    system("pause");
}

